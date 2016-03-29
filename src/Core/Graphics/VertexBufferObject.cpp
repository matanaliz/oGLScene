#include "VertexBufferObject.h"
#include "Utils/Asserts.h"
#include "Utils/Auxilary.h"
#include "ShaderProgram.h"
#include "Utils/Asserts.h"
#include "GL/glew.h"
#include "Utils/ErrorChecker.h"


VertexBufferObject::VertexBufferObject(size_t numPoints, size_t dimension, std::vector<float>&& data, DrawType type /*= DrawType::Static*/)
	:m_dataStorage(std::move(data)),
	m_numPoints(numPoints),
	m_dimension(dimension),
	m_vbo(0),
	m_drawType(type),
	isGenerated(false)
{
	if(numPoints * dimension != m_dataStorage.size())
		throw std::exception("VertexBufferObject is being initialized incorrectly");

}

void VertexBufferObject::generate()
{
	SIMPLE_ASSERT(!isGenerated);

	glGenBuffers (1, &m_vbo);

	GLenum glType = (m_drawType == DrawType::Static) ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW;

	glBindBuffer (GL_ARRAY_BUFFER, m_vbo);
	glBufferData (GL_ARRAY_BUFFER, m_dataStorage.size() * sizeof(float), m_dataStorage.data(), glType);

	isGenerated = true;

	TEST_GL_ERROR();
}

void VertexBufferObject::bind(unsigned int location) const
{
	SIMPLE_ASSERT(isGenerated);
	
	glBindBuffer (GL_ARRAY_BUFFER, m_vbo);
	glEnableVertexAttribArray (location);
	glVertexAttribPointer ((GLuint)location, m_dimension , GL_FLOAT, GL_FALSE, 0, (GLubyte *)0);

	TEST_GL_ERROR();
}

void VertexBufferObject::release()
{
	SIMPLE_ASSERT(isGenerated);

	 glDeleteBuffers(1, &m_vbo);

	 TEST_GL_ERROR();
}


VertexBufferObject::~VertexBufferObject()
{

}

void VertexBufferObject::use() const
{
	glBindBuffer (GL_ARRAY_BUFFER, m_vbo);

	TEST_GL_ERROR();
}
