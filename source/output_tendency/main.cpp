// match.cpp: �������̨Ӧ�ó������ڵ㡣
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
