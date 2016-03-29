#include "TorusGeneratorHelper.h"

static double PI = 3.141592653589793;
static double TWOPI = 6.2831853071795862;
static double TO_RADIANS(double x) { return x * 0.017453292519943295;}
static double TO_DEGREES(double x) { return x * 57.29577951308232; }

TorusGeneratorHelper::TorusGeneratorHelper()
	:m_vert(0),
	m_faces(0),
	m_positions(),
	m_normals(),
	m_texCoords(),
	m_indexes(),
	m_isGenerated(false)
{

}

TorusGeneratorHelper::~TorusGeneratorHelper()
{

}

void TorusGeneratorHelper::generate(int sides, int rings, float outerRadius, float innerRadius)
{
	m_vert  = sides * (rings+1);   // One extra ring to duplicate first ring
	m_faces = sides * rings;

	m_positions.resize(getDimension() * m_vert, 0.f);
	m_normals.resize(getDimension() * m_vert, 0.f);
	m_texCoords.resize(getDimension() * m_vert, 0.f);
	// Elements
	m_indexes.resize(6 * m_faces, 0); // I don't understand why we have 6 here

	float ringFactor  = (float)(TWOPI / rings);
	float sideFactor = (float)(TWOPI / sides);
	int idx = 0, tidx = 0;
	for( int ring = 0; ring <= rings; ring++ ) 
	{
		float u = ring * ringFactor;
		float cu = cos(u);
		float su = sin(u);
		for( int side = 0; side < sides; side++ ) 
		{
			float v = side * sideFactor;
			float cv = cos(v);
			float sv = sin(v);
			float r = (outerRadius + innerRadius * cv);
			m_positions[idx] = r * cu;
			m_positions[idx + 1] = r * su;
			m_positions[idx + 2] = innerRadius * sv;
			m_normals[idx] = cv * cu * r;
			m_normals[idx + 1] = cv * su * r;
			m_normals[idx + 2] = sv * r;
			m_texCoords[tidx] = (float)(u / TWOPI);
			m_texCoords[tidx+1] = (float)(v / TWOPI);
			tidx += 2;
			// Normalize
			float len = sqrt( m_normals[idx] * m_normals[idx] +
				m_normals[idx+1] * m_normals[idx+1] +
				m_normals[idx+2] * m_normals[idx+2] );
			m_normals[idx] /= len;
			m_normals[idx+1] /= len;
			m_normals[idx+2] /= len;
			idx += 3;
		}
	}

	idx = 0;
	for( int ring = 0; ring < rings; ring++ ) {
		int ringStart = ring * sides;
		int nextRingStart = (ring + 1) * sides;
		for( int side = 0; side < sides; side++ ) {
			int nextSide = (side+1) % sides;
			// The quad
			m_indexes[idx] = (ringStart + side);
			m_indexes[idx+1] = (nextRingStart + side);
			m_indexes[idx+2] = (nextRingStart + nextSide);
			m_indexes[idx+3] = ringStart + side;
			m_indexes[idx+4] = nextRingStart + nextSide;
			m_indexes[idx+5] = (ringStart + nextSide);
			idx += 6;
		}
	}

	m_isGenerated = true;
}

int TorusGeneratorHelper::getFaces()
{
	return m_faces;
}

int TorusGeneratorHelper::getVerticles()
{
	return m_vert;
}

VertexDataBuffer_t TorusGeneratorHelper::getPositions()
{
	return m_positions;
}

VertexDataBuffer_t TorusGeneratorHelper::getNormals()
{
	return m_normals;
}

VertexDataBuffer_t TorusGeneratorHelper::getTextureCoords()
{
	return m_texCoords;
}

VertexIndexBuffer_t TorusGeneratorHelper::getIndexes()
{
	return m_indexes;
}

int TorusGeneratorHelper::getDimension()
{
	return DIMENSION;
}
