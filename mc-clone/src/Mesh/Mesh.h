#pragma once
#include <vector>

class Mesh
{
public:
	unsigned int VAO;
	unsigned int EBO;

	int vertexCount;

private:
	std::vector<float> m_vPos;
	std::vector<unsigned int> m_indices;
	std::vector<float> m_texPos;

public:
	Mesh() {};

	Mesh(const std::vector<float>& vertexPositions, const std::vector<unsigned int>& indices, const std::vector<float>& texPositions);

	void bind();
	void unbind();
};