
#ifndef tools_h
#define tools_h

#include "stdafx.h"
#include<vector>
#include<string>
using namespace std;

//ʵ�ֽ��ַ���s���ַ�b�ָ�������ַ��������в�����
vector<string> slice(string , const char* );

//��ʱ���ַ���ת��Ϊ��Ӧ�����ֲ�����
vector<float> timeCut(string normalDate);

#endif