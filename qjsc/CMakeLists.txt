project(qjsc LANGUAGES "C")

include_directories(${CMAKE_HOME_DIRECTORY}/QuickJS)

add_definitions("-DCONFIG_VERSION=\"2021-03-27\"")
add_definitions("-DCONFIG_BIGNUM")

file(GLOB_RECURSE SRC_FILES *.c)
file(GLOB_RECURSE HDR_FILES *.h)

link_directories(${CMAKE_HOME_DIRECTORY}/build/lib)

add_executable( ${PROJECT_NAME} ${SRC_FILES} ${fHDR_FILES} )
target_link_libraries(${PROJECT_NAME} m QuickJS)

if(EXISTS ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc OR EXISTS ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc.exe)
    if(NOT EXISTS ${CMAKE_HOME_DIRECTORY}/qjs/repl.c)
        if(WIN32)
            execute_process(COMMAND ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc.exe -c -o repl.c -m repl.js WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/qjs)
        else()
            execute_process(COMMAND ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc -c -o repl.c -m repl.js WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/qjs)
        endif()
    endif()

    if(NOT EXISTS ${CMAKE_HOME_DIRECTORY}/qjs/qjscalc.c)
        if(WIN32)
            execute_process(COMMAND ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc.exe -fbignum -c -o qjscalc.c qjscalc.js WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/qjs)
        else()
            execute_process(COMMAND ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc -fbignum -c -o qjscalc.c qjscalc.js WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/qjs)
        endif()
    endif()

    if(WIN32)
        execute_process(COMMAND ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc.exe -flto -c -o tsc.c -S 2097152 tsc.js WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/TypeScript/src)
    else()
        execute_process(COMMAND ${CMAKE_HOME_DIRECTORY}/build/bin/qjsc -flto -c -o tsc.c -S 2097152 tsc.js WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/TypeScript/src)
    endif()
endif()
