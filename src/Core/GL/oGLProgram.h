#ifndef OGL_PROGRAM_H
#define OGL_PROGRAM_H

#include "Platform.h"

//This class is temporary. 
//It absorbs all necessary GL stuffs
class CORE_API oGLProgram
{
public:
	oGLProgram();
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);
};

#endif //OGL_PROGRAM_H