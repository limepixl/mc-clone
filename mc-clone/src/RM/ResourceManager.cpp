#include "ResourceManager.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace RM
{
	int numTexturesLoaded = 0;

	Shader loadShader(const char* vertexPath, const char* fragmentPath)
	{
		std::ifstream vRaw, fRaw;
		vRaw.open(vertexPath);
		fRaw.open(fragmentPath);

		std::stringstream vStream, fStream;
		vStream << vRaw.rdbuf();
		fStream << fRaw.rdbuf();

		vRaw.close();
		fRaw.close();

		std::string vString, fString;
		vString = vStream.str();
		fString = fStream.str();

		const char* vSource = vString.c_str();
		const char* fSource = fString.c_str();

		return Shader(vSource, fSource);
	}

	Texture loadTexture(const char * location)
	{
		// Image loading
		int x, y, channels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(location, &x, &y, &channels, 4);
		if(data == nullptr)
		{
			std::cout << "Failed to load image!\n";
		}
		Texture t(data, numTexturesLoaded++, x, y, channels);

		stbi_image_free(data);
		return t;
	}
}
