#include "GLWidget.h"
#include "../Core/GL/oGLProgram.h"

static oGLProgram oglProgram;

GLWidget::GLWidget(QWidget *parent)
	: QGLWidget(parent)
{
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
	oglProgram.initializeGL();
}

void GLWidget::paintGL()
{
	oglProgram.paintGL();
}

void GLWidget::resizeGL(int w, int h)
{
	oglProgram.resizeGL(w, h);
}

