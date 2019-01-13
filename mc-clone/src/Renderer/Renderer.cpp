#include "Renderer.hpp"
#include <glm/gtc/matrix_transform.hpp>

// Uniform location order
std::vector<std::string> uniforms
{
	"model",
	"projection",
	"view",
	"tex"
};

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

	// TODO :: Change based on block type
	std::vector<float> texPositions
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
		0.5f, 1.0f,
	};

	m_block = Mesh(vertexPositions, indices, texPositions);

	m_shader.use();
	m_shader.findUniformLocations(uniforms);
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

		model = glm::rotate(model, glm::radians(entity.rotation.x), { 1.0f, 0.0f, 0.0f });
		model = glm::rotate(model, glm::radians(entity.rotation.y), { 0.0f, 1.0f, 0.0f });
		model = glm::rotate(model, glm::radians(entity.rotation.z), { 0.0f, 0.0f, 1.0f });

		m_shader.setMat4(MODEL, model);
		m_shader.setMat4(VIEW, m_cam->getViewMatrix());
		
		m_block.bind();
		glDrawElements(GL_TRIANGLES, m_block.vertexCount, GL_UNSIGNED_INT, 0);
		m_block.unbind();
	}

	m_atlas.unbind();
	m_shader.stopUsing();
}

void Renderer::add(const Entity& entity)
{
	m_entities.push_back(entity);
}
