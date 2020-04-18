#pragma once
#include <QtCore\QString>
#include <QtCore\QFile>

class ConfigureBaseIf
{

public:
	typedef enum Operationtype
	{

		READ,
		WRITE

	}OPERATIONTYPE;
public:
	ConfigureBaseIf(const QString &Xmlpath);
	virtual ~ConfigureBaseIf();
protected:
	QFile				*m_ConfigureXmlFile;
	QString				 m_strXmlPath;


};

