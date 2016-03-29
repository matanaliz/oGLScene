#include <gl\glew.h>
#include "oGLProgram.h"
#include "Meshes/Mesh.h"
#include <algorithm>
#include "Graphics/Renderer.h"

#include "Meshes/MeshGenerator.h"

#include "ShaderProgram.h"
#include <iostream>
#include <algorithm>

//GO TO SOME SORT OF SHADER MANAGER
ShaderProgram shaderProgram;
MeshPtr mesh;

const char* vertex_shader =
	"#version 400\n"
	"in vec3 position;\n"
	"void main () {\n"
	"  gl_Position = vec4 (position, 1.0);\n"
	"}\n";

const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;\n"
	"void main () {\n"
	"  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);\n"
	"}\n";

const int SizeOfVBO = 2;
static GLuint vbo[SizeOfVBO] = {0};
static GLuint vao = 0;

oGLProgram::oGLProgram()
{
	m_meshIndex = -1;
}



void oGLProgram::initializeGL()
{
	glewInit();

	shaderProgram.compileShaderFromString(vertex_shader, ShaderProgram::VERTEX);
	shaderProgram.compileShaderFromString(fragment_shader, ShaderProgram::FRAGMENT);
	
	shaderProgram.linkProgram();

	//shaderProgram.use();
	MeshGenerator meshGenerator;
	mesh = meshGenerator.generateMesh(MeshGenerator::MeshType::Torus);
}

void oGLProgram::paintGL()
{
	if(m_meshIndex == 0)
		mesh = MeshGenerator().generateMesh(MeshGenerator::MeshType::Triangle);
	else if(m_meshIndex == 1)
		mesh = MeshGenerator().generateMesh(MeshGenerator::MeshType::Torus);
	
	m_meshIndex = -1;

	Renderer().render(shaderProgram, *mesh.get());
}

void oGLProgram::resizeGL(int w, int h)
{
	int side = std::min(w, h);
	glViewport((w - side) / 2, (h - side) / 2, side, side);
}


void oGLProgram::setAnotherShader(const std::string& vert, const std::string& frag)
{
	//std::cout << vert << "\n\n";
	//std::cout << frag << "\n\n";

	shaderProgram.release();


	shaderProgram.compileShaderFromString(vert, ShaderProgram::VERTEX);
	shaderProgram.compileShaderFromString(frag, ShaderProgram::FRAGMENT);

	shaderProgram.linkProgram();
}

#include <Windows.h>

oGLProgram& oGLProgram::instance()
{
	//AllocConsole(); 
	//freopen("CON","w", stdout);

	static oGLProgram ogl;
	return ogl;
}

void oGLProgram::setAnotherMesh(int meshIndex)
{
	m_meshIndex = meshIndex;
}

