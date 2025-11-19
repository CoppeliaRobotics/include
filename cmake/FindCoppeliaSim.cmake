cmake_minimum_required(VERSION 3.16.3)
include(CMakeParseArguments)

if(POLICY CMP0177)
    cmake_policy(SET CMP0177 NEW) # normalize DESTINATION paths
endif()

if(CMAKE_CXX_STANDARD)
    if(CMAKE_CXX_STANDARD LESS 17)
        message(FATAL_ERROR "Set CMAKE_CXX_STANDARD to 17 or greater (or remove it)")
    endif()
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

# fix CMAKE_MODULE_PATH to have forward slashes:
file(TO_CMAKE_PATH "${CMAKE_MODULE_PATH}" CMAKE_MODULE_PATH)

function(COPPELIASIM_FIND_ERROR MESSAGE)
    if(CoppeliaSim_FIND_REQUIRED)
        message(FATAL_ERROR ${MESSAGE})
    elseif(NOT CoppeliaSim_FIND_QUIETLY)
        message(SEND_ERROR ${MESSAGE})
    endif()
endfunction()

# redefine COPPELIASIM_INCLUDE_DIR as the directory containing this module:

get_filename_component(COPPELIASIM_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
if(NOT CoppeliaSim_FIND_QUIETLY)
    message(STATUS "CoppeliaSim: COPPELIASIM_INCLUDE_DIR: ${COPPELIASIM_INCLUDE_DIR}")
endif()

# determine the value of COPPELIASIM_ROOT_DIR:

if(NOT COPPELIASIM_ROOT_DIR)
    if(NOT DEFINED ENV{COPPELIASIM_ROOT_DIR})
        get_filename_component(COPPELIASIM_PROGRAMMING_DIR ${COPPELIASIM_INCLUDE_DIR} DIRECTORY)
        get_filename_component(COPPELIASIM_ROOT_DIR ${COPPELIASIM_PROGRAMMING_DIR} DIRECTORY)
        unset(COPPELIASIM_PROGRAMMING_DIR)
    else()
        set(COPPELIASIM_ROOT_DIR "$ENV{COPPELIASIM_ROOT_DIR}")
    endif()
endif()

# check if COPPELIASIM_ROOT_DIR exists, is valid, etc...:

set(COPPELIASIM_FOUND FALSE)

if(EXISTS "${COPPELIASIM_ROOT_DIR}")
    file(TO_CMAKE_PATH "${COPPELIASIM_ROOT_DIR}" COPPELIASIM_ROOT_DIR)
    if(NOT CoppeliaSim_FIND_QUIETLY)
        message(STATUS "CoppeliaSim: COPPELIASIM_ROOT_DIR: ${COPPELIASIM_ROOT_DIR}")
    endif()
else()
    coppeliasim_find_error("The specified COPPELIASIM_ROOT_DIR (${COPPELIASIM_ROOT_DIR}) does not exist")
    return()
endif()

function(check_simLib_version simLib_dir version)
    if(NOT CoppeliaSim_FIND_QUIETLY)
        message(STATUS "Checking CoppeliaSim header version (using ${simLib_dir})...")
    endif()
    set(COPPELIASIM_VERSION_CHECK_SRC "${CMAKE_BINARY_DIR}/sim_version_check.cpp")
    set(COPPELIASIM_VERSION_CHECK_BIN "${CMAKE_BINARY_DIR}/sim_version_check")
    file(WRITE ${COPPELIASIM_VERSION_CHECK_SRC} "
#include <iostream>
#include <${simLib_dir}/simConst.h>
int main() {
    char sep = ';';
    std::cout
        << SIM_PROGRAM_VERSION_NB/10000 << sep
        << SIM_PROGRAM_VERSION_NB/100%100 << sep
        << SIM_PROGRAM_VERSION_NB%100 << sep
        << SIM_PROGRAM_REVISION_NB << sep
        << 0 << std::endl;
}
")
    try_run(COPPELIASIM_VERSION_RUN_RESULT COPPELIASIM_VERSION_COMPILE_RESULT ${COPPELIASIM_VERSION_CHECK_BIN} ${COPPELIASIM_VERSION_CHECK_SRC} CMAKE_FLAGS -DINCLUDE_DIRECTORIES=${COPPELIASIM_INCLUDE_DIR} RUN_OUTPUT_VARIABLE COPPELIASIM_VERSION_CHECK_OUTPUT COMPILE_OUTPUT_VARIABLE COPPELIASIM_VERSION_CHECK_COMPILE_OUTPUT)
    if(${COPPELIASIM_VERSION_COMPILE_RESULT})
        if(${COPPELIASIM_VERSION_RUN_RESULT} EQUAL 0)
            list(GET COPPELIASIM_VERSION_CHECK_OUTPUT 0 COPPELIASIM_VERSION_MAJOR)
            list(GET COPPELIASIM_VERSION_CHECK_OUTPUT 1 COPPELIASIM_VERSION_MINOR)
            list(GET COPPELIASIM_VERSION_CHECK_OUTPUT 2 COPPELIASIM_VERSION_PATCH)
            list(GET COPPELIASIM_VERSION_CHECK_OUTPUT 3 COPPELIASIM_VERSION_TWEAK)
            set(COPPELIASIM_VERSION_COUNT 4)
            list(GET COPPELIASIM_VERSION_CHECK_OUTPUT 3 COPPELIASIM_REVISION)
            set(COPPELIASIM_VERSION "${COPPELIASIM_VERSION_MAJOR}.${COPPELIASIM_VERSION_MINOR}.${COPPELIASIM_VERSION_PATCH}.${COPPELIASIM_REVISION}")
            set(COPPELIASIM_VERSION_STR "${COPPELIASIM_VERSION_MAJOR}.${COPPELIASIM_VERSION_MINOR}.${COPPELIASIM_VERSION_PATCH} rev${COPPELIASIM_REVISION}")
            if(NOT CoppeliaSim_FIND_QUIETLY)
                message(STATUS "CoppeliaSim headers version ${COPPELIASIM_VERSION_STR}")
            endif()
            math(EXPR CoppeliaSim_FIND_VERSION_NB "1000000 * ${CoppeliaSim_FIND_VERSION_MAJOR} + 10000 * ${CoppeliaSim_FIND_VERSION_MINOR} + 100 * ${CoppeliaSim_FIND_VERSION_PATCH} + ${CoppeliaSim_FIND_VERSION_TWEAK}")
            add_compile_definitions(SIM_REQUIRED_PROGRAM_VERSION_NB=${CoppeliaSim_FIND_VERSION_NB})
            if(${COPPELIASIM_VERSION} VERSION_LESS ${version})
                coppeliasim_find_error("Found CoppeliaSim version ${COPPELIASIM_VERSION} but ${version} required.")
                return()
            endif()
        else()
            coppeliasim_find_error("Failed to run CoppeliaSim version check program")
            return()
        endif()
    else()
        message(STATUS "${COPPELIASIM_VERSION_CHECK_COMPILE_OUTPUT}")
        coppeliasim_find_error("Failed to compile CoppeliaSim version check program")
        return()
    endif()
endfunction()

#if(NOT CoppeliaSim_FIND_COMPONENTS)
#    set(CoppeliaSim_FIND_COMPONENTS simLib)
#endif()
foreach(comp IN LISTS CoppeliaSim_FIND_COMPONENTS)
    if(comp STREQUAL "simLib")
        message(WARNING "Component name 'simLib' is deprecated. Please use 'simLib-1'.")
        set(comp "simLib-1")
    elseif(comp STREQUAL "simLib-scriptFunctionData")
        message(WARNING "Component name 'simLib-scriptFunctionData' is deprecated. Please use 'simLib-scriptFunctionData-1'.")
        set(comp "simLib-scriptFunctionData-1")
    elseif(comp STREQUAL "simLib-socket")
        message(WARNING "Component name 'simLib-socket' is deprecated. Please use 'simLib-socket-1'.")
        set(comp "simLib-socket-1")
    elseif(comp STREQUAL "simMath")
        message(WARNING "Component name 'simMath' is deprecated. Please use 'simMath-1'.")
        set(comp "simMath-1")
    elseif(comp STREQUAL "simStack")
        message(WARNING "Component name 'simStack' is deprecated. Please use 'simStack-1'.")
        set(comp "simStack-1")
    elseif(comp STREQUAL "simPlusPlus")
        message(WARNING "Component name 'simPlusPlus' is deprecated. Please use 'simPlusPlus-1'.")
        set(comp "simPlusPlus-1")
    endif()
    if(comp STREQUAL "none")
        # dummy component
    elseif(comp STREQUAL "simLib-1")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES "${COPPELIASIM_INCLUDE_DIR}/simLib/simLib.cpp")
        if(DEFINED CoppeliaSim_FIND_VERSION)
            check_simLib_version("simLib" ${CoppeliaSim_FIND_VERSION})
        endif()
        set(CoppeliaSim_simLib-1_FOUND TRUE)
    elseif(comp STREQUAL "simLib-2")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES "${COPPELIASIM_INCLUDE_DIR}/simLib-2/simLib.cpp")
        if(DEFINED CoppeliaSim_FIND_VERSION)
            check_simLib_version("simLib-2" ${CoppeliaSim_FIND_VERSION})
        endif()
        set(CoppeliaSim_simLib-2_FOUND TRUE)
    elseif(comp STREQUAL "simLib-scriptFunctionData-1")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES
            ${COPPELIASIM_INCLUDE_DIR}/simLib/scriptFunctionData.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simLib/scriptFunctionDataItem.cpp
        )
        set(CoppeliaSim_simLib-scriptFunctionData-1_FOUND TRUE)
    elseif(comp STREQUAL "simLib-scriptFunctionData-2")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES
            ${COPPELIASIM_INCLUDE_DIR}/simLib-2/scriptFunctionData.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simLib-2/scriptFunctionDataItem.cpp
        )
        set(CoppeliaSim_simLib-scriptFunctionData-1_FOUND TRUE)
    elseif(comp STREQUAL "simLib-socket-1")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES
            ${COPPELIASIM_INCLUDE_DIR}/simLib/socketInConnection.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simLib/socketOutConnection.cpp
        )
        set(CoppeliaSim_simLib-socket-1_FOUND TRUE)
    elseif(comp STREQUAL "simLib-socket-2")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES
            ${COPPELIASIM_INCLUDE_DIR}/simLib-2/socketInConnection.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simLib-2/socketOutConnection.cpp
        )
        set(CoppeliaSim_simLib-socket-2_FOUND TRUE)
    elseif(comp STREQUAL "simMath-1")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES
            ${COPPELIASIM_INCLUDE_DIR}/simMath/mathFuncs.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simMath/3Vector.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simMath/4Vector.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simMath/7Vector.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simMath/3X3Matrix.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simMath/4X4Matrix.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simMath/mXnMatrix.cpp
        )
        set(CoppeliaSim_simMath-1_FOUND TRUE)
    elseif(comp STREQUAL "simStack-1")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES
            ${COPPELIASIM_INCLUDE_DIR}/simStack/stackArray.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simStack/stackBool.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simStack/stackMap.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simStack/stackNull.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simStack/stackNumber.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simStack/stackObject.cpp
            ${COPPELIASIM_INCLUDE_DIR}/simStack/stackString.cpp
        )
        set(CoppeliaSim_simLib-scriptFunctionData-1_FOUND TRUE)
    elseif(comp STREQUAL "simPlusPlus-1")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES "${COPPELIASIM_INCLUDE_DIR}/simPlusPlus/Lib.cpp")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES "${COPPELIASIM_INCLUDE_DIR}/simPlusPlus/Plugin.cpp")
        set(CoppeliaSim_simPlusPlus-1_FOUND TRUE)
    elseif(comp STREQUAL "simPlusPlus-2")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES "${COPPELIASIM_INCLUDE_DIR}/simPlusPlus-2/Lib.cpp")
        list(APPEND COPPELIASIM_EXPORTED_SOURCES "${COPPELIASIM_INCLUDE_DIR}/simPlusPlus-2/Plugin.cpp")
        set(CoppeliaSim_simPlusPlus-2_FOUND TRUE)
    else()
        message(FATAL_ERROR "Unknown CoppeliaSim component: ${comp}")
    endif()
