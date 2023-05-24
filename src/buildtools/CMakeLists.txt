project(buildtools)
include(darling_native_exe)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/../external/cctools-port/cctools/include)

add_darling_native_executable(getuuid getuuid.c)
add_darling_native_executable(elfdep elfdep.c)

#add_subdirectory(Rez)
