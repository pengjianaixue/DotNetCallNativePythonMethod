#pragma once
#include <QString>
struct CaseInformationStruct
{
	QString fileName;
	QString filePath;
	QString fileDir;
	bool	filePathIsContainBlankChar{ false };
	bool    isIgnore{false};
	bool	isSelectToRunList{false};
	CaseInformationStruct()
	{
		if (!filePath.isEmpty())
		{
			filePathIsContainBlankChar = judgementPathIsContainBlankChar(filePath);
		}
	}
	// must be judgementPathIsContainBlankChar before call getExecutableArgString
	// otherwise the getExecutableArgString return value may be is empty
	QString&& getExecutableArgString()
	{
		filePathIsContainBlankChar = judgementPathIsContainBlankChar(filePath);
		if (filePathIsContainBlankChar)
		{
			QString executableArgString = QString(R"(")") + filePath + R"(")";
			return std::move(executableArgString);
				
		}
		return std::move(QString());
	
	}
	bool isCasePathContainSpaceChar()
	{
		if (!filePath.isEmpty())
		{
			return judgementPathIsContainBlankChar(filePath);
		}
		return false;
	}
	bool judgementPathIsContainBlankChar(QString path)
	{
		for (const auto &item: path)
		{
			if (item.isSpace())
			{
				return true;
			}
		}
	}
};

