#pragma once

class Texture
{
public:
	int width;
	int height;
	int channels;

	unsigned int index;

private:
	unsigned int ID;

public:
	Texture(unsigned char* data, unsigned int index, int width, int height, int channels);

	void bind();
	void unbind();
};