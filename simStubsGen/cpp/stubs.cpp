#py from parse import parse, escape
#py import model
#py plugin = parse(pycpp.params['xml_file'])
#include "stubs.h"
#include <simPlusPlus/Lib.h>
#include <simStubsGen/cpp/common.h>

#include <optional>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <boost/lexical_cast.hpp>

FuncTracer::FuncTracer(const std::string &f, int l)
    : f_(f),
      l_(l)
{
    sim::addLog(l_, f_ + " [enter]");
}

FuncTracer::~FuncTracer()
{
    sim::addLog(l_, f_ + " [leave]");
}

#ifndef NDEBUG

template<typename... Arguments>
void addStubsDebugLog(const std::string &fmt, Arguments&&... args)
{
    if(sim::isStackDebugEnabled())
    {
        auto msg = sim::util::sprintf(fmt, std::forward<Arguments>(args)...);
        sim::addLog(sim_verbosity_debug, "STUBS DEBUG: %s", msg);
    }
}

static void addStubsDebugStackDump(int stackHandle)
{
    if(sim::isStackDebugEnabled())
        sim::debugStack(stackHandle);
}

#else // RELEASE
#define addStubsDebugLog(...)
#define addStubsDebugStackDump(x)
#endif

#ifdef QT_COMPIL

Qt::HANDLE UI_THREAD = NULL;
Qt::HANDLE SIM_THREAD = NULL;

std::string threadNickname()
{
    Qt::HANDLE h = QThread::currentThreadId();
    if(h == UI_THREAD) return "UI";
    if(h == SIM_THREAD) return "SIM";
    std::stringstream ss;
    ss << h;
    return ss.str();
}

void uiThread()
{
    Qt::HANDLE h = QThread::currentThreadId();
    if(UI_THREAD != NULL && UI_THREAD != h)
        sim::addLog(sim_verbosity_warnings, "UI thread has already been set");
    UI_THREAD = h;
}

void simThread()
{
    Qt::HANDLE h = QThread::currentThreadId();
    if(SIM_THREAD != NULL && SIM_THREAD != h)
        sim::addLog(sim_verbosity_warnings, "SIM thread has already been set");
    SIM_THREAD = h;
}

#endif // QT_COMPIL

#py for struct in plugin.structs:
void readFromStack(int stack, `struct.name` *value, const ReadOptions &rdopt)
{
    addStubsDebugLog("readFromStack(`struct.name`): begin reading...");
    addStubsDebugStackDump(stack);

    try
    {
        int info = sim::getStackTableInfo(stack, 0);
        if(info != sim_stack_table_map && info != sim_stack_table_empty)
        {
            throw sim::exception("expected a map");
        }

        int oldsz = sim::getStackSize(stack);
        sim::unfoldStackTable(stack);
        int numItems = (sim::getStackSize(stack) - oldsz + 1) / 2;

        std::set<std::string> requiredFields{`', '.join(f'"{field.name}"' for field in struct.fields if not field.nullable and field.mandatory())`};

        while(numItems >= 1)
        {
            sim::moveStackItemToTop(stack, oldsz - 1); // move key to top
            std::string key;
            readFromStack(stack, &key);

            sim::moveStackItemToTop(stack, oldsz - 1); // move value to top
            if(0) {}
#py for field in struct.fields:
            else if(key == "`field.name`")
            {
                addStubsDebugLog("readFromStack(`struct.name`): reading field \"`field.name`\" (`field.ctype()`)...");
                try
                {
#py if isinstance(field, (model.ParamTable, model.ParamGrid)):
                    readFromStack(stack, &(value->`field.name`), ReadOptions().setBounds("`field.size`"));
#py else:
                    readFromStack(stack, &(value->`field.name`));
#py endif
                }
                catch(std::exception &ex)
                {
                    throw sim::exception("field '`field.name`': %s", ex.what());
                }
            }
#py endfor
            else
            {
                throw sim::exception("unexpected key: %s", key);
            }

            requiredFields.erase(key);
            numItems = (sim::getStackSize(stack) - oldsz + 1) / 2;
        }

        for(const auto &field : requiredFields)
            throw sim::exception("missing required field '%s'", field);
    }
    catch(std::exception &ex)
    {
        throw sim::exception("readFromStack(`struct.name`): %s", ex.what());
    }

    addStubsDebugLog("readFromStack(`struct.name`): finished reading");
}

