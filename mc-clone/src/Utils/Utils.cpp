#include "Utils.hpp"

std::vector<float> Utils::getTexPositionsCube(BlockType type)
{
	switch(type)
	{
	case 0:
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

	case 1:
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

	case 2:
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

	default:
		return std::vector<float>();
	}
}

std::vector<float> Utils::getTexPosFace(BlockType type, Side side)
{
	switch(type)
	{
	case 0:
		if(side == Top)
		{
			return std::vector<float>
			{
				0.0f, 0.75f,
				0.25f, 0.75f,
				0.25f, 1.0f,
				0.0f, 1.0f
			};
		} else if(side == Bottom)
		{
			return std::vector<float>
			{
				0.5f, 0.75f,
				0.75f, 0.75f,
				0.75f, 1.0f,
				0.5f, 1.0f
			};
		} else
		{
			return std::vector<float>
			{
				0.25f, 0.75f,
				0.5f, 0.75f,
				0.5f, 1.0f,
				0.25f, 1.0f
			};
		}

	case 1:
		return std::vector<float>
		{
			0.5f, 0.75f,
			0.75f, 0.75f,
			0.75f, 1.0f,
			0.5f, 1.0f
		};

	case 2:
		return std::vector<float>
		{
			0.75f, 0.75f,
			1.0f, 0.75f,
			1.0f, 1.0f,
			0.75f, 1.0f
		};

	case 3:
		return std::vector<float>();

	default:
		return std::vector<float>();
	}
}
