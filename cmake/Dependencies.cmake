include(FetchContent)

# ---------------------------------------------------------------------------
# GLFW
# ---------------------------------------------------------------------------
FetchContent_Declare(
		glfw
		GIT_REPOSITORY https://github.com/glfw/glfw.git
		GIT_TAG latest
		GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glfw)

# ---------------------------------------------------------------------------
# ImGui
# ---------------------------------------------------------------------------
FetchContent_Declare(
		imgui
		GIT_REPOSITORY https://github.com/ocornut/imgui.git
		GIT_TAG master
		GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(imgui)

add_library(imgui_lib
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui_lib PUBLIC
		${imgui_SOURCE_DIR}
		${imgui_SOURCE_DIR}/backends
)
target_link_libraries(imgui_lib PUBLIC glfw)

# ---------------------------------------------------------------------------
# GLAD
# ---------------------------------------------------------------------------
add_library(glad STATIC
		third-party/glad/src/glad.c
)

target_include_directories(glad PUBLIC
		third-party/glad/include/
)

# ---------------------------------------------------------------------------
# GLM
# ---------------------------------------------------------------------------
FetchContent_Declare(
		glm
		GIT_REPOSITORY https://github.com/g-truc/glm.git
		GIT_TAG 1.0.2
		GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glm)
