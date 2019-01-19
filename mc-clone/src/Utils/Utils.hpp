#pragma once
#include <vector>

enum BlockType
{
	AIR,
	GRASS,
	DIRT,
	STONE, 
	BEDROCK,
	IRON_BLOCK,
	GOLD_BLOCK,
	DIAMOND_BLOCK,
	EMERALD_BLOCK
};

enum Side
{
	Front,
	Back,
	Right,
	Left,
	Top,
	Bottom,
};

namespace Utils
{
	std::vector<float> getTexPositionsCube(BlockType type);

	std::vector<float> getTexPosFace(BlockType type, Side side);
}