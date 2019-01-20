#pragma once
#include "../RM/ResourceManager.hpp"
#include "../Camera/Camera.hpp"
#include "../Chunk/Chunk.hpp"
#include "../Entity/Entity.hpp"
#include "../Chunk/ChunkGenerator.hpp"

class ChunkRenderer
{
private:
	// Default block shader with very basic texture usage and no transparency
	Shader m_shader = RM::loadShader("C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockV.glsl", "C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockF.glsl");

	// Texture atlas 
	Texture m_atlas = RM::loadTexture("C:/dev/GitHub/mc-clone/mc-clone/res/images/simple64x64.png");

	// Camera for getting the necessary values
	Camera* m_cam;

	// All chunks that the renderer needs to draw
	std::vector<Chunk> m_chunks;

	// All positions the renderer needs to draw the chunks at
	std::vector<Entity> m_entities;

	// Generator used for chunk generation (starting height at 16 blocks)
	ChunkGenerator m_generator = ChunkGenerator(16);

public:
	ChunkRenderer(Camera* cam);

	// Render all of the chunks 
	void render();

	// Add an entity to the draw queue
	void add(const Entity& entity);

	// Populate the vector of chunks with newly generated chunks
	// for each entity in m_entities
	void populate();
};