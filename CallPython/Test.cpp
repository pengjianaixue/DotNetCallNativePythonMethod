#include "stdafx.h"
#include "CallPython.h"
int main()
{
	CCallPython a;
	try
	{
		a.Runfunction("main", "main", " ");

	}
	catch (const std::exception& e)
	{
		printf(e.what());

	}
	
	system("pause");
	return 0;

	
	





}