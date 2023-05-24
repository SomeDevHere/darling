
FUNCTION(add_darling_native_executable exe)
	foreach(f IN LISTS ARGN)
		set(files ${files} ${f})
	endforeach(f)
	add_executable(${exe} ${files})
	set_property(TARGET ${exe} APPEND_STRING PROPERTY
		LINK_FLAGS "${DARLING_NATIVE_EXE_LINKER_FLAGS}")
ENDFUNCTION(add_darling_native_executable)
