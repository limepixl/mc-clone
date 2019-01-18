#include "ChunkRenderer.hpp"
#include "../Chunk/ChunkGenerator.hpp"
#include <glm/gtc/matrix_transform.hpp>

ChunkRenderer::ChunkRenderer(Camera* cam)
	: m_cam(cam)
{
	ChunkGenerator generator(16);
	m_chunk = generator.makeMesh();

	m_shader.use();
	m_shader.findUniformLocations();
	m_shader.stopUsing();
}

void ChunkRenderer::render()
{
	m_shader.use();
	m_shader.setInt(TEX, m_atlas.index);
	m_shader.setMat4(PROJECTION, m_cam->projMatrix);

	m_atlas.bind();

	for(auto& entity : m_entities)
	{
		glm::mat4 model(1.0f);
		model = glm::translate(model, entity.position);

		m_shader.setMat4(MODEL, model);
		m_shader.setMat4(VIEW, m_cam->getViewMatrix());

		m_chunk.bind();
		glDrawElements(GL_TRIANGLES, m_chunk.vertexCount, GL_UNSIGNED_INT, 0);
		m_chunk.unbind();
	}
}

void ChunkRenderer::add(const Entity& entity)
{
	m_entities.push_back(entity);
}
