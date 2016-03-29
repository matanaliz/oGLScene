#ifndef VERTEX_BUFFER_DATA_H
#define VERTEX_BUFFER_DATA_H

#include <vector>
#include <string>
#include <memory>

#include "BufferEnums.h"


class ShaderProgram;
class VertexBufferObject;
typedef std::shared_ptr<VertexBufferObject> SimpleVertexBufferObjectPtr;

/*
This is a simple wrapper of a simple float-based oGL FBO object
*/
class VertexBufferObject
{
public:
	~VertexBufferObject();

	VertexBufferObject(size_t numPoints, size_t dimension, std::vector<float>&& data, 
		DrawType type = DrawType::Static);

	virtual void generate();
	virtual void bind(unsigned int location) const;
	virtual void use() const;
	virtual void release();

private:
	std::vector<float> m_dataStorage;

	size_t m_numPoints;
	size_t m_dimension;
	unsigned int m_vbo;

	bool isGenerated;

	DrawType m_drawType;
};

#endif //VERTEX_BUFFER_DATA_H