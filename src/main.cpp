#include "MainWindows.h"
#include <QtWidgets/QApplication>
#include "ShadersQTextEditCallBack.h"

const char* vertex_shader =
	"#version 400\n"
	"in vec3 position;\n"
	"void main () {\n"
	"  gl_Position = vec4 (vp, 1.0);\n"
	"}\n";

const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;\n"
	"void main () {\n"
	"  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);\n"
	"}\n";


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	oGLScene w;

	ShadersQTextEditCallBack callBack(NULL);


	QTextEdit* vTextEdit = w.findChild<QTextEdit*>("vertTextEdit");
	QTextEdit* fTextEdit = w.findChild<QTextEdit*>("fragTextEdit");
	QPushButton* pushButton = w.findChild<QPushButton*>("TryShader");

	QMenu* meshMenu = w.findChild<QMenu*>("menuMesh");

	QList<QAction *> actions = meshMenu->actions();
	for(QAction* action: actions)
	{
		if(action->text() == "Triangle")
			action->connect(action, SIGNAL(triggered(bool)), &callBack, SLOT(triangleChanged(bool)) );
		else if (action->text() == "Torus")
			action->connect(action, SIGNAL(triggered(bool)), &callBack, SLOT(torusChanged(bool)) );
	}

	callBack.setShaderTextEdit(vTextEdit, fTextEdit);

	pushButton->connect(pushButton, SIGNAL(pressed()), &callBack, SLOT(vertexChanged()));

	vTextEdit->setText(vertex_shader);
	fTextEdit->setText(fragment_shader);

	w.show();
	return a.exec();
}