endforeach()

if(DEFINED COPPELIASIM_SIMLIB_VERSIONS)
    message(FATAL_ERROR "Setting COPPELIASIM_SIMLIB_VERSIONS is not supported anymore. Please use COMPONENTS argument of find_package(), e.g. find_package(CoppeliaSim COMPONENTS simLib-2)")
endif()

foreach(DIR IN LISTS COPPELIASIM_CHECK_MODULE_DIRS)
    if(NOT IS_DIRECTORY "${DIR}")
        coppeliasim_find_error("Directory ${DIR} does not exist.")
        return()
    endif()
endforeach()

if(WIN32)
    add_compile_definitions(WIN_SIM)
    add_compile_definitions(NOMINMAX)
    add_compile_definitions(strcasecmp=_stricmp)
    if((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))
        add_compile_options("/Zc:__cplusplus")
    endif()
    add_compile_definitions(_USE_MATH_DEFINES)
    set(COPPELIASIM_LIBRARIES shlwapi)
    set(COPPELIASIM_RESOURCES_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_PLUGINS_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_EXECUTABLES_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_ADDONS_DIR ${COPPELIASIM_RESOURCES_DIR}/addOns)
    set(COPPELIASIM_LIBRARIES_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_MANUAL_DIR ${COPPELIASIM_RESOURCES_DIR}/manual)
    set(COPPELIASIM_MODELS_DIR ${COPPELIASIM_RESOURCES_DIR}/models)
    set(COPPELIASIM_SCENES_DIR ${COPPELIASIM_RESOURCES_DIR}/scenes)
    set(COPPELIASIM_EXECUTABLE ${COPPELIASIM_EXECUTABLES_DIR}/coppeliaSim.exe)
