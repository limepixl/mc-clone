#include "ChunkGenerator.hpp"
#include "Chunk.hpp"
#include <random>
#include <time.h>

ChunkGenerator::ChunkGenerator(int height)
	: m_height(height)
{
	std::srand(time(0)); // Seeding the rand function
}

void ChunkGenerator::generate()
{
	// If there is a chunk already generated, delete its blocks
	if(!m_blocks.empty())
	{
		m_blocks.erase(m_blocks.begin(), m_blocks.end());
	}

	// Generate blocks in a vector based on conditions
	for(int k = 0; k < m_height; k++)
	for(int i = 0; i < chunk_dimension; i++)
	for(int j = 0; j < chunk_dimension; j++)
	{
		// First layer grass, 2 below dirt, 
		// rest stone except last layer which is bedrock
		if(k == 0)
			m_blocks.push_back(BEDROCK);
		else if(k > 0 && k < m_height - 3)
			m_blocks.push_back(STONE);
		else if(k >= m_height - 3 && k < m_height - 1)
			m_blocks.push_back(DIRT);
		else
			m_blocks.push_back(GRASS);
	}
}

void ChunkGenerator::generateRandom()
{
	// If there is a chunk already generated, delete its blocks
	if(!m_blocks.empty())
	{
		m_blocks.erase(m_blocks.begin(), m_blocks.end());
	}

	// Generate blocks in a vector based on conditions
	for(int k = 0; k < m_height; k++)
		for(int i = 0; i < chunk_dimension; i++)
			for(int j = 0; j < chunk_dimension; j++)
			{
				m_blocks.push_back(BlockType(rand() % 9));
			}
}

