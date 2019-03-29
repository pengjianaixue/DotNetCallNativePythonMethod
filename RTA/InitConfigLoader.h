#pragma once

#include <QObject>
#include <QtWidgets\QWidget>
#include <QtWidgets\QMessageBox>
#include <QtCore\QXmlStreamReader>
#include <QtCore\QXmlStreamWriter>

class CXmlConfigureFileOperation : public QObject
{
	Q_OBJECT
	
public:
	CXmlConfigureFileOperation(QObject *parent,const QString& InitFilePath);
	~CXmlConfigureFileOperation();
public:
	bool WirteInitXml(const QString &Prefix, const QString &vaule);
	bool ReadInitXml(const QString &Prefix,  QString &vaule);
	bool ForamtEndEleAndSave();
private:
	
	
	
private:
	QFile			 *m_initXmlFile;
	QXmlStreamWriter *m_XmlWriter;
	QXmlStreamReader *m_XmlReader;
	bool			  m_bLoadFlag;
				  
};
