#include "stdafx.h"
#include "pyCaller.h"
#pragma execution_character_set("utf-8")
void run()
{
	
	pyCaller a;
	a.SetPyPath(R"(C:/Users/eijpnae/Desktop)");//C++ Raw string synatx  the path add to python need the slash not the backslash
	try
	{	
		pyCaller::PYPARAMLIST test;
		a.SetPyPath(R"(C:/Users/pengjian/Desktop)");
		//std::string k = a.Runfunction(R"(Case-EVM)", "test", test);
		a.runPyFile(R"(C:\Users\pengjian\Desktop\Case-EVM.py)");
		/*PYPARAMLIST paramlist;
		PYPARAMPAIR param,param1;
		param.first = "i"; 
		param.second = "117";
		param1.first = "s";
		param1.second = "18800000";
		paramlist.push_back(param);
		paramlist.push_back(param1);
		std::string res = a.Runfunction(std::string("main"), std::string("main"), paramlist);
		printf(res.c_str());*/
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
	/*for (size_t i = 0; i < 100; i++)
	{
		run();
	}*/
	run();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}