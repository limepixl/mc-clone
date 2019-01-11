#pragma once

class Display
{
public:
	struct GLFWwindow* window;

	double deltaTime = 0.0;
	double lastFrame = 0.0;

private:
	int m_width;
	int m_height; 

public:
	Display(unsigned int windowWidth, unsigned int windowHeight);

	// Calculates the delta time between frames
	void calcDelta(double currentTime);

	void clear();
	void update();

	bool isOpen() const;
};