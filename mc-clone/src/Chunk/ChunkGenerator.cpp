#include "ChunkGenerator.hpp"
#include "Chunk.hpp"

ChunkGenerator::ChunkGenerator(int height)
	: m_height(height)
{}

void ChunkGenerator::generate()
{
	// If there is a chunk already generated, delete its blocks
	if(!blocks.empty())
	{
		blocks.erase(blocks.begin(), blocks.end());
	}

	for(int k = 0; k < m_height; k++)
	for(int i = 0; i < chunk_dimension; i++)
	for(int j = 0; j < chunk_dimension; j++)
	{
		if(k == 0)
			blocks.push_back(BEDROCK);
		else if(k == 1 || k == 2)
			blocks.push_back(DIRT);
		else
			blocks.push_back(GRASS);
	}
}

Chunk ChunkGenerator::makeChunk()
{
	// Generate the vector of blocks for checking
	generate();

	// The mesh's data
	std::vector<float> vertexPositions;
	std::vector<unsigned int> indices;
	std::vector<float> texPositions;

	std::array<float, 12> frontFace
	{
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f
	};

	std::array<float, 12> backFace
	{
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f
	};

	std::array<float, 12> leftFace
	{
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f
	};

	std::array<float, 12> rightFace
	{
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 1.0f
	};

	std::array<float, 12> topFace
	{
		0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	std::array<float, 12> bottomFace 
	{
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f
	};

	unsigned int index = 0;

	// Generate all the faces
	for(int k = 0; k < m_height; k++)
	for(int i = 0; i < chunk_dimension; i++)
	for(int j = 0; j < chunk_dimension; j++)
	{
		int currentPos3D = i + j * chunk_dimension + k * chunk_area;
		int currentPos2D = currentPos3D - chunk_area * k;

		if(blocks[currentPos3D] == AIR)
		{
			continue;
		}

		// Left face
		if(currentPos2D % chunk_dimension == 0 || blocks[currentPos3D - 1] == AIR)
		{
			std::array<float, 12> currentVPositions = leftFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());

			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(blocks[currentPos3D]), Left);
			texPositions.insert(texPositions.end(), currentTexPositions.begin(), currentTexPositions.end());

			std::vector<unsigned int> i
			{
				index, index + 1, index + 2,
				index + 2, index + 3, index + 0
			};
			indices.insert(indices.end(), i.begin(), i.end());

			index += 4;
		}

		// Back face
		if(currentPos2D < chunk_dimension || blocks[currentPos3D - chunk_dimension] == AIR)
		{
			std::array<float, 12> currentVPositions = backFace;
			translateVertices(currentVPositions, i, k, j);
			
			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());

			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(blocks[currentPos3D]), Back);
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
		if((currentPos3D + 1) % chunk_dimension == 0 || blocks[currentPos3D + 1] == AIR)
		{
			std::array<float, 12> currentVPositions = rightFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(blocks[currentPos3D]), Right);
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
		if(j == chunk_dimension - 1 || blocks[currentPos3D + chunk_dimension] == AIR)
		{
			std::array<float, 12> currentVPositions = frontFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(blocks[currentPos3D]), Front);
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
		if(currentPos3D + chunk_area >= chunk_volume || blocks[currentPos3D + chunk_area] == AIR)
		{
			std::array<float, 12> currentVPositions = topFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(blocks[currentPos3D]), Top);
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
		if(k == 0 || blocks[currentPos3D - chunk_area] == AIR)
		{
			std::array<float, 12> currentVPositions = bottomFace;
			translateVertices(currentVPositions, i, k, j);

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::array<float, 8> currentTexPositions = Utils::getTexPosFace(BlockType(blocks[currentPos3D]), Bottom);
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

	//m_height = rand() % 5 + 11;
	//chunk_volume = chunk_area * m_height;

	return Chunk({vertexPositions, indices, texPositions}, blocks);
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