elseif(UNIX AND NOT APPLE)
    add_compile_definitions(LIN_SIM)
    set(COPPELIASIM_LIBRARIES "")
    set(COPPELIASIM_RESOURCES_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_PLUGINS_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_EXECUTABLES_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_ADDONS_DIR ${COPPELIASIM_RESOURCES_DIR}/addOns)
    set(COPPELIASIM_LIBRARIES_DIR ${COPPELIASIM_ROOT_DIR})
    set(COPPELIASIM_MANUAL_DIR ${COPPELIASIM_RESOURCES_DIR}/manual)
    set(COPPELIASIM_MODELS_DIR ${COPPELIASIM_RESOURCES_DIR}/models)
    set(COPPELIASIM_SCENES_DIR ${COPPELIASIM_RESOURCES_DIR}/scenes)
    set(COPPELIASIM_EXECUTABLE ${COPPELIASIM_EXECUTABLES_DIR}/coppeliaSim)
elseif(UNIX AND APPLE)
    add_compile_definitions(MAC_SIM)
    set(COPPELIASIM_LIBRARIES "")
    set(PLUGINS_NEW_PLACE OFF) # enable later...
    if(EXISTS ${COPPELIASIM_ROOT_DIR}/coppeliaSim.app OR COPPELIASIM_ROOT_DIR STREQUAL .)
        set(COPPELIASIM_RESOURCES_DIR ${COPPELIASIM_ROOT_DIR}/coppeliaSim.app/Contents/Resources)
        if(PLUGINS_NEW_PLACE)
            set(COPPELIASIM_PLUGINS_DIR ${COPPELIASIM_ROOT_DIR}/coppeliaSim.app/Contents/PlugIns/coppeliaSim)
        else()
            set(COPPELIASIM_PLUGINS_DIR ${COPPELIASIM_ROOT_DIR}/coppeliaSim.app/Contents/MacOS)
        endif()
        set(COPPELIASIM_EXECUTABLES_DIR ${COPPELIASIM_ROOT_DIR}/coppeliaSim.app/Contents/MacOS)
        set(COPPELIASIM_LIBRARIES_DIR ${COPPELIASIM_ROOT_DIR}/coppeliaSim.app/Contents/Frameworks)
    elseif(EXISTS ${COPPELIASIM_ROOT_DIR}/../../Contents/MacOS)
        get_filename_component(COPPELIASIM_RESOURCES_DIR ${COPPELIASIM_ROOT_DIR}/../../Contents/Resources ABSOLUTE)
        if(PLUGINS_NEW_PLACE)
            get_filename_component(COPPELIASIM_PLUGINS_DIR ${COPPELIASIM_ROOT_DIR}/../../Contents/PlugIns/coppeliaSim ABSOLUTE)
        else()
            get_filename_component(COPPELIASIM_PLUGINS_DIR ${COPPELIASIM_ROOT_DIR}/../../Contents/MacOS ABSOLUTE)
        endif()
        get_filename_component(COPPELIASIM_EXECUTABLES_DIR ${COPPELIASIM_ROOT_DIR}/../../Contents/MacOS ABSOLUTE)
        get_filename_component(COPPELIASIM_LIBRARIES_DIR ${COPPELIASIM_ROOT_DIR}/../../Contents/Frameworks ABSOLUTE)
    else()
        coppeliasim_find_error("Cannot determine plugins install dir (try specifying a valid COPPELIASIM_ROOT_DIR cmake variable)")
        return()
    endif()
    set(COPPELIASIM_ADDONS_DIR ${COPPELIASIM_RESOURCES_DIR}/addOns)
    set(COPPELIASIM_MANUAL_DIR ${COPPELIASIM_RESOURCES_DIR}/manual)
    set(COPPELIASIM_MODELS_DIR ${COPPELIASIM_RESOURCES_DIR}/models)
    set(COPPELIASIM_SCENES_DIR ${COPPELIASIM_RESOURCES_DIR}/scenes)
    set(COPPELIASIM_EXECUTABLE ${COPPELIASIM_EXECUTABLES_DIR}/coppeliaSim)
