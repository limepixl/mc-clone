#pragma once
#include <array>
#include <vector>

// Enum that stores values for all blocks possible
// to get a texture for, from the atlas
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

// Enum that stores all possible sides for each block
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
	// Return texture coordinates for a single side of a block type
	std::array<float, 8> getTexPosFace(BlockType type, Side side);
}