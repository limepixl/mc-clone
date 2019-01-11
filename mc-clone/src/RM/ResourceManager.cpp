#include "ResourceManager.h"
#include <fstream>
#include <string>
#include <sstream>

Shader RM::loadShader(const char* vertexPath, const char* fragmentPath)
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
