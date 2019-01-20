#include "Shader.hpp"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

Shader::Shader(const char* vSource, const char* fSource)
{
	// Compile vertex shader
	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vSource, 0);
	glCompileShader(vertex);

	// Check compilation status
	int compiled;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &compiled);
	if(compiled != GL_TRUE)
	{
		int log_length = 0;
		char message[1024];
		glGetShaderInfoLog(vertex, 1024, &log_length, message);
		std::cout << "Failed to compile vertex shader!\n" << message << "\n";
	}

	// Compile fragment shader
	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fSource, 0);
	glCompileShader(fragment);

	// Check compilation status
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &compiled);
	if(compiled != GL_TRUE)
	{
		int log_length = 0;
		char message[1024];
		glGetShaderInfoLog(fragment, 1024, &log_length, message);
		std::cout << "Failed to compile fragment shader!\n" << message << "\n";
	}

	// Create and link the program
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);
	glLinkProgram(m_ID);

	// Clean up the remaining shaders
	glDetachShader(m_ID, vertex);
	glDetachShader(m_ID, fragment);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	// The order of uniform names 
	m_uniforms = {
		"model",
		"projection",
		"view",
		"tex"
	};
}

Shader::~Shader()
{
	glDeleteProgram(m_ID);
}

void Shader::use()
{
	glUseProgram(m_ID);
}

void Shader::stopUsing()
{
	glUseProgram(0);
}

void Shader::findUniformLocations()
{
	// Find all uniform locations
	for(auto& uni : m_uniforms)
	{
		m_uniformLocations.push_back(glGetUniformLocation(m_ID, uni.c_str()));
	}
}

void Shader::setInt(int index, int value)
{
	glUniform1i(m_uniformLocations[index], value);
}

void Shader::setMat4(int index, const glm::mat4 & value)
{
	glUniformMatrix4fv(m_uniformLocations[index], 1, GL_FALSE, glm::value_ptr(value));
}