#pragma once
#include <glm/glm.hpp>

class Shader
{
private:
	unsigned int ID;

	const char* m_vSource;
	const char* m_fSource;

public:
	Shader(const char* vertexPath, const char* fragmentPath);

	~Shader();

	void use();

	void setInt(const char* location, int value);
	void setMat4(const char* location, const glm::mat4& value);
};