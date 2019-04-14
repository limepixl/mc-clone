#include "Camera.hpp"
#include "../Display/Display.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(Display* display)
	: m_display(display)
{
    projMatrix = glm::perspective(glm::radians(50.0f), static_cast<float>(display->width) / display->height, 0.1f, 1000.0f);

	position = glm::vec3(0.0);
	front = glm::vec3(0.0, 0.0, -1.0);
	right = glm::vec3(1.0, 0.0, 0.0);
	up = glm::vec3(0.0, 1.0, 0.0);

	firstMouse = true;
	yaw = -90.0f;
	pitch = 0.0f;

	lastX = display->width / 2.0f;
	lastY = display->height / 2.0f;

	mouseSens = 0.2f;
}

glm::mat4 Camera::getViewMatrix()
{
	viewMatrix = glm::lookAt(position, position + front, up);
	return viewMatrix;
}

void Camera::processCamKeyboard()
{
    speed = 10.0f * static_cast<float>(m_display->deltaTime);

	if(glfwGetKey(m_display->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		position += speed * front;
	}

	if(glfwGetKey(m_display->window, GLFW_KEY_S) == GLFW_PRESS)
	{
		position -= speed * front;
	}

	if(glfwGetKey(m_display->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		position -= glm::normalize(glm::cross(front, up)) * speed;
	}

	if(glfwGetKey(m_display->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		position += glm::normalize(glm::cross(front, up)) * speed;
	}

	if(glfwGetKey(m_display->window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		position += speed * glm::vec3(0.0f, 1.0f, 0.0f);
	}

	if(glfwGetKey(m_display->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		position -= speed * glm::vec3(0.0f, 1.0f, 0.0f);
	}
}

void Camera::processCamMouse()
{
	double xpos;
	double ypos;
	glfwGetCursorPos(m_display->window, &xpos, &ypos);

	if(firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	xoffset *= mouseSens;
	yoffset *= mouseSens;

	yaw += xoffset;
	pitch += yoffset;

	if(pitch > 89.0f)
		pitch = 89.0f;
	if(pitch < -89.0f)
		pitch = -89.0f;

	updateVectors();
}

void Camera::updateVectors()
{
	// Calculate the new front vector
	glm::vec<3, double> f;
	f.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	f.y = sin(glm::radians(pitch));
	f.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(f);

	// Also re-calculate the Right and Up vector
	right = glm::normalize(glm::cross(front, {0.0f, 1.0f, 0.0f})); 
	up = glm::normalize(glm::cross(right, front));
}

