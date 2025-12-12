cmake_minimum_required(VERSION 4.0)
project(
		LWELibrary
		DESCRIPTION "A library for Learning With Errors (LWE) cryptographic schemes such as Modular LWE and Ring LWE."
		VERSION 0.1.0
		LANGUAGES CXX C
)

add_executable(LWELibrary src/main.cpp)

set_target_properties(LWELibrary PROPERTIES
		CXX_STANDARD 23
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS OFF
		COMPILE_WARNING_AS_ERROR ON
		CMAKE_CXX_FLAGS_DEBUG "-g -O0"
		CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG"
)

include(cmake/Dependencies.cmake)

add_subdirectory(core)
add_subdirectory(crypto)

if (MSVC)
	target_compile_options(LWELibrary PRIVATE /W4)
else()
	target_compile_options(LWELibrary PRIVATE -Wall -Wextra -pedantic)
endif()