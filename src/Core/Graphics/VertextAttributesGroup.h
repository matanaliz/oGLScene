#ifndef VERTEX_ATTRIBUTE_H
#define VERTEX_ATTRIBUTE_H

#include <vector>
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

class ShaderProgram;
/*
consist VBO and VAO
*/
class VertextAttributesGroup
{
public:
	VertextAttributesGroup();

	void addVertexAttribute(VertexBufferObjectPtr vertexB);
	
	void generate();
	void bind(ShaderProgram& shaderProgram);
	void unbind(ShaderProgram& shaderProgram);
	void release();
	
private:
	VertexArrayObject m_vao;
	std::vector<VertexBufferObjectPtr> m_vbos;
}; 

#endif // !VERTEX_ATTRIBUTE_H
