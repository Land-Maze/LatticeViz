#include <core/window.h>
#include <gfx/renderer.h>

using namespace LatticeViz;

int main(void)
{
	Core::Window window;
	GFX::Renderer renderer;

	window.Create(
		{
			800,
			600,
			"LWE Visualisation"
		}
	);

	renderer.Initialize(window.GetGLFWWindow());

	while(!window.ShouldClose())
	{

		window.PollEvents();
		window.SwapBuffer();
	}

	window.Close();
	glfwTerminate();
	return 0;
}
