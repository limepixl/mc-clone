#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Camera/Camera.h"
#include "RM/ResourceManager.h"
#include <iostream>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

// Translates full texture coordinates into coordinates in normalized space
std::vector<float> normalizeTexCoordinates(std::vector<int>& texCoordinates, int imageWidth, int imageHeight)
{
	std::vector<float> normalized;
	normalized.reserve(texCoordinates.size());

	for(int i = 0; i <= texCoordinates.size() - 2; i += 2)
	{
		normalized.push_back(texCoordinates[i] / (float)imageWidth);
		normalized.push_back(texCoordinates[i + 1] / (float)imageHeight);
	}

	return normalized;
}

int main()
{
	// GLFW init	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window and context creation
	GLFWwindow* window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
	if(window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// GLAD init
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, WIDTH, HEIGHT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

	// Shader
	Shader shader = RM::loadShader("C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockV.glsl", "C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockF.glsl");

	// Camera initialization
	Camera cam(WIDTH, HEIGHT);

	// NOTE: Display func.
	double deltaTime = 0.0;
	double lastFrame = 0.0;
	// END

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

	std::vector<int> texPositionsInteger
	{
		// Back
		96, 480,
		128, 480,
		128, 512,
		96, 512,
		// Front
		96, 480,
		128, 480,
		128, 512,
		96, 512,
		// Right
		96, 480,
		128, 480,
		128, 512,
		96, 512,
		// Left
		96, 480,
		128, 480,
		128, 512,
		96, 512,
		// Top
		64, 480,
		96, 480,
		96, 512,
		64, 512,
		// Bottom
		352, 448,
		384, 448,
		384, 480,
		352, 480
	};

	// Texture creation
	unsigned int texture;
	glGenTextures(1, &texture);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Image loading
	int x, y, channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("C:/dev/GitHub/mc-clone/mc-clone/res/images/minecraft.png", &x, &y, &channels, 4);
	if(data == nullptr)
	{
		std::cout << "Failed to load image!\n";
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);

	// Get normalized texture coordinates
	std::vector<float> texPositions = normalizeTexCoordinates(texPositionsInteger, x, y);

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
	while(!glfwWindowShouldClose(window))
	{
		// Delta time calculation
		double currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cam.processCamMovement(window, deltaTime);

		// Setting up matrices
		glm::mat4 model(1.0);
		model = glm::rotate(model, (float)glfwGetTime() / 2.0f, { 0.0f, 1.0f, 0.0f });
		shader.setMat4(MODEL, model);
		shader.setMat4(PROJECTION, cam.projMatrix);
		shader.setMat4(VIEW, cam.viewMatrix);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glDrawElements(GL_TRIANGLES, (int)indices.size(), GL_UNSIGNED_INT, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

