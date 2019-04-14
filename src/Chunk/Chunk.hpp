#pragma once
#include "../Mesh/Mesh.hpp"
#include "../Utils/Utils.hpp"

class Chunk
{
public:
	Mesh mesh;	// All the combined block faces into a single mesh

	std::vector<uint8_t> blocks;	// All blocks stored as uint8_t

public:
	Chunk() = default;

	Chunk(const Mesh& mesh, const std::vector<uint8_t>& blocks);
};