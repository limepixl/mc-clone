#pragma once
#include "../Camera/Camera.h"
#include "../RM/ResourceManager.h"
#include "../Entity/Entity.h"
#include "../Mesh/Mesh.h"

class Renderer
{
private:
	Shader m_shader = RM::loadShader("C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockV.glsl", "C:/dev/GitHub/mc-clone/mc-clone/res/shaders/blockF.glsl");
	Texture m_atlas = RM::loadTexture("C:/dev/GitHub/mc-clone/mc-clone/res/images/simple.png");
	Camera* m_cam;

	Mesh m_block;

	std::vector<Entity> m_entities;

public:
	Renderer(Camera* cam);

	void render();

	void add(const Entity& entity);
};