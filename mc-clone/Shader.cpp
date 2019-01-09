#include "Shader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::ifstream vRaw, fRaw;
	vRaw.open(vertexPath);
	fRaw.open(fragmentPath);

	std::stringstream vSource, fSource;
	vSource << vRaw.rdbuf();
	fSource << fRaw.rdbuf();

	vRaw.close();
	fRaw.close();

	std::string vString, fString;
	vString = vSource.str();
	fString = fSource.str();

	m_vSource = vString.c_str();
	m_fSource = fString.c_str();

	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &m_vSource, 0);
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
	glShaderSource(fragment, 1, &m_fSource, 0);
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

void Shader::setInt(const char* location, int value)
{
	int loc = glGetUniformLocation(ID, location);
	glUniform1i(loc, value);
}