void writeToStack(const `struct.name` &value, int stack, const WriteOptions &wropt)
{
    addStubsDebugLog("writeToStack(`struct.name`): begin writing...");

    try
    {
        sim::pushTableOntoStack(stack);

#py for field in struct.fields:
        addStubsDebugLog("writeToStack(`struct.name`): writing field \"`field.name`\" (`field.ctype()`)...");
        try
        {
            writeToStack(std::string{"`field.name`"}, stack);
            writeToStack(value.`field.name`, stack);
            sim::insertDataIntoStackTable(stack);
        }
        catch(std::exception &ex)
        {
            throw sim::exception("field '`field.name`': %s", ex.what());
        }
#py endfor
    }
    catch(std::exception &ex)
    {
        throw sim::exception("writeToStack(`struct.name`): %s", ex.what());
    }

    addStubsDebugLog("writeToStack(`struct.name`): finished writing");
}

`struct.name`::`struct.name`()
{
#py for field in struct.fields:
#py if field.default:
    `field.name` = `field.cdefault()`;
#py endif
#py endfor
}

#py endfor
void checkRuntimeVersion()
{
    int simVer = sim::programVersion();

    // version required by simStubsGen:
    int minVer = 4050107; // 4.5.1rev7
    if(simVer < minVer)
        throw sim::exception("requires at least %s (simStubsGen)", sim::versionString(minVer));

    // version required by plugin:
    if(simVer < SIM_REQUIRED_PROGRAM_VERSION_NB)
        throw sim::exception("requires at least %s", sim::versionString(SIM_REQUIRED_PROGRAM_VERSION_NB));

    // warn if the app older than the headers used to compile:
    if(simVer < SIM_PROGRAM_FULL_VERSION_NB)
        sim::addLog(sim_verbosity_warnings, "has been built for %s", sim::versionString(SIM_PROGRAM_FULL_VERSION_NB));
}

bool registerScriptStuff()
{
    try
    {
        checkRuntimeVersion();

        auto dbg = sim::getNamedBoolParam("simStubsGen.debug");
        if(dbg && *dbg)
            sim::enableStackDebug();

        try
        {
            // register varables from enums:
#py for enum in plugin.enums:
#if SIM_PROGRAM_FULL_VERSION_NB < 4060010
            sim::registerScriptVariableRaw("`enum.name`", "{}", 0);
#endif
#py for item in enum.items:
            sim::registerScriptVariable("`enum.name`.`item.name`", `plugin.name.lower()`_`enum.item_prefix``item.name`, 0);
#py endfor
#py endfor
            // register commands:
#py for cmd in plugin.commands:
            sim::registerScriptCallbackFunction("`cmd.name`", `cmd.c_name`_callback);
#py endfor
        }
        catch(std::exception &ex)
        {
            throw sim::exception("Initialization failed (registerScriptItems): %s", ex.what());
        }
    }
    catch(sim::exception& ex)
    {
        sim::addLog(sim_verbosity_errors, ex.what());
        return false;
    }
    return true;
}

#py for enum in plugin.enums:
const char* `enum.name.lower()`_string(`enum.name` x)
{
    switch(x)
    {
#py for item in enum.items:
        case `plugin.name.lower()`_`enum.item_prefix``item.name`: return "`plugin.name.lower()`_`enum.item_prefix``item.name`";
#py endfor
        default: return "???";
    }
}

