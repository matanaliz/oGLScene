#include "Mesh.h"

Mesh::Mesh():
	m_vao(std::make_shared<VertexArrayObject>()),
	m_vbos(),
	m_indexBuffer(nullptr)
{
	m_vao->generate();
}

Mesh::~Mesh()
{
	m_vao->release();
	for(auto vbo: m_vbos)
		vbo->release();
	if(m_indexBuffer)
		m_indexBuffer->release();
}

void Mesh::addVertexBuffer(SimpleVertexBufferObjectPtr vbo, int location)
{
	m_vbos.push_back(vbo);
	m_vao->bindVertexBuffer(vbo.get(), location);
}

void Mesh::addIndexBuffer(IndexesVertexBufferObjectPtr indexBuffer)
{
	m_indexBuffer = indexBuffer;
	m_vao->bindIndexBuffer(indexBuffer.get());
}

const IndexesVertexBufferObjectPtr Mesh::getIndexesObject() const
{
	return m_indexBuffer;
}

const VertexArrayObjectPtr Mesh::getVertexArrayObject() const
{
	return m_vao;
}

void Mesh::use() const
{
	for(auto vbo: m_vbos)
		vbo->use();
}

void Mesh::unUse() const
{
}

