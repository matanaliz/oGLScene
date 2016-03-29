#include "ShadersQTextEditCallBack.h"
#include "QTextEdit.h"
#include "Core/Graphics//oGLProgram.h"

ShadersQTextEditCallBack::ShadersQTextEditCallBack(QObject *parent)
	: QObject(parent)
{

}

ShadersQTextEditCallBack::~ShadersQTextEditCallBack()
{

}

void ShadersQTextEditCallBack::fragmentChanged()
{
	int i = 0;
	i++;
}

void ShadersQTextEditCallBack::vertexChanged()
{
	oGLProgram::instance().setAnotherShader(vertTE->toPlainText().toStdString(), fragmTE->toPlainText().toStdString());
}

void ShadersQTextEditCallBack::setShaderTextEdit(QTextEdit* t1, QTextEdit* t2)
{
	vertTE = t1;
	fragmTE = t2;
}

void ShadersQTextEditCallBack::triangleChanged(bool value)
{
	oGLProgram::instance().setAnotherMesh(0);
}

void ShadersQTextEditCallBack::torusChanged(bool value)
{
	oGLProgram::instance().setAnotherMesh(1);
}
