file(GLOB_RECURSE FILES_SRC CONFIGURE_DEPENDS
		"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(crypto ${FILES_SRC})

target_include_directories(crypto PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(crypto PUBLIC)