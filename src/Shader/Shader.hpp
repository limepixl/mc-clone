#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <string>

// Enum for ease of use in
// setting uniform values
enum UniformLocations
{
	MODEL,
	PROJECTION,
	VIEW,
	TEX
};

// Shader class that stores an already linked
// shader program, using vertex and fragment shaders
class Shader
{
private:
	unsigned int m_ID;	// Final shader program id

	// Vector of found uniform locations
	std::vector<int> m_uniformLocations;

	// Uniform variable names used for finding locations
	std::vector<std::string> m_uniforms;

public:
	Shader(const char* vertexSource, const char* fragmentSource);

	~Shader();

	// Use or stop using a shader program
	void use();
	void stopUsing();

	// Pass in values at the uniform location
	void setInt(int index, int value);
	void setMat4(int index, const glm::mat4& value);

	// Find all uniform locations for later use
	// instead of querying each location each time
	// a uniform needs to be set
	void findUniformLocations();
};