#include "Texture.h"
#include <glad/glad.h>

Texture::Texture(unsigned char* data, unsigned int index, int width, int height, int channels)
	: m_index(index), width(width), height(height), channels(channels)
{
	// Texture creation
	glGenTextures(1, &ID);

	bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	unbind();
}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0 + m_index);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unbind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
}