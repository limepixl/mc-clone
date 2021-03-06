#pragma once
#include "../Camera/Camera.hpp"
#include "../RM/ResourceManager.hpp"
#include "../Entity/Entity.hpp"
#include "../Mesh/Mesh.hpp"

// Unused block renderer
class Renderer
{
private:
    Shader m_shader = RM::loadShader("../mc-clone/res/shaders/blockV.glsl", "C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockF.glsl");
    Texture m_atlas = RM::loadTexture("../mc-clone/res/images/simple.png");
	Camera* m_cam;

	Mesh m_block;

	std::vector<Entity> m_entities;

public:
	Renderer(Camera* cam);

	void render();

	void add(const Entity& entity);
};
