#ifndef SHADERSQTEXTEDITCALLBACK_H
#define SHADERSQTEXTEDITCALLBACK_H

#include <QObject>

class QTextEdit;
class ShadersQTextEditCallBack : public QObject
{
	Q_OBJECT

public:
	ShadersQTextEditCallBack(QObject *parent);
	void setShaderTextEdit(QTextEdit* vertTE, QTextEdit* fragmTE);
	~ShadersQTextEditCallBack();

public slots:
	void vertexChanged();	
	void fragmentChanged();	

	void triangleChanged(bool value);	
	void torusChanged(bool value);	

private:
	QTextEdit* vertTE;
	QTextEdit* fragmTE;
};

#endif // SHADERSQTEXTEDITCALLBACK_H
