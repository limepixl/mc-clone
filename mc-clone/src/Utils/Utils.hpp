#pragma once
#include <array>
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
	std::array<float, 8> getTexPosFace(BlockType type, Side side);
}