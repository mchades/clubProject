// match.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Match.h"


int main()
{
	Match* a = new Match("import.txt");
	a->start();
	a->output();
	//system("pause");
	return 0;
}
