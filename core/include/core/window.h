#pragma once

#include <memory>
#include <GLFW/glfw3.h>

namespace LatticeViz::Core
{
	struct DestroyGLFWWindow
	{
		void operator()(GLFWwindow* ptr) const
		{
			if(ptr) glfwDestroyWindow(ptr);
		}
	};

	using Smart_GLFWWindow = std::unique_ptr<GLFWwindow, DestroyGLFWWindow>;

	class Window
	{
	public:
		Window() = default;
		~Window() = default;

		/**
		 * @param width Width of the window (excluding DPI scaling)
		 * @param height of the window (excluding DPI scaling)
		 * @param title Title of the window
		 */
		struct WindowParams
		{
			int width = 800;
			int height = 600;
			const char* title = "Window";
		};

		/**
		 * Creates a GLFW window with the specified title and dimensions.
		 *
		 * @param window_params Struct that includes title, width, height
		 */
		void create(const WindowParams& window_params);

		/**
		 * Polls events from the windowing system.
		 * Such as keyboard and mouse input, window resize, etc.
		 */
		void pollEvents() const;

		/**
		 * Checks if the window should close.
		 * For example, if the user has clicked the close button.
		 * Or if the application has requested to close the window (e.g. via ctrl+c or alt+f4).
		 *
		 * @return True if the window should close, False otherwise.
		 */
		[[nodiscard]] bool shouldClose() const;

		/**
		 * Destroys the window and releases resources related to it.
		 * After calling this function, the window object should not be used anymore.
		 */
		void close();

		/**
		 *
		 * @return Returns a pointer to the underlying GLFW window object.
		 */
		[[nodiscard]] GLFWwindow* getGLFWWindow() const { return m_window.get(); };

	private:
		Smart_GLFWWindow m_window = nullptr;
		GLFWmonitor* m_monitor = nullptr;

		WindowParams m_window_params;
	};
}
