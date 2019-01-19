#include "Utils.hpp"

std::vector<float> Utils::getTexPositionsCube(BlockType type)
{
	switch(type)
	{
	case GRASS:
		return std::vector<float>
		{
			// Back
			0.25f, 0.75f,
			0.5f, 0.75f,
			0.5f, 1.0f,
			0.25f, 1.0f,
			// Front
			0.25f, 0.75f,
			0.5f, 0.75f,
			0.5f, 1.0f,
			0.25f, 1.0f,
			// Right
			0.25f, 0.75f,
			0.5f, 0.75f,
			0.5f, 1.0f,
			0.25f, 1.0f,
			// Left
			0.25f, 0.75f,
			0.5f, 0.75f,
			0.5f, 1.0f,
			0.25f, 1.0f,
			// Top
			0.0f, 0.75f,
			0.25f, 0.75f,
			0.25f, 1.0f,
			0.0f, 1.0f,
			// Bottom
			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f
		};

	case DIRT:
		return std::vector<float>
		{
			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f,

			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f,

			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f,

			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f,

			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f,

			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f
		};

	case STONE:
		return std::vector<float>
		{
			// Back
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f,
			// Front
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f,
			// Right
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f,
			// Left
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f,
			// Top
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f,
			// Bottom
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f
		};

	case BEDROCK:
		return std::vector<float>
		{
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,

			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,

			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,

			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,

			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,

			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f
		};

	default:
		return std::vector<float>();
	}
}

std::vector<float> Utils::getTexPosFace(BlockType type, Side side)
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
			return std::vector<float>
			{
				0.25f, 0.75f,
					0.5f, 0.75f,
					0.5f, 1.0f,
					0.25f, 1.0f
			};

		case 4:
			return std::vector<float>
			{
				0.0f, 0.75f,
				0.25f, 0.75f,
				0.25f, 1.0f,
				0.0f, 1.0f
			};

		case 5:
			return std::vector<float>
			{
				0.5f, 0.75f,
				0.75f, 0.75f,
				0.75f, 1.0f,
				0.5f, 1.0f
			};
		}

	case DIRT:
		return std::vector<float>
		{
			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f
		};

	case STONE:
		return std::vector<float>
		{
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f
		};

	case BEDROCK:
		return std::vector<float>
		{
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f
		};

	case IRON_BLOCK:
		return std::vector<float>
		{
			0.0f, 0.0f,
			0.25f, 0.0f,
			0.25f, 0.25f,
			0.0f, 0.25f
		};

	case GOLD_BLOCK:
		return std::vector<float>
		{
			0.25f, 0.0f,
			0.5f, 0.0f,
			0.5f, 0.25f,
			0.25f, 0.25f
		};

	case DIAMOND_BLOCK:
		return std::vector<float>
		{
			0.5f, 0.0f,
			0.75f, 0.0f,
			0.75f, 0.25f,
			0.5f, 0.25f
		};

	case EMERALD_BLOCK:
		return std::vector<float>
		{
			0.75f, 0.0f,
			1.0f, 0.0f,
			1.0f, 0.25f,
			0.75f, 0.25f
		};

	default:
		return std::vector<float>();
	}
}
