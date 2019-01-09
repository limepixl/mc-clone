#pragma once
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
};