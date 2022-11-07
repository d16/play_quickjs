project(QuickJS LANGUAGES "C")

add_definitions("-DCONFIG_VERSION=\"2021-03-27\"")
add_definitions("-DCONFIG_BIGNUM")
add_definitions("-D_GNU_SOURCE")

file(GLOB_RECURSE SRC_FILES *.c)
file(GLOB_RECURSE HDR_FILES *.h)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -MMD -Wno-array-bounds -Wno-format-truncation")

add_library( ${PROJECT_NAME} STATIC ${SRC_FILES} ${HDR_FILES} )