endif()
set(COPPELIASIM_LUA_DIR ${COPPELIASIM_RESOURCES_DIR}/lua)
set(COPPELIASIM_PYTHON_DIR ${COPPELIASIM_RESOURCES_DIR}/python)
if(NOT CoppeliaSim_FIND_QUIETLY)
    message(STATUS "CoppeliaSim: COPPELIASIM_RESOURCES_DIR: ${COPPELIASIM_RESOURCES_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_PLUGINS_DIR: ${COPPELIASIM_PLUGINS_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_EXECUTABLES_DIR: ${COPPELIASIM_EXECUTABLES_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_LIBRARIES_DIR: ${COPPELIASIM_LIBRARIES_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_ADDONS_DIR: ${COPPELIASIM_ADDONS_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_MANUAL_DIR: ${COPPELIASIM_MANUAL_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_MODELS_DIR: ${COPPELIASIM_MODELS_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_SCENES_DIR: ${COPPELIASIM_SCENES_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_LUA_DIR: ${COPPELIASIM_LUA_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_PYTHON_DIR: ${COPPELIASIM_PYTHON_DIR}")
    message(STATUS "CoppeliaSim: COPPELIASIM_EXECUTABLE: ${COPPELIASIM_EXECUTABLE}")
endif()

include_directories(${COPPELIASIM_INCLUDE_DIR})

