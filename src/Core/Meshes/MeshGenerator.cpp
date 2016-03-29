#include "MeshGenerator.h"
#include "MeshHelpers/TorusGeneratorHelper.h"
#include "Mesh.h"
#include "Utils/Auxilary.h"

#pragma message("Need to get rid of GL dependency")

#include "Graphics/VertexBufferObject.h"
#include "Graphics/IndexesVertexBufferObject.h"


MeshPtr MeshGenerator::generateMesh(MeshType type)
{
	auto meshPair = m_meshHashMap.find(type);
	if(meshPair != std::end(m_meshHashMap))
		return meshPair->second;

	MeshPtr mesh;

	switch (type)
	{
	case MeshType::Torus:
		mesh = generateTorus();
		break;
	case MeshType::Triangle:
		mesh = generateTriangle();
		break;
	default:
		ERROR_NOT_IMPL("MeshGenerator::generateMesh");
	}

	//m_meshHashMap[type] = mesh;
	return mesh;
}

MeshPtr MeshGenerator::generateTorus()
{
	MeshPtr mesh = std::make_shared<Mesh>();

	TorusGeneratorHelper helper;
	helper.generate(30, 30, 0.7f, 0.3f);
	int nVerts = helper.getVerticles();
	int nFaces = helper.getFaces();
	auto positions = helper.getPositions();
	auto indexes = helper.getIndexes();

	auto positionVertexBuffer = std::make_shared<VertexBufferObject>(nVerts, 3, std::move(positions));
	positionVertexBuffer->generate();

	auto elementsVertexBuffer = std::make_shared<IndexesVertexBufferObject>(nFaces, std::move(indexes));
	elementsVertexBuffer->generate();

	mesh->addVertexBuffer(positionVertexBuffer, 0);
	mesh->addIndexBuffer(elementsVertexBuffer);

	return mesh;
}

MeshPtr MeshGenerator::generateTriangle()
{
	static const int NumberOfPoints = 3;
	static const int PointsSize = 3;
	static float points[NumberOfPoints * PointsSize] = {
		0.0f,  0.5f,  0.0f,
		0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};
	MeshPtr mesh = std::make_shared<Mesh>();

	auto positionVertexBuffer = std::make_shared<VertexBufferObject>(NumberOfPoints, PointsSize, std::vector<float>(points, points + PointsSize * NumberOfPoints));
	positionVertexBuffer->generate();

	mesh->addVertexBuffer(positionVertexBuffer, 0);

	return mesh;
}

std::map<MeshGenerator::MeshType, MeshPtr> MeshGenerator::m_meshHashMap;

