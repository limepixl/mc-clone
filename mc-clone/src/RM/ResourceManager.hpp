#pragma once
#include "../Shader/Shader.hpp"
#include "../Texture/Texture.hpp"

namespace RM
{
	Shader loadShader(const char* vertexPath, const char* fragmentPath);

	Texture loadTexture(const char* location);
}