#pragma once
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

// Camera class to provide a view matrix that behaves
// like an FPS camera. Controls are WASD for axis  
// movement and the mouse for looking around.
class Camera
{
public:
	glm::vec3 position;		// Camera's 3D position
	glm::vec3 front;		// Vector pointing forwards
	glm::vec3 right;		// Vector pointing in positive X
	glm::vec3 up;			// Vector pointing upwards

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

	// For convenience of getting the dimensions of the display
	class Display* m_display;

public:
	Camera(class Display* display);

	// Uses the newly modified vectors
	// and returns the view matrix
	glm::mat4 getViewMatrix();

	// Camera keyboard movement
	void processCamKeyboard();
	
	// Camera mouse movement
	void processCamMouse();

private:
	void updateVectors();
};

