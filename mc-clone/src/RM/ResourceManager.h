#pragma once
#include "../Shader/Shader.h"
#include "../Texture/Texture.h"

namespace RM
{
	Shader loadShader(const char* vertexPath, const char* fragmentPath);

	Texture loadTexture(const char* location);
}