#include "stdafx.h"
#include "CallPython.h"
void run()
{

	CCallPython a;
	try
	{	
		
		PARAMLIST paramlist;
		PARAMPAIR param;
		param.first = "s";
		param.second = "117";
		paramlist.push_back(param);
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