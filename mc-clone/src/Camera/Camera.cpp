#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(int windowWidth, int windowHeight)
{
	position = glm::vec3(0.0);
	front = glm::vec3(0.0, 0.0, -1.0);
	right = glm::vec3(1.0, 0.0, 0.0);
	up = glm::vec3(0.0, 1.0, 0.0);

	projMatrix = glm::perspective(glm::radians(50.0f), (float)windowWidth / windowHeight, 0.1f, 100.0f);
}

void Camera::updateVectors()
{
	viewMatrix = glm::lookAt(position, position + front, up);
}

void Camera::processCamMovement(GLFWwindow* window, double deltaTime)
{
	speed = 3.0f * (float)deltaTime;

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		position += speed * front;
	}

	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		position -= speed * front;
	}

	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		position -= glm::normalize(glm::cross(front, up)) * speed;
	}

	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		position += glm::normalize(glm::cross(front, up)) * speed;
	}

	if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		position += speed * up;
	}

	if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		position -= speed * up;
	}


	updateVectors();
}