function(COPPELIASIM_GENERATE_STUBS GENERATED_OUTPUT_DIR)
    cmake_parse_arguments(COPPELIASIM_GENERATE_STUBS "OLD_STYLE" "XML_FILE;LUA_FILE" "LUA_FILES" ${ARGN})
    if(NOT CoppeliaSim_FIND_QUIETLY)
        message(STATUS "Adding simStubsGen command...")
    endif()
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    if(Python3_VERSION VERSION_LESS 3.8)
        message(FATAL_ERROR "Python 3.8+ is required")
    endif()
    if(NOT CoppeliaSim_FIND_QUIETLY)
        message(STATUS "Reading plugin metadata...")
    endif()
    if(COPPELIASIM_GENERATE_STUBS_OLD_STYLE)
        set(OLD_STYLE_OPT --old-style)
    endif()
    execute_process(
        COMMAND ${Python3_EXECUTABLE}
            ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate.py
            ${OLD_STYLE_OPT}
            --xml-file ${COPPELIASIM_GENERATE_STUBS_XML_FILE}
            --gen-cmake-meta
            ${GENERATED_OUTPUT_DIR}
        RESULT_VARIABLE READ_PLUGIN_META_EXITCODE)
    if(NOT READ_PLUGIN_META_EXITCODE EQUAL 0)
        message(FATAL_ERROR "Failed reading plugin metadata (error in XML file?)")
    endif()
    include(${GENERATED_OUTPUT_DIR}/meta.cmake)
    if(NOT CoppeliaSim_FIND_QUIETLY)
        set(PLUGIN_INFO_STR "${PLUGIN_NAME}")
        if(PLUGIN_VERSION GREATER 0)
            set(PLUGIN_INFO_STR "${PLUGIN_INFO_STR} [version=${PLUGIN_VERSION}]")
        endif()
        message(STATUS "Plugin: ${PLUGIN_INFO_STR}")
    endif()
    if(PLUGIN_VERSION GREATER 0)
        set(PLUGIN_NAME_AND_VERSION ${PLUGIN_NAME}-${PLUGIN_VERSION})
    else()
        set(PLUGIN_NAME_AND_VERSION ${PLUGIN_NAME})
    endif()
    set(OUTPUT_FILES
        ${GENERATED_OUTPUT_DIR}/stubs.cpp
        ${GENERATED_OUTPUT_DIR}/stubs.h
        ${GENERATED_OUTPUT_DIR}/plugin.h
        ${GENERATED_OUTPUT_DIR}/stubsPlusPlus.cpp
        ${GENERATED_OUTPUT_DIR}/index.json
        ${GENERATED_OUTPUT_DIR}/reference.html
    )
    set(COMMAND_ARGS
        ${Python3_EXECUTABLE}
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate.py
        --verbose
        --xml-file ${COPPELIASIM_GENERATE_STUBS_XML_FILE}
        --gen-all ${GENERATED_OUTPUT_DIR}
    )
    set(DEPENDENCIES
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/__init__.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate_api_index.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate_ce.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate_cmake_metadata.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate_lua_typechecker.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/generate_lua_xml.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/merge_xml.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/parse.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/model/__init__.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/model/command.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/model/enum.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/model/param.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/model/plugin.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/model/script_function.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/model/struct.py
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/cpp/plugin.h
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/cpp/stubs.cpp
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/cpp/stubs.h
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/cpp/stubsPlusPlus.cpp
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/xsd/callbacks.xsd
        ${COPPELIASIM_INCLUDE_DIR}/simStubsGen/xsl/reference.xsl
        ${COPPELIASIM_GENERATE_STUBS_XML_FILE}
    )
    if(NOT "${COPPELIASIM_GENERATE_STUBS_LUA_FILE}" STREQUAL "")
        list(APPEND COMMAND_ARGS --lua-file ${COPPELIASIM_GENERATE_STUBS_LUA_FILE})
        list(APPEND DEPENDENCIES ${COPPELIASIM_GENERATE_STUBS_LUA_FILE})
        get_filename_component(LUA_FILE_NAME_WLE ${COPPELIASIM_GENERATE_STUBS_LUA_FILE} NAME_WLE)
        list(APPEND OUTPUT_FILES ${GENERATED_OUTPUT_DIR}/typecheck.lua)
        install(FILES ${GENERATED_OUTPUT_DIR}/typecheck.lua RENAME ${PLUGIN_NAME_AND_VERSION}-typecheck.lua DESTINATION ${COPPELIASIM_LUA_DIR})
        install(FILES ${COPPELIASIM_GENERATE_STUBS_LUA_FILE} RENAME ${PLUGIN_NAME_AND_VERSION}.lua DESTINATION ${COPPELIASIM_LUA_DIR})
    endif()
    if(NOT "${COPPELIASIM_GENERATE_STUBS_LUA_FILES}" STREQUAL "")
        foreach(LUA_FILE IN LISTS COPPELIASIM_GENERATE_STUBS_LUA_FILES)
            message(STATUS "Processing Lua file: ${LUA_FILE}")
            list(APPEND COMMAND_ARGS --lua-file ${LUA_FILE})
            list(APPEND DEPENDENCIES ${LUA_FILE})
            get_filename_component(LUA_FILE_NAME_WLE ${LUA_FILE} NAME_WLE)
        endforeach()
        list(APPEND OUTPUT_FILES ${GENERATED_OUTPUT_DIR}/typecheck.lua)
        install(FILES ${GENERATED_OUTPUT_DIR}/typecheck.lua RENAME ${PLUGIN_NAME_AND_VERSION}-typecheck.lua DESTINATION ${COPPELIASIM_LUA_DIR})
    endif()
    add_custom_command(OUTPUT ${OUTPUT_FILES} COMMAND ${COMMAND_ARGS} DEPENDS ${DEPENDENCIES})
    set(INDEX_FILE_NAME ${PLUGIN_NAME_AND_VERSION}.json)
    install(FILES ${GENERATED_OUTPUT_DIR}/reference.html RENAME ${PLUGIN_NAME}.htm DESTINATION ${COPPELIASIM_MANUAL_DIR}/en/${PLUGIN_NAME_AND_VERSION})
    install(FILES ${GENERATED_OUTPUT_DIR}/index.json RENAME ${INDEX_FILE_NAME} DESTINATION ${COPPELIASIM_MANUAL_DIR}/index)
    if(NOT COPPELIASIM_GENERATE_STUBS_OLD_STYLE)
        list(APPEND OUTPUT_FILES ${GENERATED_OUTPUT_DIR}/ce.lua)
        install(FILES ${GENERATED_OUTPUT_DIR}/ce.lua RENAME ${PLUGIN_NAME_AND_VERSION}-ce.lua DESTINATION ${COPPELIASIM_LUA_DIR})
    endif()
    set_property(SOURCE ${GENERATED_OUTPUT_DIR}/stubs.cpp PROPERTY SKIP_AUTOGEN ON)
    set_property(SOURCE ${GENERATED_OUTPUT_DIR}/stubs.h PROPERTY SKIP_AUTOGEN ON)
    include_directories("${GENERATED_OUTPUT_DIR}")
    list(APPEND COPPELIASIM_EXPORTED_SOURCES "${GENERATED_OUTPUT_DIR}/stubs.cpp")
    set(COPPELIASIM_EXPORTED_SOURCES "${COPPELIASIM_EXPORTED_SOURCES}" PARENT_SCOPE)
