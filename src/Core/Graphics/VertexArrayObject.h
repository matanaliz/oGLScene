#ifndef VERTEX_ARRAY_OBJECT_H
#define VERTEX_ARRAY_OBJECT_H

#include <memory>

class ShaderProgram;
class VertexBufferObject;
class IndexesVertexBufferObject;
class VertexArrayObject;

typedef std::shared_ptr<VertexArrayObject> VertexArrayObjectPtr;

/*
This class is a simple wrapper of oGL VAO object.
It's purpose is to bind and logically unite a few VBO object (probably as the parts of one mesh)
*/
class VertexArrayObject
{
public:
	VertexArrayObject();
	//Generate VAO object. 
	void generate();
	/*
	Bind vbo and elements vbo(indexes) to the current VAO
	*/
	void bindVertexBuffer(const VertexBufferObject* vbo, int location);
	void bindIndexBuffer(const IndexesVertexBufferObject* vbo);

	void use();
	void unUse();
	void release();
private:
	unsigned int m_vao;  //oGL VAO index
	bool isGenerated;
};

#endif //VERTEX_ARRAY_OBJECT_H