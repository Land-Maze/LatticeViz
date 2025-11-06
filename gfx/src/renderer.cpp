#include <iostream>
#include <gfx/renderer.h>
#include <glad/glad.h>

namespace LatticeViz::GFX
{
	void Renderer::Initialize(GLFWwindow* window)
	{
		glfwMakeContextCurrent(window);

		if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			std::cerr << "Failed to initialize GLAD\n";
			return;
		}

		std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";
	}
}
