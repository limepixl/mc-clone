#pragma once
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Camera
{
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;

	glm::mat4 viewMatrix;
	glm::mat4 projMatrix;

	float speed;

private:
	// Variables needed for mouse movement calculation
	bool firstMouse;								  
													  
	double yaw;										  
	double pitch;									  
													  
	double lastX;									  
	double lastY;									  
													  
	float mouseSens;	

	class Display* m_display;

public:
	Camera(class Display* display);

	glm::mat4 getViewMatrix();

	// Camera keyboard movement
	void processCamMovement();
	
	// Camera mouse movement
	void processCamMouse();

	void updateVectors();
};

