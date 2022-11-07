if(EXISTS ${CMAKE_HOME_DIRECTORY}/qjs/repl.c AND EXISTS ${CMAKE_HOME_DIRECTORY}/qjs/qjscalc.c)
    project(qjs LANGUAGES "C")

    include_directories(${CMAKE_HOME_DIRECTORY}/QuickJS)

    add_definitions("-DCONFIG_VERSION=\"2021-03-27\"")
    add_definitions("-DCONFIG_BIGNUM")

    file(GLOB_RECURSE SRC_FILES *.c)
    file(GLOB_RECURSE HDR_FILES *.h)

    link_directories(${CMAKE_HOME_DIRECTORY}/build/lib)

    add_executable( ${PROJECT_NAME} ${SRC_FILES} ${fHDR_FILES} )
    target_link_libraries(${PROJECT_NAME} m QuickJS)
endif()