#ifndef MESH_GENERATOR_H
#define MESH_GENERATOR_H

#include <memory>
#include <map>

class Mesh;
typedef std::shared_ptr<Mesh> MeshPtr;


//This is temporary class to provide quick access to basic meshes


class MeshGenerator
{
public:
	enum class MeshType
	{
		Triangle,
		Torus
	};

	MeshPtr generateMesh(MeshType type);

private:
	MeshPtr generateTorus();
	MeshPtr generateTriangle();
	static std::map<MeshType, MeshPtr> m_meshHashMap;
};

#endif