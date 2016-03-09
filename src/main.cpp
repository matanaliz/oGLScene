#include "MainWindows.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	oGLScene w;
	w.show();
	return a.exec();
}
