#pragma once
#include "../Shader/Shader.hpp"
#include "../Texture/Texture.hpp"

namespace RM
{
	// Load the sourcecode from vertexPath and fragmentPath and returns
	// an already linked shader program
	Shader loadShader(const char* vertexPath, const char* fragmentPath);

	// Loads an image at location and returns an already defined
	// texture object 
	Texture loadTexture(const char* location);
}