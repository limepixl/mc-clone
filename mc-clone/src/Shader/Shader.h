#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <string>

enum UniformLocations
{
	MODEL,
	PROJECTION,
	VIEW,
	TEX
};

class Shader
{
private:
	std::vector<int> m_uniformLocations;
	//std::vector<std::string> m_uniforms;
public:
	unsigned int ID;

	Shader(const char* vertexSource, const char* fragmentSource);

	~Shader();

	void use();
	void stopUsing();

	void setInt(int index, int value);
	void setMat4(int index, const glm::mat4& value);

	void findUniformLocations(const std::vector<std::string>& locations);
};