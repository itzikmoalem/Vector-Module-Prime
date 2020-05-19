cmake_minimum_required (VERSION 3.14)

project(oop1_ex03)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	add_compile_options (/permissive-)
endif ()

add_executable (oop1_ex03 "")

add_subdirectory (include)
add_subdirectory (src)
