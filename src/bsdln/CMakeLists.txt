project(bsdln)
include(darling_host_exe)

add_darling_host_executable(bsdln
	ln.c
)
target_link_libraries(bsdln bsd)
