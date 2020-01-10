#include "stdafx.h"
#include "pyCaller.h"
#pragma execution_character_set("utf-8")
void run()
{
	
	PyCaller a(R"(C:/Users/eijpnae/Desktop)");
	try
	{			
		//a.runPyFile(R"(.\test.py)");
		PyCaller::PYPARAMLIST paramlist;
		PyCaller::PYPARAMPAIR param, param1;
		PyCaller::PyResult res = nullptr;
		param.first = "d";
		param.second = "117.58";
		param1.first = "d";
		param1.second = "118.56";
		paramlist.push_back(param);
		paramlist.push_back(param1);
	 	double sumValue{0};
		bool executeRes = a.runPyFunction(R"(main)", "testFetch", 15.45,118.56,153.0,4,5,6,7, sumValue);
		if (executeRes)
		{
			std::cout << sumValue << std::endl;
		}
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