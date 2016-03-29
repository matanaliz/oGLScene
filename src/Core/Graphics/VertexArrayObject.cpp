#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "Utils/Asserts.h"
#include "ShaderProgram.h"

#include "IndexesVertexBufferObject.h"
#include "GL/glew.h"

#include "Utils/ErrorChecker.h"

VertexArrayObject::VertexArrayObject()
	:m_vao(0),
	isGenerated(false)
{

}

void VertexArrayObject::generate()
{
	SIMPLE_ASSERT(!isGenerated);

	glGenVertexArrays(1, &m_vao);
	isGenerated = true;

	TEST_GL_ERROR();
}

void VertexArrayObject::use()
{
	SIMPLE_ASSERT(isGenerated);
	glBindVertexArray(m_vao);

	TEST_GL_ERROR();
}

void VertexArrayObject::unUse()
{
	SIMPLE_ASSERT(isGenerated);
	glBindVertexArray(0);

	TEST_GL_ERROR();
}

void VertexArrayObject::release()
{
	SIMPLE_ASSERT(isGenerated);
	unUse();
	glDeleteVertexArrays(1, &m_vao);

	TEST_GL_ERROR();
}

void VertexArrayObject::bindVertexBuffer(const VertexBufferObject* vbo, int location)
{
	SIMPLE_ASSERT(isGenerated);
	SIMPLE_ASSERT(vbo != nullptr);
	use();
	vbo->bind(location);
	//unUse();

	TEST_GL_ERROR();
}

void VertexArrayObject::bindIndexBuffer(const IndexesVertexBufferObject* indexes)
{
	SIMPLE_ASSERT(isGenerated);
	SIMPLE_ASSERT(indexes != nullptr);
	use();
	indexes->use();
	unUse();

	TEST_GL_ERROR();
}



