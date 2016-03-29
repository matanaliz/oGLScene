#ifndef GLSCENCE_H
#define GLSCENCE_H

#include <QOpenGLWidget>
#include <QTimer>

class GLWidget : public QOpenGLWidget 
{
	Q_OBJECT

public:
	GLWidget(QWidget *parent);
	~GLWidget();

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

protected slots:
	void  drawGL();

private:
	QTimer timer;
};

#endif // GLSCENCE_H
