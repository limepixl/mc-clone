#include "Utils.h"

std::vector<float> Utils::getTexPositions(BlockType type)
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

	case 2:
		return std::vector<float>
		{
			// Back
			0.0f, 0.25f,
			0.25f, 0.25f,
			0.25f, 0.5f,
			0.0f, 0.5f,
			// Front
			0.0f, 0.25f,
			0.25f, 0.25f,
			0.25f, 0.5f,
			0.0f, 0.5f,
			// Right
			0.0f, 0.25f,
			0.25f, 0.25f,
			0.25f, 0.5f,
			0.0f, 0.5f,
			// Left
			0.0f, 0.25f,
			0.25f, 0.25f,
			0.25f, 0.5f,
			0.0f, 0.5f,
			// Top
			0.0f, 0.25f,
			0.25f, 0.25f,
			0.25f, 0.5f,
			0.0f, 0.5f,
			// Bottom
			0.0f, 0.25f,
			0.25f, 0.25f,
			0.25f, 0.5f,
			0.0f, 0.5f
		};

	case 3:
		return std::vector<float>
		{
			// Back
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,
			// Front
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,
			// Right
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,
			// Left
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,
			// Top
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f,
			// Bottom
			0.0f, 0.5f,
			0.25f, 0.5f,
			0.25f, 0.75f,
			0.0f, 0.75f
		};

	default:
		return std::vector<float>();
		break;
	}
}
