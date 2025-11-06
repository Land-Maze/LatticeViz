#include <iostream>
#include <core/window.h>

namespace LatticeViz::Core
{
	// FIXME: Fill everything here later

	void Window::create(const WindowParams& window_params)
	{
		std::cout << "Hello world!";
	}

	void Window::pollEvents() const
	{
	}

	bool Window::shouldClose() const
	{
		return true;
	}

	void Window::close()
	{
	}
}
