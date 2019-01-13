#pragma once
#include <vector>

enum BlockType
{
	GRASS,
	STONE,
	WATER,
	BEDROCK
};

namespace Utils
{
	std::vector<float> getTexPositions(BlockType type);
}