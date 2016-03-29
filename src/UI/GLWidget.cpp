#include "GLWidget.h"
#include "../Core/Graphics//oGLProgram.h"


GLWidget::GLWidget(QWidget *parent)
	: QOpenGLWidget (parent)
{
	connect(&timer, SIGNAL(timeout()), this, SLOT(drawGL()));
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
	oGLProgram::instance().initializeGL();
	timer.start();
}

void GLWidget::paintGL()
{
	oGLProgram::instance().paintGL();
}

void GLWidget::resizeGL(int w, int h)
{
	oGLProgram::instance().resizeGL(w, h);
}

void GLWidget::drawGL()
{
	repaint();
}

