#pragma once

// Class that represents a texture object
class Texture
{
public:
	// Index of image as a texture unit
    int index;

private:
	// Dimensions and format of image
	int m_width;
	int m_height;
	int m_channels;

	unsigned int m_ID;	// Texture object

public:
    Texture(unsigned char* data, int index, int width, int height, int channels);

	// Bind or unbind texture
	void bind();
	void unbind();
};
