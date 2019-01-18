#pragma once
#include "../RM/ResourceManager.hpp"
#include "../Camera/Camera.hpp"
#include "../Mesh/Mesh.hpp"
#include "../Entity/Entity.hpp"

class ChunkRenderer
{
private:
	Shader m_shader = RM::loadShader("C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockV.glsl", "C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockF.glsl");
	Texture m_atlas = RM::loadTexture("C:/dev/GitHub/mc-clone/mc-clone/res/images/simple.png");
	Camera* m_cam;

	Mesh m_chunk;

	std::vector<Entity> m_entities;

public:
	ChunkRenderer(Camera* cam);

	void render();

	void add(const Entity& entity);
};