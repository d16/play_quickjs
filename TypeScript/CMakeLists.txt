project(tsc LANGUAGES "C")

include_directories(${CMAKE_HOME_DIRECTORY}/QuickJS)

file(GLOB_RECURSE SRC_FILES *.c)
file(GLOB_RECURSE HDR_FILES *.h)

link_directories(${CMAKE_HOME_DIRECTORY}/build/lib)

add_executable( ${PROJECT_NAME} ${SRC_FILES} ${fHDR_FILES} )
target_link_libraries(${PROJECT_NAME} m QuickJS)
