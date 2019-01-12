#include <glad/glad.h>
#include "Camera/Camera.h"
#include "RM/ResourceManager.h"
#include "Display/Display.h"
#include <iostream>
#include <vector>
#include "Renderer/Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main()
{
	// Window creation
	Display display(WIDTH, HEIGHT);

	// Camera initialization
	Camera cam(WIDTH, HEIGHT);

	Renderer renderer(&cam);

	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
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

		cam.processCamMovement(display.window, display.deltaTime);

		
		renderer.render();

		display.update();
	}

	glfwTerminate();
	return 0;
}

