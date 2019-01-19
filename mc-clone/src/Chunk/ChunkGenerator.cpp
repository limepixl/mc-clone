#include "ChunkGenerator.hpp"

ChunkGenerator::ChunkGenerator(int height)
	: m_height(height)
{}

void ChunkGenerator::generate()
{
	for(int k = 0; k < m_height; k++)
	for(int i = 0; i < CHUNK_DIMENSION; i++)
	for(int j = 0; j < CHUNK_DIMENSION; j++)
	{
		//if(k < m_height - 3)
		//	blocks.push_back(STONE);
		//else if(k < m_height - 1)
		//	blocks.push_back(DIRT);
		//else
		//	blocks.push_back(GRASS);

		blocks.push_back(BlockType(rand() % 4));
	}
}

Mesh ChunkGenerator::makeMesh()
{
	// Generate the vector of blocks for checking
	generate();

	// The mesh's data
	std::vector<float> vertexPositions;
	std::vector<unsigned int> indices;
	std::vector<float> texPositions;

	std::vector<float> frontFace
	{
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f
	};

	std::vector<float> backFace
	{
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f
	};

	std::vector<float> leftFace
	{
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f
	};

	std::vector<float> rightFace
	{
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 1.0f
	};

	std::vector<float> topFace
	{
		0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	std::vector<float> bottomFace
	{
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f
	};

	unsigned int index = 0;

	// Generate all the faces
	for(int k = 0; k < m_height; k++)
	for(int i = 0; i < CHUNK_DIMENSION; i++)
	for(int j = 0; j < CHUNK_DIMENSION; j++)
	{
		int currentPos3D = i + j * CHUNK_DIMENSION + k * CHUNK_AREA;
		int currentPos2D = currentPos3D - CHUNK_AREA * k;

		if(blocks[currentPos3D] == AIR)
		{
			continue;
		}

		// Left face
		if(currentPos2D % CHUNK_DIMENSION == 0 || blocks[currentPos3D - 1] == AIR)
		{
			std::vector<float> currentVPositions = leftFace;
			currentVPositions[0] += i;	   currentVPositions[1] += k;		currentVPositions[2] += j;
			currentVPositions[3] += i;	   currentVPositions[4] += k;		currentVPositions[5] += j;
			currentVPositions[6] += i;	   currentVPositions[7] += k;		currentVPositions[8] += j;
			currentVPositions[9] += i;	   currentVPositions[10] +=k;		currentVPositions[11] +=j;

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());

			std::vector<float> currentTexPositions = Utils::getTexPosFace(blocks[currentPos3D], Left);
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
		if(currentPos2D < CHUNK_DIMENSION || blocks[currentPos3D - CHUNK_DIMENSION] == AIR)
		{
			std::vector<float> currentVPositions = backFace;
			currentVPositions[0] += i;	   currentVPositions[1] += k;		currentVPositions[2] += j;
			currentVPositions[3] += i;	   currentVPositions[4] += k;		currentVPositions[5] += j;
			currentVPositions[6] += i;	   currentVPositions[7] += k;		currentVPositions[8] += j;
			currentVPositions[9] += i;	   currentVPositions[10] += k;		currentVPositions[11] += j;
			
			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());

			std::vector<float> currentTexPositions = Utils::getTexPosFace(blocks[currentPos3D], Back);
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
		if((currentPos3D + 1) % CHUNK_DIMENSION == 0 || blocks[currentPos3D + 1] == AIR)
		{
			std::vector<float> currentVPositions = rightFace;
			currentVPositions[0] += i;	   currentVPositions[1] += k;		currentVPositions[2] += j;
			currentVPositions[3] += i;	   currentVPositions[4] += k;		currentVPositions[5] += j;
			currentVPositions[6] += i;	   currentVPositions[7] += k;		currentVPositions[8] += j;
			currentVPositions[9] += i;	   currentVPositions[10] +=k;		currentVPositions[11] +=j;

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::vector<float> currentTexPositions = Utils::getTexPosFace(blocks[currentPos3D], Right);
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
		if(j == CHUNK_DIMENSION - 1 || blocks[currentPos3D + CHUNK_DIMENSION] == AIR)
		{
			std::vector<float> currentVPositions = frontFace;
			currentVPositions[0] += i;	   currentVPositions[1] += k;		currentVPositions[2] += j;
			currentVPositions[3] += i;	   currentVPositions[4] += k;		currentVPositions[5] += j;
			currentVPositions[6] += i;	   currentVPositions[7] += k;		currentVPositions[8] += j;
			currentVPositions[9] += i;	   currentVPositions[10] +=k;		currentVPositions[11] +=j;

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::vector<float> currentTexPositions = Utils::getTexPosFace(blocks[currentPos3D], Front);
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
		if(currentPos3D + CHUNK_AREA >= CHUNK_VOLUME || blocks[currentPos3D + CHUNK_AREA] == AIR)
		{
			std::vector<float> currentVPositions = topFace;
			currentVPositions[0] += i;	   currentVPositions[1] += k;		currentVPositions[2] += j;
			currentVPositions[3] += i;	   currentVPositions[4] += k;		currentVPositions[5] += j;
			currentVPositions[6] += i;	   currentVPositions[7] += k;		currentVPositions[8] += j;
			currentVPositions[9] += i;	   currentVPositions[10] +=k;		currentVPositions[11] +=j;

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::vector<float> currentTexPositions = Utils::getTexPosFace(blocks[currentPos3D], Top);
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
		if(k == 0 || blocks[currentPos3D - CHUNK_AREA] == AIR)
		{
			std::vector<float> currentVPositions = bottomFace;
			currentVPositions[0] += i;	  currentVPositions[1] += k;	currentVPositions[2] += j;
			currentVPositions[3] += i;	  currentVPositions[4] += k;	currentVPositions[5] += j;
			currentVPositions[6] += i;	  currentVPositions[7] += k;	currentVPositions[8] += j;
			currentVPositions[9] += i;	  currentVPositions[10] +=k;   currentVPositions[11] += j;

			vertexPositions.insert(vertexPositions.end(), currentVPositions.begin(), currentVPositions.end());
			
			std::vector<float> currentTexPositions = Utils::getTexPosFace(blocks[currentPos3D], Bottom);
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

	return Mesh(vertexPositions, indices, texPositions);
}
