#include <iostream>
#include <core/window.h>

namespace LatticeViz::Core
{

	void Window::Create(const WindowParams& window_params)
	{
		if(!glfwInit())
		{
			std::cerr << "Failed to initialize GLFW" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

		const auto window = glfwCreateWindow(
			window_params.width,
			window_params.height,
			window_params.title,
			nullptr,
			nullptr
		);

		if(window == nullptr)
		{
			std::cerr << "Failed to initialize GLFW" << std::endl;
			glfwTerminate();
			return;
		}

		m_window = Smart_GLFWWindow(window);

		glfwSwapInterval(1);
	}

	void Window::PollEvents() const
	{
		glfwPollEvents();
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_window.get());
	}

	void Window::Close() const
	{
		glfwDestroyWindow(m_window.get());
	}

	void Window::SwapBuffer() const
	{
		glfwSwapBuffers(m_window.get());
	}

}
