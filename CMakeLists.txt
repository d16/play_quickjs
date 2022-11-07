cmake_minimum_required(VERSION 3.16)

project(PlayQuickJS C CXX)

enable_testing()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb3")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

if(MSVC)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

add_subdirectory(QuickJS)
add_subdirectory(qjsc)
if( EXISTS ${CMAKE_HOME_DIRECTORY}/qjs/repl.c AND EXISTS ${CMAKE_HOME_DIRECTORY}/qjs/qjscalc.c)
  add_subdirectory(qjs)
endif()
if(EXISTS ${CMAKE_HOME_DIRECTORY}/TypeScript/src/tsc.c)
  add_subdirectory(TypeScript)
endif()
