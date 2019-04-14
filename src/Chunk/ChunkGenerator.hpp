#pragma once
#include <vector>
#include <array>
#include "../Utils/Utils.hpp"
#include "../Mesh/Mesh.hpp"
#include <stdint.h>

class ChunkGenerator
{
private:
	// All blocks stored as uint8_t (analogous to BlockType)
	std::vector<uint8_t> m_blocks;

	// Height of each chunk
	int m_height;

	// Default chunk data
    int chunk_dimension = 16; // n*n
    int chunk_area = chunk_dimension * chunk_dimension;
    int chunk_volume = chunk_dimension * chunk_dimension * m_height;

public:
	ChunkGenerator() = default;

	ChunkGenerator(int height);

	// Generates a vector of blocks
	void generate();

	// Generates a random vector of blocks
	void generateRandom();
	
	// Creates the chunk from the array of blocks
	class Chunk makeChunk();

private:
	// Convenience function to offset vertex positions to actual positions depending 
	// on the current position in 3D space
	void translateVertices(std::array<float, 12>& vertices, int x, int y, int z);
};
