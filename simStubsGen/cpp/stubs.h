#py from parse import parse
#py import model
#py plugin = parse(pycpp.params['xml_file'])
#ifndef STUBS_H__INCLUDED
#define STUBS_H__INCLUDED

#py if plugin.needs_eigen():
#define SIM_STUBS_GEN_EIGEN
#py endif
#include <simLib/simExp.h>
#include <simPlusPlus/Lib.h>
#include <simStubsGen/cpp/common.h>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/format.hpp>

class FuncTracer
{
    int l_;
    std::string f_;
public:
    FuncTracer(const std::string &f, int l = sim_verbosity_trace);
    ~FuncTracer();
};

#ifndef __FUNC__
#ifdef __PRETTY_FUNCTION__
#define __FUNC__ __PRETTY_FUNCTION__
#else
#define __FUNC__ __func__
#endif
#endif // __FUNC__

#define TRACE_FUNC FuncTracer __funcTracer__##__LINE__((boost::format("%s:%d:%s:") % __FILE__ % __LINE__ % __FUNC__).str())

#ifdef QT_COMPIL
#include <QThread>

extern Qt::HANDLE UI_THREAD;
extern Qt::HANDLE SIM_THREAD;

std::string threadNickname();
void uiThread();
void simThread();

#define ASSERT_THREAD(ID) \
    if(UI_THREAD == NULL) {\
        sim::addLog(sim_verbosity_debug, "warning: cannot check ASSERT_THREAD(" #ID ") because global variable UI_THREAD is not set yet.");\
    } else if(strcmp(#ID, "UI") == 0) {\
        if(QThread::currentThreadId() != UI_THREAD) {\
            sim::addLog(sim_verbosity_errors, "%s:%d %s should be called from UI thread", __FILE__, __LINE__, __FUNC__);\
            exit(1);\
        }\
    } else if(strcmp(#ID, "!UI") == 0) {\
        if(QThread::currentThreadId() == UI_THREAD) {\
            sim::addLog(sim_verbosity_errors, "%s:%d %s should NOT be called from UI thread", __FILE__, __LINE__, __FUNC__);\
            exit(1);\
        }\
    } else {\
        sim::addLog(sim_verbosity_debug, "warning: cannot check ASSERT_THREAD(" #ID "). Can check only UI and !UI.");\
    }
#endif // QT_COMPIL

#py for struct in plugin.structs:
struct `struct.name`
{
#py for field in struct.fields:
    `field.ctype()` `field.name`;
#py endfor

    `struct.name`();
    `struct.name`(`', '.join(f'const {f.ctype()} &{f.name}_' for f in struct.fields)`) : `', '.join(f'{f.name}({f.name}_)' for f in struct.fields)` {}
};

void readFromStack(int stack, `struct.name` *value, const ReadOptions &rdopt = {});
void writeToStack(const `struct.name` &value, int stack, const WriteOptions &wropt = {});
#py endfor

bool registerScriptStuff();

#py for enum in plugin.enums:
enum `enum.name`
{
#py for i, item in enumerate(enum.items):
    `plugin.name.lower()`_`enum.item_prefix``item.name` = `item.value`,
#py endfor
};

const char* `enum.name.lower()`_string(`enum.name` x);

#py endfor
#py for cmd in plugin.commands:
struct `cmd.c_in_name`
{
    SScriptCallBack _;
#py for p in cmd.params:
    `p.ctype()` `p.name`;
#py endfor

    `cmd.c_in_name`();
};

struct `cmd.c_out_name`
{
#py for p in cmd.returns:
    `p.ctype()` `p.name`;
#py endfor

    `cmd.c_out_name`();
};

void `cmd.c_name`_callback(SScriptCallBack *p);
SIM_DLLEXPORT void `plugin.name`_`cmd.c_name`(`cmd.c_in_name` *in, `cmd.c_out_name` *out);

#py endfor
#py for fn in plugin.script_functions:
struct `fn.c_in_name`
{
#py for p in fn.params:
    `p.ctype()` `p.name`;
#py endfor

    `fn.c_in_name`();
};

struct `fn.c_out_name`
{
#py for p in fn.returns:
    `p.ctype()` `p.name`;
#py endfor

    `fn.c_out_name`();
};

#py if len(fn.returns) == 1:
`fn.returns[0].ctype()` `fn.c_name`(`fn.c_arg_list(pre_args=['int scriptId', 'const char *func'], defaults=True)`);
#py endif
#py if len(fn.returns) == 0:
void `fn.c_name`(`fn.c_arg_list(pre_args=['int scriptId', 'const char *func'], defaults=True)`);
#py endif
bool `fn.c_name`(int scriptId, const char *func, `fn.c_in_name` *in_args, `fn.c_out_name` *out_args);

#py endfor
// following functions must be implemented in the plugin

#py for cmd in plugin.commands:
void `cmd.c_name`(SScriptCallBack *p, const char *cmd, `cmd.c_in_name` *in, `cmd.c_out_name` *out);
#py endfor

#endif // STUBS_H__INCLUDED
