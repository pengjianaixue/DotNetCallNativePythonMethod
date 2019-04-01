#pragma once
#include <QtCore\QString>
#include <QtCore\QFile>
class CConfigureBaseIf
{

public:
	typedef enum Operationtype
	{

		READ,
		WRITE

	}OPERATIONTYPE;
public:
	CConfigureBaseIf(const QString &Xmlpath);
	virtual ~CConfigureBaseIf();
protected:
	QFile				*m_ConfigureXmlFile;
	QString				 m_strXmlPath;


};

