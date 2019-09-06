#pragma once

#include <QObject>
#include <QtWidgets\QWidget>
#include <QtWidgets\QMessageBox>
#include <QtCore\QXmlStreamReader>
#include <QtCore\QXmlStreamWriter>
#include <pugixml.hpp>
#include <ConfigureBaseIf.h>
#include "Trace.h"

class CXmlConfigureFileOperation : public QObject
{

	Q_OBJECT
public:
	typedef enum Operationtype
			{
				READ,
				WRITE

			}OPERATIONTYPE;
public:
	//CXmlConfigureFileOperation(QObject *parent);
	CXmlConfigureFileOperation(QObject *parent, const QString& InitFilePath, OPERATIONTYPE optype);
	virtual ~CXmlConfigureFileOperation();
	bool InitXmlOperationter();
public:
	bool WirteInitXml(const QString &Prefix, const QString &vaule);
	bool ReadInitXml(const QString &Prefix, QString &vaule);
	bool ForamtEndEleAndSave();
private:
	
	
	
private:
	QFile				*m_initXmlFile;
	QXmlStreamWriter	*m_XmlWriter;
	QXmlStreamReader	*m_XmlReader;
	pugi::xml_document	*m_pugiXmlReader;
	bool				m_bLoadFlag;
	OPERATIONTYPE		m_enumclassmode;
	bool				m_bInitFileExistsFlags;
				  
};
