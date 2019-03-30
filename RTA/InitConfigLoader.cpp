#include "stdafx.h"
#include "InitConfigLoader.h"

CXmlConfigureFileOperation::CXmlConfigureFileOperation(QObject *parent, const std::string& InitFilePath,OPERATIONTYPE optype)
	: QObject(parent), m_initXmlFile( new QFile(InitFilePath.c_str())),m_bLoadFlag(true), m_pugiXmlReader(nullptr)
{
	m_enumclassmode = optype;
	if (m_enumclassmode == OPERATIONTYPE::READ)
	{
		QFileInfo InitXmlFile(*m_initXmlFile);
		bool bInitFileExistsFlags = InitXmlFile.exists();
		if (bInitFileExistsFlags)
		{
			m_pugiXmlReader = new pugi::xml_document;
			if (!m_pugiXmlReader->load_file(InitFilePath.c_str(), pugi::parse_default, pugi::encoding_utf8))
			{
				QMessageBox::critical(nullptr, "File Load Error", "Load or create Init.Xml file failed!!!");
				m_bLoadFlag = false;
			}
		}
	}
	else if (m_enumclassmode == OPERATIONTYPE::WRITE)
	{

		if (!m_initXmlFile->open(QIODevice::WriteOnly))
		{
			QMessageBox::critical(nullptr, "File Load Error", "Load or create Init.Xml file failed!!!");
			m_bLoadFlag = false;
		}
		m_XmlWriter = new  QXmlStreamWriter(m_initXmlFile);
		if (m_bLoadFlag)
		{
			m_XmlWriter->setCodec("utf-8");
			m_XmlWriter->setAutoFormatting(true);
			m_XmlWriter->writeStartDocument();
			m_XmlWriter->writeStartElement("initialdata");
		}
	}
	
}

CXmlConfigureFileOperation::~CXmlConfigureFileOperation()
{
	if (m_XmlWriter!=nullptr && m_enumclassmode == OPERATIONTYPE::WRITE)
	{
		delete m_XmlWriter;
		m_XmlWriter = nullptr;
	}
	if (m_pugiXmlReader !=nullptr && m_enumclassmode == OPERATIONTYPE::READ)
	{
		delete m_pugiXmlReader;
		m_pugiXmlReader = nullptr;
	}
	
}

bool CXmlConfigureFileOperation::InitXmlOperationter()
{

	return false;
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

bool CXmlConfigureFileOperation::ReadInitXml(const QString &Prefix,QString &vaule)
{
	QString xpathstr = "//initialdata/" + Prefix;
	TRACE(xpathstr);
	if (m_bLoadFlag)
	{
		TRACE(Prefix);
		pugi::xpath_node findnode = m_pugiXmlReader->select_node(xpathstr.toStdString().c_str()); //m_pugiXmlReader->child(Prefix.toStdString().c_str());
		vaule = findnode.node().child_value();
		TRACE(vaule);
		return true;

	}
	/*
	while (!m_XmlReader->atEnd()&& m_bLoadFlag)
	{
		
		QXmlStreamReader::TokenType nType = m_XmlReader->readNext();
		if (m_XmlReader->isEndDocument())
		{
			return false;
		}
		if (m_XmlReader->isCharacters() )
		{
			TRACE(m_XmlReader->name());
			if (m_XmlReader->name() == Prefix)
			{
				vaule = m_XmlReader->readElementText();
				break;
			}
			
		}
	}*/
	return false;
}

bool CXmlConfigureFileOperation::ForamtEndEleAndSave()
{
	m_XmlWriter->writeEndElement();
	m_XmlWriter->writeEndDocument();
	m_initXmlFile->flush();
	m_initXmlFile->close();
	return true;
}


