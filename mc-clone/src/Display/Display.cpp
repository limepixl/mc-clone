#include "Display.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Display::Display(unsigned int windowWidth, unsigned int windowHeight)
	: m_width(windowWidth), m_height(windowHeight)
{
	// GLFW init	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window and context creation
	window = glfwCreateWindow(m_width, m_height, "Window Title", nullptr, nullptr);
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

	glViewport(0, 0, windowWidth, windowHeight);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void Display::clear()
{
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
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