Chunk ChunkGenerator::makeChunk()
{
	// Generate the vector of blocks for checking
	generate();

	// Use randomized blocks
	// generateRandom();

	// The mesh's data
	std::vector<float> vertexPositions;
	std::vector<unsigned int> indices;
	std::vector<float> texPositions;

	// Each face's coordinates ////////
	std::array<float, 12> frontFace	 //
	{								 //
		0.0f, 0.0f, 1.0f,			 //
		1.0f, 0.0f, 1.0f,			 //
		1.0f, 1.0f, 1.0f,			 //
		0.0f, 1.0f, 1.0f			 //
	};								 //
									 //
	std::array<float, 12> backFace	 //
	{								 //
		1.0f, 0.0f, 0.0f,			 //
		0.0f, 0.0f, 0.0f,			 //
		0.0f, 1.0f, 0.0f,			 //
		1.0f, 1.0f, 0.0f			 //
	};								 //
									 //
	std::array<float, 12> leftFace	 //
	{								 //
		0.0f, 0.0f, 0.0f,			 //
		0.0f, 0.0f, 1.0f,			 //
		0.0f, 1.0f, 1.0f,			 //
		0.0f, 1.0f, 0.0f			 //
	};								 //
									 //
	std::array<float, 12> rightFace	 //
	{								 //
		1.0f, 0.0f, 1.0f,			 //
		1.0f, 0.0f, 0.0f,			 //
		1.0f, 1.0f, 0.0f,			 //
		1.0f, 1.0f, 1.0f			 //
	};								 //
									 //
	std::array<float, 12> topFace	 //
	{								 //
		0.0f, 1.0f, 1.0f,			 //
		1.0f, 1.0f, 1.0f,			 //
		1.0f, 1.0f, 0.0f,			 //
		0.0f, 1.0f, 0.0f			 //
	};								 //
									 //
	std::array<float, 12> bottomFace //
	{								 //
		0.0f, 0.0f, 0.0f,			 //
		1.0f, 0.0f, 0.0f,			 //
		1.0f, 0.0f, 1.0f,			 //
		0.0f, 0.0f, 1.0f			 //
	};								 //
	///////////////////////////////////

	// Index value that is used for
	// the vertex indices
	unsigned int index = 0;

	// Generate all the faces
	for(int k = 0; k < m_height; k++)
	for(int i = 0; i < chunk_dimension; i++)
	for(int j = 0; j < chunk_dimension; j++)
	{
		// Current position in the vector indexed as 1D from 3D
		int currentPos3D = i + j * chunk_dimension + k * chunk_area;

		// Current position in the vector containing a single
		// layer (y coordinate) for local comparisons
		int currentPos2D = currentPos3D - chunk_area * k;

		// If the current block is air then move to the next block
		if(m_blocks[currentPos3D] == AIR)
		{
			continue;
		}

		// Left face
		if(currentPos2D % chunk_dimension == 0 || m_blocks[currentPos3D - 1] == AIR)
		{
			// Moving positions to actual position instead of at 0, 0, 0
			// based on the current 3D position
			std::array<float, 12> currentVPositions = leftFace;
			translateVertices(currentVPositions, i, k, j);

			// Inserting the appropriate face's coordinates into the final mesh's vertex positions vector
			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());

			// Getting appropriate texture coordinates and adding them to the final mesh's tex coordinates
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(m_blocks[currentPos3D]), Left);
			texPositions.insert(texPositions.end(), currentTexPositions.begin(), currentTexPositions.end());

			// Adding indices (order of vertices) to final mesh's indices
			std::vector<unsigned int> i
			{
				index, index + 1, index + 2,
				index + 2, index + 3, index + 0
			};
			indices.insert(indices.end(), i.begin(), i.end());

			index += 4;
		}
		// (Above comments apply for all faces)

		// Back face
		if(currentPos2D < chunk_dimension || m_blocks[currentPos3D - chunk_dimension] == AIR)
		{
			std::array<float, 12> currentVPositions = backFace;
			translateVertices(currentVPositions, i, k, j);
			
			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());

			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(m_blocks[currentPos3D]), Back);
			texPositions.insert(texPositions.end(), currentTexPositions.begin(), currentTexPositions.end());

			std::vector<unsigned int> i
			{
				index, index + 1, index + 2,
				index + 2, index + 3, index + 0
			};
			indices.insert(indices.end(), i.begin(), i.end());

			index += 4;
		}

		// Right face
		if((currentPos3D + 1) % chunk_dimension == 0 || m_blocks[currentPos3D + 1] == AIR)
		{
			std::array<float, 12> currentVPositions = rightFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(m_blocks[currentPos3D]), Right);
			texPositions.insert(texPositions.end(), currentTexPositions.begin(), currentTexPositions.end());

			std::vector<unsigned int> i
			{
				index, index + 1, index + 2,
				index + 2, index + 3, index + 0
			};
			indices.insert(indices.end(), i.begin(), i.end());

			index += 4;
		}

		// Front face
		if(j == chunk_dimension - 1 || m_blocks[currentPos3D + chunk_dimension] == AIR)
		{
			std::array<float, 12> currentVPositions = frontFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(m_blocks[currentPos3D]), Front);
			texPositions.insert(texPositions.end(), currentTexPositions.begin(), currentTexPositions.end());

			std::vector<unsigned int> i
			{
				index, index + 1, index + 2,
				index + 2, index + 3, index + 0
			};
			indices.insert(indices.end(), i.begin(), i.end());

			index += 4;
		}

		// Top face
		if(currentPos3D + chunk_area >= chunk_volume || m_blocks[currentPos3D + chunk_area] == AIR)
		{
			std::array<float, 12> currentVPositions = topFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(m_blocks[currentPos3D]), Top);
			texPositions.insert(texPositions.end(), currentTexPositions.begin(), currentTexPositions.end());

			std::vector<unsigned int> i
			{
				index, index + 1, index + 2,
				index + 2, index + 3, index + 0
			};
			indices.insert(indices.end(), i.begin(), i.end());

			index += 4;
		}

		// Bottom face
		if(k == 0 || m_blocks[currentPos3D - chunk_area] == AIR)
		{
			std::array<float, 12> currentVPositions = bottomFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(m_blocks[currentPos3D]), Bottom);
			texPositions.insert(texPositions.end(), currentTexPositions.begin(), currentTexPositions.end());

			std::vector<unsigned int> i
			{
				index, index + 1, index + 2,
				index + 2, index + 3, index + 0
			};
			indices.insert(indices.end(), i.begin(), i.end());

			index += 4;
		}
	}

	// Get a slightly randomized height for each chunk
	m_height = rand() % 5 + 11;
	chunk_volume = chunk_area * m_height;

	return Chunk({vertexPositions, indices, texPositions}, m_blocks);
}

void ChunkGenerator::translateVertices(std::array<float, 12>& vertices, int x, int y, int z)
{
	for(int i = 0; i < 12; i++)
	{
		int coordinate = i % 3;
		if(coordinate == 0)
			vertices[i] += x;
		else if(coordinate == 1)
			vertices[i] += y;
		else
			vertices[i] += z;
	}
}
