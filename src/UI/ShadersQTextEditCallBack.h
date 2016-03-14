#ifndef SHADERSQTEXTEDITCALLBACK_H
#define SHADERSQTEXTEDITCALLBACK_H

#include <QObject>

class QTextEdit;
class ShadersQTextEditCallBack : public QObject
{
	Q_OBJECT

public:
	ShadersQTextEditCallBack(QObject *parent);
	void SetShaderTextEdit(QTextEdit* vertTE, QTextEdit* fragmTE);
	~ShadersQTextEditCallBack();

public slots:
	void vertexChanged();	
	void fragmentChanged();	

private:
	QTextEdit* vertTE;
	QTextEdit* fragmTE;
};

#endif // SHADERSQTEXTEDITCALLBACK_H
