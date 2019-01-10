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

	Camera(int windowWidth, int windowHeight);

	void updateVectors();

	void processCamMovement(GLFWwindow* window, double deltaTime);
};