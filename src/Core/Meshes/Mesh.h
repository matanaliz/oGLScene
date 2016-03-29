#ifndef _MESH_H_
#define _MESH_H_

#include "Graphics/VertexBufferObject.h"
#include "Graphics/IndexesVertexBufferObject.h"
#include "Graphics/VertexArrayObject.h"
#include <memory>

class ShaderProgram;

class Mesh;
typedef std::shared_ptr<Mesh> MeshPtr;

class Mesh
{
public:
	Mesh();
	~Mesh();

	void addVertexBuffer(SimpleVertexBufferObjectPtr vbo, int location);
	void addIndexBuffer(IndexesVertexBufferObjectPtr indexBuffer);
	void use() const;
	void unUse() const;

	const IndexesVertexBufferObjectPtr getIndexesObject() const;
	const VertexArrayObjectPtr getVertexArrayObject() const;
private:
	//VertextAttributesGroup m_vertexAttributes;
	VertexArrayObjectPtr m_vao;
	std::vector<SimpleVertexBufferObjectPtr> m_vbos;
	IndexesVertexBufferObjectPtr m_indexBuffer;

};

#endif