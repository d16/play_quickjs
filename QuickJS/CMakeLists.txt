project(QuickJS LANGUAGES "C")

add_definitions("-DCONFIG_VERSION=\"2021-03-27\"")
add_definitions("-DCONFIG_BIGNUM")

file(GLOB_RECURSE SRC_FILES *.c)
file(GLOB_RECURSE HDR_FILES *.h)

add_library( ${PROJECT_NAME} STATIC ${SRC_FILES} ${HDR_FILES} )
