#include "stdafx.h"
#include "ConfigureBaseIf.h"



CConfigureBaseIf::CConfigureBaseIf(const QString & Xmlpath):m_strXmlPath(Xmlpath), 
								  m_ConfigureXmlFile(new QFile(QString(m_strXmlPath)))
{
	
}

CConfigureBaseIf::~CConfigureBaseIf()
{

}
