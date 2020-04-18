
#include "stdafx.h"
#include "ConfigureBaseIf.h"



ConfigureBaseIf::ConfigureBaseIf(const QString & Xmlpath):m_strXmlPath(Xmlpath), 
								  m_ConfigureXmlFile(new QFile(QString(m_strXmlPath)))
{
	
}

ConfigureBaseIf::~ConfigureBaseIf()
{

}
