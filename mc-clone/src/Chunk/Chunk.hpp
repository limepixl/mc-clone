#pragma once
#include "../Mesh/Mesh.hpp"
#include "../Utils/Utils.hpp"

class Chunk
{
public:
	Mesh mesh;

	std::vector<uint8_t> blocks;

public:
	Chunk() = default;

	Chunk(const Mesh& mesh, const std::vector<uint8_t>& blocks);
};