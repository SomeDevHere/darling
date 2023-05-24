project(bsdln)
include(darling_native_exe)

add_darling_native_executable(bsdln
	ln.c
)
target_link_libraries(bsdln bsd)