endfunction(COPPELIASIM_GENERATE_STUBS)

find_package(Boost REQUIRED CONFIG COMPONENTS regex)

function(COPPELIASIM_ADD_PLUGIN PLUGIN_TARGET_NAME)
    cmake_parse_arguments(COPPELIASIM_ADD_PLUGIN "LEGACY" "" "SOURCES" ${ARGN})
    if(PLUGIN_VERSION GREATER 0)
        set(PLUGIN_TARGET_NAME_V "${PLUGIN_TARGET_NAME}-${PLUGIN_VERSION}")
    else()
        set(PLUGIN_TARGET_NAME_V "${PLUGIN_TARGET_NAME}")
    endif()
    add_library(${PLUGIN_TARGET_NAME_V} SHARED ${COPPELIASIM_EXPORTED_SOURCES} ${COPPELIASIM_ADD_PLUGIN_SOURCES})
    target_compile_definitions(${PLUGIN_TARGET_NAME_V} PRIVATE UID=int)
    target_include_directories(${PLUGIN_TARGET_NAME_V} PRIVATE ${COPPELIASIM_INCLUDE_DIR})
    target_link_libraries(${PLUGIN_TARGET_NAME_V} PRIVATE ${COPPELIASIM_LIBRARIES})
    target_link_libraries(${PLUGIN_TARGET_NAME_V} PUBLIC Boost::boost Boost::regex)
    if(UNIX)
        target_compile_options(${PLUGIN_TARGET_NAME_V} PRIVATE -fvisibility=hidden)
    endif()
    install(TARGETS ${PLUGIN_TARGET_NAME_V} DESTINATION ${COPPELIASIM_PLUGINS_DIR})
endfunction(COPPELIASIM_ADD_PLUGIN)

