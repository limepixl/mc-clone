#pragma once
#include <vector>

enum BlockType
{
	GRASS,
	STONE,
};

enum Side
{
	Front,
	Back,
	Right,
	Left,
	Top,
	Bottom,
	FL,
	FR,
	BL,
	BR,
};

namespace Utils
{
	std::vector<float> getTexPositionsCube(BlockType type);

	std::vector<float> getTexPositionsFace(BlockType type, Side side);
}