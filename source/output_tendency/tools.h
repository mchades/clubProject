
#ifndef tools_h
#define tools_h

#include "stdafx.h"
#include<vector>
#include<string>
using namespace std;

//实现将字符串s按字符b分割后存放在字符串向量中并返回
vector<string> slice(string , const char* );

//将时间字符串转化为对应的数字并返回
vector<float> timeCut(string normalDate);

#endif