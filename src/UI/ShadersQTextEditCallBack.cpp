#include "ShadersQTextEditCallBack.h"
#include "QTextEdit.h"

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
	int i = 0;
	i++;
}

void ShadersQTextEditCallBack::SetShaderTextEdit(QTextEdit* t1, QTextEdit* t2)
{
	vertTE = t1;
	fragmTE = t2;
}
