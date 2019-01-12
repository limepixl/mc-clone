#include <glad/glad.h>
#include "Camera/Camera.h"
#include "Display/Display.h"
#include "Renderer/Renderer.h"

int main()
{
	// Display creation
	Display display(1280, 720);

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

