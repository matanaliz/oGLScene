#include <gl\glew.h>
#include "oGLProgram.h"
#include <algorithm>

#include "ShaderProgram.h"

//WOULD GO TO MESH HIERARHY
static float points[] = {
	0.0f,  0.5f,  0.0f,
	0.5f, -0.5f,  0.0f,
	-0.5f, -0.5f,  0.0f
};

//GO TO SOME SORT OF SHADER MANAGER
ShaderProgram shaderProgram;

const char* vertex_shader =
	"#version 400\n"
	"in vec3 vp;"
	"void main () {"
	"  gl_Position = vec4 (vp, 1.0);"
	"}";

const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;"
	"void main () {"
	"  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
	"}";

static GLuint vbo = 0;
static GLuint vao = 0;

oGLProgram::oGLProgram()
{
}

void oGLProgram::initializeGL()
{
	glewInit();


	shaderProgram.compileShaderFromString(vertex_shader, ShaderProgram::VERTEX);
	shaderProgram.compileShaderFromString(fragment_shader, ShaderProgram::FRAGMENT);




	glGenBuffers (1, &vbo);
	glBindBuffer (GL_ARRAY_BUFFER, vbo);
	glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), points, GL_STATIC_DRAW);

	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);
	glEnableVertexAttribArray (0);
	glBindBuffer (GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	shaderProgram.linkProgram();
}

void oGLProgram::paintGL()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shaderProgram.use();

	glBindVertexArray (vao);
	// draw points 0-3 from the currently bound VAO with current in-use shader
	glDrawArrays (GL_TRIANGLES, 0, 3);

	//float test = color.redF();
	//glClearColor(color.redF(), color.greenF(), color.blueF (), 1);
	//glClear(GL_COLOR_BUFFER_BIT);

}

void oGLProgram::resizeGL(int w, int h)
{
	int side = std::min(w, h);
	glViewport((w - side) / 2, (h - side) / 2, side, side);
}

