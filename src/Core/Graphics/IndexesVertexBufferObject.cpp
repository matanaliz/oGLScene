#include "IndexesVertexBufferObject.h"
#include "Utils/Asserts.h"
#include "Utils/Auxilary.h"
#include "ShaderProgram.h"

#include "GL/glew.h"

#include "Utils/ErrorChecker.h"

IndexesVertexBufferObject::IndexesVertexBufferObject(int faces, std::vector<unsigned int>&& data, DrawType type /*= DrawType::Static*/)
	:m_dataStorage(std::move(data)),
	m_vbo(0),
	m_faces(faces),
	m_drawType(type)
{

}

void IndexesVertexBufferObject::generate()
{
	glGenBuffers (1, &m_vbo);

	GLenum glType = (m_drawType == DrawType::Static) ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,  m_dataStorage.size() * sizeof(unsigned int), m_dataStorage.data(), glType);

	TEST_GL_ERROR();
}

void IndexesVertexBufferObject::use() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo);

	TEST_GL_ERROR();
}

void IndexesVertexBufferObject::release()
{
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo);
	//glDeleteBuffers(1, &m_vbo);
}


IndexesVertexBufferObject::~IndexesVertexBufferObject()
{
}

int IndexesVertexBufferObject::getFaces() const
{
	return m_faces;
}

void IndexesVertexBufferObject::unUse() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	TEST_GL_ERROR();
}
