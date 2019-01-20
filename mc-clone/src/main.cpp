#include <glad/glad.h>
#include "Display/Display.hpp"
#include "Renderer/ChunkRenderer.hpp"

int main()
{
	// Display creation
	Display display(1280, 720);

	Camera cam(&display);

	ChunkRenderer renderer(&cam);

	for(int i = 0; i < 16 * 16; i += 16)
		for(int j = 0; j < 16 * 16; j += 16)
			renderer.add({ {i, 0.0f, j} });
	
	renderer.initialize();

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

