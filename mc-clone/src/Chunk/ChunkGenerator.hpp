#pragma once
#include <vector>
#include "../Utils/Utils.hpp"
#include "../Mesh/Mesh.hpp"
#include <stdint.h>

class ChunkGenerator
{
public:
	std::vector<uint8_t> blocks;

private:
	int m_height;

	// Default chunk data
	int chunk_dimension = 16; // n*n
	int chunk_area = chunk_dimension * chunk_dimension;
	int chunk_volume = chunk_dimension * chunk_dimension * m_height;

public:
	ChunkGenerator() = default;

	ChunkGenerator(int height);

	// Generates an array of blocks
	void generate();
	
	// Creates the chunk's mesh
	class Chunk makeChunk();

private:
	void translateVertices(std::vector<float>& vertices, int x, int y, int z);
};