#ifndef TORUS_GENERATOR_HELPER_H
#define TORUS_GENERATOR_HELPER_H

#include <vector>

typedef std::vector<float> VertexDataBuffer_t;
typedef std::vector<unsigned int> VertexIndexBuffer_t;

class TorusGeneratorHelper
{
public:
	TorusGeneratorHelper();
	~TorusGeneratorHelper();

	void generate(int sides, int rings, float outerRadius, float innerRadius);
	
	int getFaces();
	int getVerticles();
	VertexDataBuffer_t getPositions();
	VertexDataBuffer_t getNormals();
	VertexDataBuffer_t getTextureCoords();
	VertexIndexBuffer_t getIndexes();

	int getDimension();

private:
	//input values, probably unnecessary 
	/*
	int m_sides;
	int m_rings;

	float m_outerRadius;
	float m_innerRadius;
	*/

	//Computed values
	int m_vert;
	int m_faces;

	//Computed data buffers
	VertexDataBuffer_t m_positions; //Position
	VertexDataBuffer_t m_normals; 	// Normals
	VertexDataBuffer_t m_texCoords; 	// Tex coords
	VertexIndexBuffer_t m_indexes; 	// Elements

	static const int DIMENSION = 3;

	//aux
	bool m_isGenerated;
};

#endif