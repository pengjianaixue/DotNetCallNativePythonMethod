#include "stdafx.h"
#include "CallPython.h"
#pragma execution_character_set("utf-8")
void run()
{
	
	CCallPython a;
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
		//paramlist.push_back(param1);
		std::string res = a.Runfunction("main", "main", paramlist);
		printf(res.c_str());

	}
	catch (const std::exception& e)
	{
		printf(e.what());
	}
	system("pause");
}
int main()
{
	//_CrtSetBreakAlloc(158);
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}