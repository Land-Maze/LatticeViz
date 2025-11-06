#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace LatticeViz::GFX
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		void Initialize(GLFWwindow* window);
	private:
	};
}
