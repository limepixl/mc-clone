#pragma once
#include <glm/glm.hpp>

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexSource, const char* fragmentSource);

	~Shader();

	void use();

	void setInt(int location, int value);
	void setMat4(int location, const glm::mat4& value);

	int getUniformLocation(const char* location);
};