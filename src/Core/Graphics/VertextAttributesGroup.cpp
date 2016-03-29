#include "VertextAttributesGroup.h"
//#include "Asserts.h"


VertextAttributesGroup::VertextAttributesGroup()
{
}

void VertextAttributesGroup::generate()
{
	m_vao.generate();
	for(auto& vbo : m_vbos)
		vbo->generate();
}

void VertextAttributesGroup::bind(ShaderProgram& shaderProgram)
{
	m_vao.bind(shaderProgram);
	for(auto& vbo : m_vbos)
		vbo->bind(shaderProgram);
}

void VertextAttributesGroup::unbind(ShaderProgram& shaderProgram)
{
	m_vao.unbind(shaderProgram);
	for(auto& vbo : m_vbos)
		vbo->unbind(shaderProgram);
}

void VertextAttributesGroup::release()
{
	m_vao.release();
	for(auto& vbo : m_vbos)
		vbo->release();
}

//void VertextAttributeGroup::addVertexData(size_t numPoints, size_t dimension,const std::vector<float> data, boost::variant<std::string, int> location)
//{
//	VertexBufferObject vertexBufferObject(numPoints, dimension, data, location);
//	m_vbos.push_back(vertexBufferObject);
//}

void VertextAttributesGroup::addVertexAttribute(VertexBufferObjectPtr vertexBuffer)
{
	m_vbos.push_back(vertexBuffer);
}
