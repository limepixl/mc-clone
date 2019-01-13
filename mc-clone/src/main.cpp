#include <glad/glad.h>
#include "Display/Display.hpp"
#include "Renderer/Renderer.hpp"

int main()
{
	// Display creation
	Display display(1920, 1080);

	Camera cam(&display);

	Renderer renderer(&cam);

	for(int i = 0; i < 100; i++)
	for(int j = 0; j < 100; j++)
	{
		renderer.add({ { -(float)i, -0.5f, -(float)j }, { 0.0f, 0.0f, 0.0f } });
	}

	// Render loop
	while(display.isOpen())
	{
		// Delta time calculation
		display.calcDelta(glfwGetTime());

		// Clearing the window
		display.clear();

		cam.processCamMovement();
		cam.processCamMouse();
		
		renderer.render();

		// Swap buffers and poll events
		display.update();
	}

	glfwTerminate();
	return 0;
}

