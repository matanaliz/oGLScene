#ifndef OGL_PROGRAM_H
#define OGL_PROGRAM_H

#include "Platform.h"
#include <string>
//This class is temporary. 
//It absorbs all necessary GL stuffs
class CORE_API oGLProgram
{
	oGLProgram();

public:
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);
	void setAnotherShader(const std::string& vert, const std::string& frag);
	void setAnotherMesh(int mesh);

	static oGLProgram& instance();
};

#endif //OGL_PROGRAM_H