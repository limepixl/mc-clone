#include "Shader.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

Shader::Shader(const char* vSource, const char* fSource)
{
	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vSource, 0);
	glCompileShader(vertex);

	int compiled;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &compiled);
	if(compiled != GL_TRUE)
	{
		int log_length = 0;
		char message[1024];
		glGetShaderInfoLog(vertex, 1024, &log_length, message);
		std::cout << "Failed to compile vertex shader!\n" << message << "\n";
	}

	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fSource, 0);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &compiled);
	if(compiled != GL_TRUE)
	{
		int log_length = 0;
		char message[1024];
		glGetShaderInfoLog(fragment, 1024, &log_length, message);
		std::cout << "Failed to compile fragment shader!\n" << message << "\n";
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setInt(int index, int value)
{
	glUniform1i(m_uniformLocations[index], value);
}

void Shader::setMat4(int index, const glm::mat4 & value)
{
	glUniformMatrix4fv(m_uniformLocations[index], 1, GL_FALSE, glm::value_ptr(value));
}

int Shader::getUniformLocation(const char* location)
{
	return glGetUniformLocation(ID, location);
}

void Shader::findUniformLocations(const std::vector<std::string>& locations)
{
	// Store the uniform order
	//m_uniforms = locations;

	// Find all uniform locations
	for(auto& loc : locations)
	{
		m_uniformLocations.push_back(glGetUniformLocation(ID, loc.c_str()));
	}
}
