#include "ChunkRenderer.hpp"
#include <glm/gtc/matrix_transform.hpp>

ChunkRenderer::ChunkRenderer(Camera* cam)
	: m_cam(cam)
{
	// Setup
	m_shader.use();
	m_shader.findUniformLocations();
	m_shader.setInt(TEX, m_atlas.index);
	m_shader.setMat4(PROJECTION, m_cam->projMatrix);
	m_shader.stopUsing();
}

void ChunkRenderer::render()
{
	m_shader.use();
	m_atlas.bind();

	for(int i = 0; i < m_entities.size(); i++)
	{
		glm::mat4 model(1.0f);
		model = glm::translate(model, m_entities[i].position);

		m_shader.setMat4(MODEL, model);
		m_shader.setMat4(VIEW, m_cam->getViewMatrix());

		m_chunks[i].mesh.bind();
		glDrawElements(GL_TRIANGLES, m_chunks[i].mesh.vertexCount, GL_UNSIGNED_INT, 0);
		m_chunks[i].mesh.unbind();
	}
}

void ChunkRenderer::add(const Entity& entity)
{
	m_entities.push_back(entity);
}

void ChunkRenderer::initialize()
{
	for(auto& entity : m_entities)
	{
		m_chunks.push_back(m_generator.makeChunk());
	}
}
