#pragma once
#include <vector>

enum BlockType
{
	GRASS,
	DIRT,
	STONE,
	AIR
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