function(COPPELIASIM_ADD_EXECUTABLE EXECUTABLE_TARGET_NAME)
    cmake_parse_arguments(COPPELIASIM_ADD_EXECUTABLE "" "" "SOURCES" ${ARGN})
    add_executable(${EXECUTABLE_TARGET_NAME} ${COPPELIASIM_ADD_EXECUTABLE_SOURCES})
    if(UNIX)
        target_compile_options(${EXECUTABLE_TARGET_NAME} PRIVATE -fvisibility=hidden)
    endif()
    install(TARGETS ${EXECUTABLE_TARGET_NAME} DESTINATION ${COPPELIASIM_EXECUTABLES_DIR})
endfunction(COPPELIASIM_ADD_EXECUTABLE)

function(COPPELIASIM_ADD_ADDON ADDON_FILE)
    install(FILES ${ADDON_FILE} DESTINATION ${COPPELIASIM_ADDONS_DIR})
endfunction(COPPELIASIM_ADD_ADDON)

function(COPPELIASIM_ADD_LUA LUA_FILE)
    cmake_parse_arguments(COPPELIASIM_ADD_LUA "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_LUA_SUBDIR)
        install(FILES ${LUA_FILE} DESTINATION ${COPPELIASIM_LUA_DIR}/${COPPELIASIM_ADD_LUA_SUBDIR})
    else()
        install(FILES ${LUA_FILE} DESTINATION ${COPPELIASIM_LUA_DIR})
    endif()
endfunction(COPPELIASIM_ADD_LUA)

function(COPPELIASIM_ADD_LUA_DIRECTORY LUA_DIR)
    cmake_parse_arguments(COPPELIASIM_ADD_LUA_DIRECTORY "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_LUA_DIRECTORY_SUBDIR)
        install(DIRECTORY ${LUA_DIR} DESTINATION ${COPPELIASIM_LUA_DIR}/${COPPELIASIM_ADD_LUA_DIRECTORY_SUBDIR})
    else()
        install(DIRECTORY ${LUA_DIR} DESTINATION ${COPPELIASIM_LUA_DIR})
    endif()
endfunction(COPPELIASIM_ADD_LUA_DIRECTORY)

function(COPPELIASIM_ADD_PYTHON PYTHON_FILE)
    cmake_parse_arguments(COPPELIASIM_ADD_PYTHON "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_PYTHON_SUBDIR)
        install(FILES ${PYTHON_FILE} DESTINATION ${COPPELIASIM_PYTHON_DIR}/${COPPELIASIM_ADD_PYTHON_SUBDIR})
    else()
        install(FILES ${PYTHON_FILE} DESTINATION ${COPPELIASIM_PYTHON_DIR})
    endif()
endfunction(COPPELIASIM_ADD_PYTHON)

function(COPPELIASIM_ADD_PYTHON_DIRECTORY PYTHON_DIR)
    cmake_parse_arguments(COPPELIASIM_ADD_PYTHON_DIRECTORY "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_PYTHON_DIRECTORY_SUBDIR)
        install(DIRECTORY ${PYTHON_DIR} DESTINATION ${COPPELIASIM_PYTHON_DIR}/${COPPELIASIM_ADD_PYTHON_DIRECTORY_SUBDIR})
    else()
        install(DIRECTORY ${PYTHON_DIR} DESTINATION ${COPPELIASIM_PYTHON_DIR})
    endif()
endfunction(COPPELIASIM_ADD_PYTHON_DIRECTORY)

function(COPPELIASIM_ADD_MANUAL MANUAL)
    cmake_parse_arguments(COPPELIASIM_ADD_MANUAL "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_MANUAL_SUBDIR)
        install(FILES ${MANUAL} DESTINATION ${COPPELIASIM_MANUAL_DIR}/${COPPELIASIM_ADD_MANUAL_SUBDIR})
    else()
        install(FILES ${MANUAL} DESTINATION ${COPPELIASIM_MANUAL_DIR}/en)
    endif()
endfunction(COPPELIASIM_ADD_MANUAL)

function(COPPELIASIM_ADD_MANUAL_DIRECTORY MANUAL_DIR)
    cmake_parse_arguments(COPPELIASIM_ADD_MANUAL_DIRECTORY "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_MANUAL_DIRECTORY_SUBDIR)
        install(DIRECTORY ${MANUAL_DIR} DESTINATION ${COPPELIASIM_MANUAL_DIR}/${COPPELIASIM_ADD_MANUAL_DIRECTORY_SUBDIR})
    else()
        install(DIRECTORY ${MANUAL_DIR} DESTINATION ${COPPELIASIM_MANUAL_DIR})
    endif()
endfunction(COPPELIASIM_ADD_MANUAL_DIRECTORY)

function(COPPELIASIM_ADD_LIBRARY LIB_FILE)
    install(FILES ${LIB_FILE} DESTINATION ${COPPELIASIM_LIBRARIES_DIR})
endfunction(COPPELIASIM_ADD_LIBRARY)

function(COPPELIASIM_ADD_PLUGIN_DIRECTORY DIR)
    cmake_parse_arguments(COPPELIASIM_ADD_PLUGIN_DIRECTORY "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_PLUGIN_DIRECTORY_SUBDIR)
        install(DIRECTORY ${DIR} DESTINATION ${COPPELIASIM_PLUGINS_DIR}/${COPPELIASIM_ADD_PLUGIN_DIRECTORY_SUBDIR})
    else()
        install(DIRECTORY ${DIR} DESTINATION ${COPPELIASIM_PLUGINS_DIR})
    endif()
endfunction(COPPELIASIM_ADD_PLUGIN_DIRECTORY)

function(COPPELIASIM_ADD_MODEL MODEL_FILE)
    cmake_parse_arguments(COPPELIASIM_ADD_MODEL "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_MODEL_SUBDIR)
        install(FILES ${MODEL_FILE} DESTINATION ${COPPELIASIM_MODELS_DIR}/${COPPELIASIM_ADD_MODEL_SUBDIR})
    else()
        install(FILES ${MODEL_FILE} DESTINATION ${COPPELIASIM_MODELS_DIR})
    endif()
endfunction(COPPELIASIM_ADD_MODEL)

function(COPPELIASIM_ADD_MODEL_DIRECTORY MODEL_DIR)
    cmake_parse_arguments(COPPELIASIM_ADD_MODEL_DIRECTORY "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_MODEL_DIRECTORY_SUBDIR)
        install(DIRECTORY ${MODEL_DIR} DESTINATION ${COPPELIASIM_MODELS_DIR}/${COPPELIASIM_ADD_MODEL_DIRECTORY_SUBDIR})
    else()
        install(DIRECTORY ${MODEL_DIR} DESTINATION ${COPPELIASIM_MODELS_DIR})
    endif()
endfunction(COPPELIASIM_ADD_MODEL_DIRECTORY)

function(COPPELIASIM_ADD_SCENE SCENE_FILE)
    cmake_parse_arguments(COPPELIASIM_ADD_SCENE "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_SCENE_SUBDIR)
        install(FILES ${SCENE_FILE} DESTINATION ${COPPELIASIM_SCENES_DIR}/${COPPELIASIM_ADD_SCENE_SUBDIR})
    else()
        install(FILES ${SCENE_FILE} DESTINATION ${COPPELIASIM_SCENES_DIR})
    endif()
endfunction(COPPELIASIM_ADD_SCENE)

function(COPPELIASIM_ADD_SCENE_DIRECTORY SCENE_DIR)
    cmake_parse_arguments(COPPELIASIM_ADD_SCENE_DIRECTORY "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_SCENE_DIRECTORY_SUBDIR)
        install(DIRECTORY ${SCENE_DIR} DESTINATION ${COPPELIASIM_SCENES_DIR}/${COPPELIASIM_ADD_SCENE_DIRECTORY_SUBDIR})
    else()
        install(DIRECTORY ${SCENE_DIR} DESTINATION ${COPPELIASIM_SCENES_DIR})
    endif()
endfunction(COPPELIASIM_ADD_SCENE_DIRECTORY)

function(COPPELIASIM_ADD_RESOURCE RESOURCE_FILE)
    cmake_parse_arguments(COPPELIASIM_ADD_RESOURCE "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_RESOURCE_SUBDIR)
        install(FILES ${RESOURCE_FILE} DESTINATION ${COPPELIASIM_RESOURCES_DIR}/${COPPELIASIM_ADD_RESOURCE_SUBDIR})
    else()
        install(FILES ${RESOURCE_FILE} DESTINATION ${COPPELIASIM_RESOURCES_DIR})
    endif()
endfunction(COPPELIASIM_ADD_RESOURCE)

function(COPPELIASIM_ADD_RESOURCE_DIRECTORY RESOURCE_DIR)
    cmake_parse_arguments(COPPELIASIM_ADD_RESOURCE_DIRECTORY "" "SUBDIR" "" ${ARGN})
    if(COPPELIASIM_ADD_RESOURCE_DIRECTORY_SUBDIR)
        install(DIRECTORY ${RESOURCE_DIR} DESTINATION ${COPPELIASIM_RESOURCES_DIR}/${COPPELIASIM_ADD_RESOURCE_DIRECTORY_SUBDIR})
    else()
        install(DIRECTORY ${RESOURCE_DIR} DESTINATION ${COPPELIASIM_RESOURCES_DIR})
    endif()
endfunction(COPPELIASIM_ADD_RESOURCE_DIRECTORY)

find_package(Git)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/.git AND GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE "BUILD_GIT_VERSION"
        RESULT_VARIABLE "GIT_RESULT"
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NOT GIT_RESULT EQUAL 0)
        set(BUILD_GIT_VERSION "unknown")
    endif()
else()
    set(BUILD_GIT_VERSION "unknown")
endif()

set(COPPELIASIM_FOUND TRUE)
