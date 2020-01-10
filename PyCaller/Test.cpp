#include "stdafx.h"
#include "pyCaller.h"
#pragma execution_character_set("utf-8")
void run()
{
	
	PyCaller a(R"(C:/Users/eijpnae/Desktop)");
	try
	{			
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