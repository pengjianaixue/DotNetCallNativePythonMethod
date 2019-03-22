#include "stdafx.h"
#include "CallPython.h"
#pragma execution_character_set("utf-8")
void run()
{
	
	CCallPython<std::string> a;
	a.SetPyPath(R"(C:/Users/eijpnae/Desktop)");//C++ Raw string synatx  the path add to python need the slash not the backslash
	try
	{	
		PARAMLIST paramlist;
		PARAMPAIR param,param1;
		param.first = "i"; 
		param.second = "117";
		param1.first = "s";
		param1.second = "18800000";
		paramlist.push_back(param);
		paramlist.push_back(param1);
		std::string res = a.Runfunction(std::string("main"), std::string("main"), paramlist);
		//CreateProcess()
		printf(res.c_str());
		//std::hash<int> int_hash;
		//int j = int_hash(2);
		//printf("hash vaule is %d",j);

	}
	catch (const std::exception& e)
	{
		printf(e.what());
	}
	
}
int main()
{
	//_CrtSetBreakAlloc(158);
	for (size_t i = 0; i < 100; i++)
	{
		run();
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}