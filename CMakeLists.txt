cmake_minimum_required(VERSION 4.0)
project(
		LatticeViz
		VERSION 0.1.0
		LANGUAGES CXX
)

add_executable(${PROJECT_NAME} src/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS OFF
		COMPILE_WARNING_AS_ERROR ON
		CMAKE_CXX_FLAGS_DEBUG "-g -O0"
		CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG"
)

include(cmake/Dependencies.cmake)

add_subdirectory(core)
add_subdirectory(crypto)
add_subdirectory(gfx)

target_link_libraries(${PROJECT_NAME} PRIVATE core crypto gfx)