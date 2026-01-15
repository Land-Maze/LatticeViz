file(GLOB_RECURSE FILES_SRC CONFIGURE_DEPENDS
		"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(benchmark ${FILES_SRC})

target_link_libraries(benchmark PUBLIC)