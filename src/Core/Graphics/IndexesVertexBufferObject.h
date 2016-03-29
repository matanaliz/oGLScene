#ifndef ELEMENTS_VERTEX_BUFFER_OBJECT_H
#define ELEMENTS_VERTEX_BUFFER_OBJECT_H

#include <vector>
#include <memory>

#include "BufferEnums.h"


class ShaderProgram;
class IndexesVertexBufferObject;
typedef std::shared_ptr<IndexesVertexBufferObject> IndexesVertexBufferObjectPtr;

//This vertex buffer contains indexes each three of those are represent the triangle to be drawn with glDrawElements
class IndexesVertexBufferObject
{
public:
	IndexesVertexBufferObject(int faces, std::vector<unsigned int>&& data, DrawType type = DrawType::Static);
	~IndexesVertexBufferObject();

	void generate();
	void use() const;
	void unUse() const;
	void release();
	int getFaces() const;

private:
	std::vector<unsigned int> m_dataStorage;
	unsigned int m_vbo;
	int m_faces;
	DrawType m_drawType;
};

#endif //ELEMENTS_VERTEX_BUFFER_OBJECT_H