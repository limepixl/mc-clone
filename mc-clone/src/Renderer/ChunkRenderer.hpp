#pragma once
#include "../RM/ResourceManager.hpp"
#include "../Camera/Camera.hpp"
#include "../Chunk/Chunk.hpp"
#include "../Entity/Entity.hpp"
#include "../Chunk/ChunkGenerator.hpp"

class ChunkRenderer
{
private:
	Shader m_shader = RM::loadShader("C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockV.glsl", "C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockF.glsl");
	Texture m_atlas = RM::loadTexture("C:/dev/GitHub/mc-clone/mc-clone/res/images/simple64x64.png");
	Camera* m_cam;

	std::vector<Chunk> m_chunks;

	std::vector<Entity> m_entities;

	ChunkGenerator m_generator = ChunkGenerator(4);

public:
	ChunkRenderer(Camera* cam);

	void render();

	void add(const Entity& entity);

	void initialize();
};