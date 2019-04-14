#include "Renderer.hpp"
#include "../Utils/Utils.hpp"
#include <glm/gtc/matrix_transform.hpp>

Renderer::Renderer(Camera* cam)
	: m_cam(cam)
{
	std::vector<float> vertexPositions
	{
		//Back
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,

		//Front
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f,

		//Right
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//Left
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,

		//Top
		0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		//Bottom
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f
	};

	std::vector<unsigned int> indices
	{
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	//std::vector<float> texPositions = Utils::getTexPositionsCube(GRASS);

//	m_block = Mesh(vertexPositions, indices, texPositions);

	m_shader.use();
	m_shader.findUniformLocations();
	m_shader.stopUsing();
}

void Renderer::render()
{
	m_shader.use();
	m_shader.setInt(TEX, m_atlas.index);

	m_atlas.bind();

	m_shader.setMat4(PROJECTION, m_cam->projMatrix);

	for(auto& entity : m_entities)
	{
		glm::mat4 model(1.0f);
		model = glm::translate(model, entity.position);

		m_shader.setMat4(MODEL, model);
		m_shader.setMat4(VIEW, m_cam->getViewMatrix());
		
		m_block.bind();
        glDrawElements(GL_TRIANGLES, m_block.vertexCount, GL_UNSIGNED_INT, nullptr);
		m_block.unbind();
	}

	m_atlas.unbind();
	m_shader.stopUsing();
}

void Renderer::add(const Entity& entity)
{
	m_entities.push_back(entity);
}
