#include "MainWindows.h"
#include <QtWidgets/QApplication>
#include "ShadersQTextEditCallBack.h"

const char* vertex_shader =
	"#version 400\n"
	"in vec3 vp;\n"
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

	QTextEdit* vTextEdit = w.findChild<QTextEdit*>("vertTextEdit");
	QTextEdit* fTextEdit = w.findChild<QTextEdit*>("fragTextEdit");
	QPushButton* pushButton = w.findChild<QPushButton*>("TryShader");

	ShadersQTextEditCallBack callBack(NULL);

	pushButton->connect(pushButton, SIGNAL(pressed()), &callBack, SLOT(vertexChanged()));

	vTextEdit->setText(vertex_shader);
	fTextEdit->setText(fragment_shader);

	w.show();
	return a.exec();
}
