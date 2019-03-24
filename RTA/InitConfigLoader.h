#pragma once

#include <QObject>
#include <QtCore\QXmlStreamReader>
#include <QtCore\QXmlStreamWriter>

class XmlConfigureLoader : public QObject
{
	Q_OBJECT
	
public:
	XmlConfigureLoader(QObject *parent);
	~XmlConfigureLoader();
public:
	bool CreateAndCheckInitXml();
	
private:
	QXmlStreamWriter m_XmlWriter;
	QXmlStreamReader m_XmlReader;
};
