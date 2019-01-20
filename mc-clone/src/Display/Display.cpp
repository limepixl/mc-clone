#include "Display.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Display::Display(int windowWidth, int windowHeight)
	: width(windowWidth), height(windowHeight)
{
	init();

	// Setup viewport
	glViewport(0, 0, windowWidth, windowHeight);

	// Enable the depth testing and culling
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glCullFace(GL_LEFT);
	glCullFace(GL_RIGHT);

	// Cursor is bound to window
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Display::clear()
{
	glClearColor(0.3f, 0.3f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::calcDelta(double currentTime)
{
	deltaTime = currentTime - lastFrame;
	lastFrame = currentTime;
}

void Display::update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Display::isOpen() const
{
	return !glfwWindowShouldClose(window);
}

void Display::init()
{
	// GLFW init	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window and context creation
	window = glfwCreateWindow(width, height, "Window title", nullptr, nullptr);
	if(window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	// GLAD init
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}