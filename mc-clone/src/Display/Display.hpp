#pragma once

class Display
{
public:
	struct GLFWwindow* window;

	double deltaTime = 0.0;
	double lastFrame = 0.0;

	int width;
	int height; 

public:
	Display(int windowWidth, int windowHeight);

	// Calculates the delta time between frames
	void calcDelta(double currentTime);

	void clear();
	void update();

	bool isOpen() const;
};