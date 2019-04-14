#include "ChunkRenderer.hpp"
#include <glm/gtc/matrix_transform.hpp>

ChunkRenderer::ChunkRenderer(Camera* cam)
	: m_cam(cam)
{
	// Setup of uniforms that need to be set once
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

	// Go through each chunk and translate it to the
	// corresponding entity position
    for(size_t i = 0; i < m_entities.size(); i++)
	{
		// The current chunk's mesh
		auto& currentMesh = m_chunks[i].mesh;

		glm::mat4 model(1.0f);
		model = glm::translate(model, m_entities[i].position);

		m_shader.setMat4(MODEL, model);
		m_shader.setMat4(VIEW, m_cam->getViewMatrix());

		currentMesh.bind();
        glDrawElements(GL_TRIANGLES, currentMesh.vertexCount, GL_UNSIGNED_INT, nullptr);
		currentMesh.unbind();
	}
}

void ChunkRenderer::add(const Entity& entity)
{
	m_entities.push_back(entity);
}

void ChunkRenderer::populate()
{
    for(size_t i = 0; i < m_entities.size(); i++)
	{
		m_chunks.push_back(m_generator.makeChunk());
	}
}
