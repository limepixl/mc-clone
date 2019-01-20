#pragma once

class Display
{
public:
	struct GLFWwindow* window;

	// Values used for deltatime calculation
	double deltaTime = 0.0;
	double lastFrame = 0.0;

	// Window's dimensions
	int width;
	int height; 

public:
	Display(int windowWidth, int windowHeight);

	// Calculates the delta time between frames
	void calcDelta(double currentTime);

	// Clear the buffer with a color
	void clear();

	// Swap buffers and poll glfw events
	void update();

	bool isOpen() const;

private:
	// GLFW and GLAD init
	void init();
};