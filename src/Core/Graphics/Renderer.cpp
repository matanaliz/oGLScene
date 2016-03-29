#include "Renderer.h"
#include "ShaderProgram.h"
#include "VertexArrayObject.h"
#include "IndexesVertexBufferObject.h"
#include "Meshes/Mesh.h"
#include "Utils/Asserts.h"
#include "Utils/ErrorChecker.h"

#include <GL/glew.h>

void Renderer::render(const ShaderProgram& shaderProgram, const Mesh& mesh)
{
	//Later should provide customization of this settings
	glClearColor(0.5, 0.0, 0.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	shaderProgram.use();
	
	auto meshVAO = mesh.getVertexArrayObject();
	SIMPLE_ASSERT(meshVAO != nullptr);
	meshVAO->use();

	auto indexes = mesh.getIndexesObject();
	if(indexes)
	{	
		//Draw with GL_ELEMENT_ARRAY_BUFFER active
		indexes->use();
		glDrawElements(GL_TRIANGLES, 6 * indexes->getFaces(), GL_UNSIGNED_INT, ((GLubyte *)NULL + (0)));
		TEST_GL_ERROR();
		indexes->unUse();
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, 3 );
		TEST_GL_ERROR();
	}
	meshVAO->unUse();
	shaderProgram.unUse();
}
