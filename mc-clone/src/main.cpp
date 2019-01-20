#include <glad/glad.h>
#include "Display/Display.hpp"
#include "Renderer/ChunkRenderer.hpp"

int main()
{
	Display display(1280, 720);
	Camera cam(&display);
	ChunkRenderer renderer(&cam);

	// Chunk creation
	// Creating n chunks all sized 16x16.
	for(int i = 0; i < 16 * 16; i += 16)
		for(int j = 0; j < 16 * 16; j += 16)
			renderer.add({ {i, 0.0f, j} });
	
	// Create a chunk for each entity.
	// (So the same mesh isn't used again and again)
	renderer.populate();

	// Render loop
	while(display.isOpen())
	{
		// Delta time calculation
		display.calcDelta(glfwGetTime());

		// Clearing the window
		display.clear();

		// Process camera input for 3D movement
		cam.processCamKeyboard();
		cam.processCamMouse();
		
		// Render all meshes in their respective positions
		renderer.render();

		// Swap buffers and poll events
		display.update();
	}

	glfwTerminate();
	return 0;
}

