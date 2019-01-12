#include <glad/glad.h>
#include "Camera/Camera.h"
#include "RM/ResourceManager.h"
#include "Display/Display.h"
#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main()
{
	// Window creation
	Display display(WIDTH, HEIGHT);

	// Shader
	Shader shader = RM::loadShader("C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockV.glsl", "C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockF.glsl");

	// Camera initialization
	Camera cam(WIDTH, HEIGHT);

	std::vector<float> vexPositions
	{
		//Back
		0.5, -0.5, -0.5,
		-0.5, -0.5, -0.5,
		-0.5, 0.5, -0.5,
		0.5, 0.5, -0.5,

		//Front
		-0.5, -0.5, 0.5,
		0.5, -0.5, 0.5,
		0.5, 0.5, 0.5,
		-0.5, 0.5, 0.5,

		//Right
		0.5, -0.5, 0.5,
		0.5, -0.5, -0.5,
		0.5, 0.5, -0.5,
		0.5, 0.5, 0.5,

		//Left
		-0.5, -0.5, -0.5,
		-0.5, -0.5, 0.5,
		-0.5, 0.5, 0.5,
		-0.5, 0.5, -0.5,

		//Top
		-0.5, 0.5, 0.5,
		0.5, 0.5, 0.5,
		0.5, 0.5, -0.5,
		-0.5, 0.5, -0.5,

		//Bottom
		-0.5, -0.5, -0.5,
		0.5, -0.5, -0.5,
		0.5, -0.5, 0.5,
		-0.5, -0.5, 0.5
	};

	std::vector<unsigned int> indices
	{
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	std::vector<float> texPositions
	{
		// Back
		0.25f, 0.75f,
		0.5f, 0.75f,
		0.5f, 1.0f,
	    0.25f, 1.0f,
		// Front
		0.25f, 0.75f,
		0.5f, 0.75f,
		0.5f, 1.0f,
		0.25f, 1.0f,
		// Right
		0.25f, 0.75f,
		0.5f, 0.75f,
		0.5f, 1.0f,
		0.25f, 1.0f,
		// Left
		0.25f, 0.75f,
		0.5f, 0.75f,
		0.5f, 1.0f,
		0.25f, 1.0f,
		// Top
		0.0f, 0.75f,
		0.25f, 0.75f,
		0.25f, 1.0f,
		0.0f, 1.0f,
		// Bottom
		0.5f, 0.75f,
		0.75f, 0.75f,
		0.75f, 1.0f,
		0.5f, 1.0f,
	};

	Texture textureAtlas = RM::loadTexture("C:/dev/GitHub/mc-clone/mc-clone/res/images/simple.png");

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Passing in vertex positions
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vexPositions.size() * sizeof(float), vexPositions.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Indices
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	// Texture coordinates
	unsigned int tVBO;
	glGenBuffers(1, &tVBO);
	glBindBuffer(GL_ARRAY_BUFFER, tVBO);
	glBufferData(GL_ARRAY_BUFFER, texPositions.size() * sizeof(float), texPositions.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	// Clean up
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &tVBO);

	// Get uniform locations
	std::vector<std::string> uniforms
	{
		"model",
		"projection",
		"view",
		"tex"
	};

	shader.use();
	shader.findUniformLocations(uniforms);
	shader.setInt(TEX, 0);

	// Render loop
	while(display.isOpen())
	{
		// Delta time calculation
		display.calcDelta(glfwGetTime());

		// Clearing the window
		display.clear();

		cam.processCamMovement(display.window, display.deltaTime);

		// Setting up matrices
		glm::mat4 model(1.0);
		model = glm::rotate(model, (float)glfwGetTime() / 2.0f, { 0.0f, 1.0f, 0.0f });
		shader.setMat4(MODEL, model);
		shader.setMat4(PROJECTION, cam.projMatrix);
		shader.setMat4(VIEW, cam.viewMatrix);

		textureAtlas.bind();

		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glDrawElements(GL_TRIANGLES, (int)indices.size(), GL_UNSIGNED_INT, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		textureAtlas.unbind();

		display.update();
	}

	glfwTerminate();
	return 0;
}

