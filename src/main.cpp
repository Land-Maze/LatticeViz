#include <core/window.h>

using namespace LatticeViz;

int main(void)
{
	Core::Window window;

	window.create(
		{
			800,
			600,
			"LWE Visualisation"
		}
	);

	while(!window.shouldClose())
	{

	}

	return 0;
}
