#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWindows.h"

class oGLScene : public QMainWindow
{
	Q_OBJECT

public:
	oGLScene(QWidget *parent = 0);
	~oGLScene();

private:
	Ui::oGLSceneClass ui;
};

#endif // MAINWINDOWS_H
