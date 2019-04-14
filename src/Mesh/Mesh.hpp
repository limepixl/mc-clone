#pragma once
#include <vector>

class Mesh
{
public:
	unsigned int VAO;	// Vertex array object
	unsigned int EBO;	// Index/element buffer object

    size_t vertexCount;

private:
	// All of the mesh's data: vertex positions,
	// indices and texture coordinates
	std::vector<float> m_vPos;
	std::vector<unsigned int> m_indices;
	std::vector<float> m_texPos;

public:
	Mesh() = default;

	Mesh(const std::vector<float>& vertexPositions, const std::vector<unsigned int>& indices, const std::vector<float>& texPositions);

	// Bind and unbind the VAO and EBO
	void bind();
	void unbind();
};