#py endfor
#py for cmd in plugin.commands:
`cmd.c_in_name`::`cmd.c_in_name`()
{
#py for p in cmd.params:
#py if p.cdefault() is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

`cmd.c_out_name`::`cmd.c_out_name`()
{
#py for p in cmd.returns:
#py if p.cdefault() is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

void `cmd.c_name`_callback(SScriptCallBack *p)
{
    addStubsDebugLog("`cmd.c_name`_callback: reading input arguments...");
    addStubsDebugStackDump(p->stackID);

    const char *cmd = "`plugin.name`.`cmd.name`";

    `cmd.c_in_name` in_args;
    if(p)
    {
        std::memcpy(&in_args._, p, sizeof(SScriptCallBack));
    }
    `cmd.c_out_name` out_args;

    try
    {
        // check argument count

        int numArgs = sim::getStackSize(p->stackID);
        if(numArgs < `cmd.params_min`)
            throw sim::exception("not enough arguments");
        if(numArgs > `cmd.params_max`)
            throw sim::exception("too many arguments");

        // read input arguments from stack

#py for i, p in enumerate(cmd.params):
        if(numArgs >= `i+1`)
        {
            addStubsDebugLog("`cmd.c_name`_callback: reading input argument `i+1` \"`p.name`\" (`p.ctype()`)...");
            try
            {
                sim::moveStackItemToTop(p->stackID, 0);
#py if isinstance(p, (model.ParamTable, model.ParamGrid)):
                readFromStack(p->stackID, &(in_args.`p.name`), ReadOptions().setBounds("`p.size`"));
#py else:
                readFromStack(p->stackID, &(in_args.`p.name`));
#py endif
            }
            catch(std::exception &ex)
            {
                throw sim::exception("read in arg `i+1` (`p.name`): %s", ex.what());
            }
        }

#py endfor

        addStubsDebugLog("`cmd.c_name`_callback: stack content after reading input arguments:");
        addStubsDebugStackDump(p->stackID);

#py if cmd.clear_stack_after_reading_input:
        addStubsDebugLog("`cmd.c_name`_callback: clearing stack content after reading input arguments");
        // clear stack
        sim::popStackItem(p->stackID, 0);

#py endif

        addStubsDebugLog("`cmd.c_name`_callback: calling callback (`cmd.c_name`)");
        `plugin.name`_`cmd.c_name`(&in_args, &out_args);
    }
    catch(std::exception &ex)
    {
        sim::setLastError(ex.what());
    }

    try
    {
        addStubsDebugLog("`cmd.c_name`_callback: writing output arguments...");
        addStubsDebugStackDump(p->stackID);

#py if cmd.clear_stack_before_writing_output:
        addStubsDebugLog("`cmd.c_name`_callback: clearing stack content before writing output arguments");
        // clear stack
        sim::popStackItem(p->stackID, 0);

#py endif

        // write output arguments to stack

#py for i, p in enumerate(cmd.returns):
        addStubsDebugLog("`cmd.c_name`_callback: writing output argument `i+1` \"`p.name`\" (`p.ctype()`)...");
        try
        {
            writeToStack(out_args.`p.name`, p->stackID);
        }
        catch(std::exception &ex)
        {
            throw sim::exception("write out arg `i+1` (`p.name`): %s", ex.what());
        }
#py endfor

        addStubsDebugLog("`cmd.c_name`_callback: stack content after writing output arguments:");
        addStubsDebugStackDump(p->stackID);
    }
    catch(std::exception &ex)
    {
        sim::setLastError(ex.what());
        // clear stack
        try { sim::popStackItem(p->stackID, 0); } catch(...) {}
    }

    addStubsDebugLog("`cmd.c_name`_callback: finished");
}

#py endfor
#py for fn in plugin.script_functions:
`fn.c_in_name`::`fn.c_in_name`()
{
#py for p in fn.params:
#py if p.default is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

`fn.c_out_name`::`fn.c_out_name`()
{
#py for p in fn.returns:
#py if p.default is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

bool `fn.c_name`(int scriptId, const char *func, `fn.c_in_name` *in_args, `fn.c_out_name` *out_args)
{
    addStubsDebugLog("`fn.c_name`: writing input arguments...");

    int stackID = -1;

    try
    {
        stackID = sim::createStack();

        // write input arguments to stack

#py for i, p in enumerate(fn.params):
        addStubsDebugLog("`fn.c_name`: writing input argument `i+1` \"`p.name`\" (`p.ctype()`)...");
        try
        {
            writeToStack(in_args->`p.name`, stackID);
        }
        catch(std::exception &ex)
        {
            throw sim::exception("writing input argument `i+1` (`p.name`): %s", ex.what());
        }
#py endfor

        addStubsDebugLog("`fn.c_name`: wrote input arguments:");
        addStubsDebugStackDump(stackID);

        sim::callScriptFunctionEx(scriptId, func, stackID);

        // read output arguments from stack

        addStubsDebugLog("`fn.c_name`: reading output arguments...");

#py for i, p in enumerate(fn.returns):
        addStubsDebugLog("`fn.c_name`: reading output argument `i+1` \"`p.name`\" (`p.ctype()`)...");
        try
        {
            sim::moveStackItemToTop(stackID, 0);
#py if isinstance(p, (model.ParamTable, model.ParamGrid)):
            readFromStack(stackID, &(out_args->`p.name`), ReadOptions().setBounds("`p.size`"));
#py else:
            readFromStack(stackID, &(out_args->`p.name`));
#py endif
        }
        catch(std::exception &ex)
        {
            throw sim::exception("read out arg `i+1` (`p.name`): %s", ex.what());
        }
#py endfor

        addStubsDebugLog("`fn.c_name`: stack content after reading output arguments:");
        addStubsDebugStackDump(stackID);

        sim::releaseStack(stackID);
        stackID = -1;
    }
    catch(std::exception &ex)
    {
        if(stackID != -1)
            try { sim::releaseStack(stackID); } catch(...) {}
        sim::setLastError(ex.what());
        return false;
    }

    addStubsDebugLog("`fn.c_name`: finished");

    return true;
}

#py endfor
