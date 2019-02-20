#include "stdafx.h"
#include "CallPython.h"
int main()
{
	CCallPython a;
	a.Runfunction("main", "printf", "1");
	
	system("pause");
	return 0;
	





}