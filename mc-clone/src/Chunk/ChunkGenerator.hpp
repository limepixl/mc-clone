#pragma once
#include <vector>
#include "../Utils/Utils.hpp"
#include "../Mesh/Mesh.hpp"

class ChunkGenerator
{
public:
	std::vector<BlockType> blocks;

private:
	int m_height;

	// Default chunk data
	const int CHUNK_DIMENSION = 16; // n*n
	const int CHUNK_AREA = CHUNK_DIMENSION * CHUNK_DIMENSION;
	const int CHUNK_VOLUME = CHUNK_DIMENSION * CHUNK_DIMENSION * m_height;

public:
	ChunkGenerator() = default;

	ChunkGenerator(int height);

	// Generates an array of blocks
	void generate();
	
	// Creates the chunk's mesh
	Mesh makeMesh();

private:
	void translateVertices(std::vector<float>& vertices, int x, int y, int z);
};