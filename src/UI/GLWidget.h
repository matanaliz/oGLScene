#ifndef GLSCENCE_H
#define GLSCENCE_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
	Q_OBJECT

public:
	GLWidget(QWidget *parent);
	~GLWidget();

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

private:
	
};

#endif // GLSCENCE_H
