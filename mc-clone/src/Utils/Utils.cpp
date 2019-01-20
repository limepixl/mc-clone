#include "Utils.hpp"

std::array<float, 8> Utils::getTexPosFace(BlockType type, Side side)
{
	switch(type)
	{
	case GRASS:
		switch(side)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			return std::array<float, 8>
			{
				0.25f, 0.75f,
				0.5f, 0.75f,
				0.5f, 1.0f,
				0.25f, 1.0f
			};

		case 4:
			return std::array<float, 8>
			{
				0.0f, 0.75f,
				0.25f, 0.75f,
				0.25f, 1.0f,
				0.0f, 1.0f
			};

		case 5:
			return std::array<float, 8>
			{
				0.5f, 0.75f,
				0.75f, 0.75f,
				0.75f, 1.0f,
				0.5f, 1.0f
			};
		}

	case DIRT:
		return std::array<float, 8>
		{
			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f
		};

	case STONE:
		return std::array<float, 8>
		{
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f
		};

	case BEDROCK:
		return std::array<float, 8>
		{
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f
		};

	case IRON_BLOCK:
		return std::array<float, 8>
		{
			0.0f, 0.0f,
			0.25f, 0.0f,
			0.25f, 0.25f,
			0.0f, 0.25f
		};

	case GOLD_BLOCK:
		return std::array<float, 8>
		{
			0.25f, 0.0f,
			0.5f, 0.0f,
			0.5f, 0.25f,
			0.25f, 0.25f
		};

	case DIAMOND_BLOCK:
		return std::array<float, 8>
		{
			0.5f, 0.0f,
			0.75f, 0.0f,
			0.75f, 0.25f,
			0.5f, 0.25f
		};

	case EMERALD_BLOCK:
		return std::array<float, 8>
		{
			0.75f, 0.0f,
			1.0f, 0.0f,
			1.0f, 0.25f,
			0.75f, 0.25f
		};

	default:
		return std::array<float, 8>();
	}
}
