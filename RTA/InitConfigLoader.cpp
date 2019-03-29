#include "stdafx.h"
#include "InitConfigLoader.h"

CXmlConfigureFileOperation::CXmlConfigureFileOperation(QObject *parent, const QString& InitFilePath)
	: QObject(parent), m_initXmlFile( new QFile(InitFilePath)),m_bLoadFlag(true)
{
	
	QFileInfo InitXmlFile(*m_initXmlFile);
	bool bInitFileExistsFlags = InitXmlFile.exists();
	if (!m_initXmlFile->open(QIODevice::ReadWrite))
	{
		QMessageBox::critical(nullptr, "File Load Error", "Load or create Init.Xml file failed!!!");
		m_bLoadFlag = false;
	}
	m_XmlWriter = new  QXmlStreamWriter(m_initXmlFile);
	m_XmlReader = new  QXmlStreamReader(m_initXmlFile);
	if (bInitFileExistsFlags&&m_bLoadFlag)
	{
		m_XmlWriter->setCodec("utf-8");
		m_XmlWriter->writeDefaultNamespace("http://www.w3.org/2000/xmlns/");
		m_XmlWriter->writeStartDocument();
		m_XmlWriter->setAutoFormatting(true);
		m_XmlWriter->writeStartElement("INITDATA");
	}


}

CXmlConfigureFileOperation::~CXmlConfigureFileOperation()
{

	delete m_XmlWriter;
	delete m_XmlReader;
}

bool CXmlConfigureFileOperation::WirteInitXml(const QString &Prefix, const QString &vaule)
{	
	if (m_bLoadFlag)
	{
		
		m_XmlWriter->writeTextElement(Prefix, vaule);
		return true;
	}
	return false;
}

bool CXmlConfigureFileOperation::ReadInitXml(const QString &Prefix,  QString &vaule)
{
	while (!m_XmlReader->atEnd())
	{
		
		m_XmlReader->readNext();
		if (m_XmlReader->isEndDocument())
		{
			return false;
		}
		if (m_XmlReader->name()==Prefix)
		{
			vaule = m_XmlReader->readElementText();
			break;
		}
	}
	return true;
}

bool CXmlConfigureFileOperation::ForamtEndEleAndSave()
{
	m_XmlWriter->writeEndElement();
	m_XmlWriter->writeEndDocument();
	m_initXmlFile->close();
	return true;
}


