#pragma once

class Texture
{
public:
	int width;
	int height;
	int channels;

private:
	unsigned int ID;
	unsigned int m_index;

public:
	Texture(unsigned char* data, unsigned int index, int width, int height, int channels);

	void bind();
	void unbind();
};