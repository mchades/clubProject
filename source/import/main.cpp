// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <string>
#include <time.h>
#include<iomanip>
#include<algorithm>


using namespace std;

string DepName[20] = { "活动部", "实践部", "办公室", "宣传部", "文体部", "外联部", "学习部", "策划部", "组织部", "财务部",
"客服部", "行政部", "技术部", "人事部", "生活部", "权益部", "科技部", "采购部", "产品部", "主席团" };

string Interest[20] = { "篮球", "足球", "乒乓球", "游泳", "画画", "看书", "看电影", "跳舞", "志愿活动", "领导力强",
"学习", "交际", "做海报", "唱歌", "文档", "演讲", "科技", "生活", "技术", "策划" };

string Days[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };


void generateID(ofstream *data)
{
	//产生学号
	*data << "1703";//学号前四位固定数字  
	*data << setfill('0') << setw(5) << rand() % 100000 << " ";//后五位随机数字
}


void generateName(ofstream *data)
{
	//产生姓名
	char xing[81] = "赵钱孙李周吴郑王冯陈褚卫蒋沈韩杨朱秦尤许何吕施张孔曹严华金魏陶姜戚谢邹喻柏水窦章";//姓  
	char ming[81] = "世洪胜主杰仁英仓仕栋任坤众伸佐兰国侪促海信涵修明倡瑞鹏石学良露儒俊伟远秋刚狄琴剑";//名  

	int n = rand() % (strlen(xing) / 2) * 2;//随机选择”姓“的位置  
	*data << xing[n] << xing[n + 1];//一个汉字占两个字节  
	for (int j = 0; j < rand() % 2 + 1; ++j)//名字的个数（1~2）  
	{
		n = rand() % (strlen(ming) / 2) * 2;
		*data << ming[n] << ming[n + 1];
	}
	*data << " ";
}

void generateGpa(ofstream *data)
{ 
	//产生绩点
	*data << (rand() % 999+1) / 100.0 << " ";
}

void generateIntentDep(ofstream *data)
{
	//产生意愿部门
	int n = rand() % 5+1;
	random_shuffle(&DepName[0], &DepName[20]);  //将部门随机排列

	for (int i = 0; i<n; i++)
	{
		*data << DepName[i] << ",";
	}
	*data << " ";
}

void generateTags(ofstream *data)
{
	//产生特点标签
	int n = rand() % 5+1;
	random_shuffle(&Interest[0], &Interest[20]);  //将部门随机排列

	for (int i = 0; i<n; i++)
	{
		*data << Interest[i] << ",";
	}
	*data << " ";
}

void generateDate(ofstream *data)
{
	//产生时间段
	int n = rand() % 5+1;

	random_shuffle(&Days[0], &Days[7]);  //将星期随机排列
	for (int i = 0; i < n; i++)
	{
		*data << Days[i] << ",";
		int oHour = (rand() % 4) + 20;   //随机生成结束时间的小时
		int oMin = (rand() % 2)*30 ;    //随机生成结束时间的分钟，30分钟或者0
		int sHour = rand() % (oHour-19)+19;
		int sMin = (rand() % 2) * 30;
		*data << sHour << ":" << setfill('0') << setw(2)<< sMin << ",";
		*data << oHour << ":" << setfill('0') << setw(2) << oMin << ";";
	}
}

void generateLimit(ofstream *data)
{
	//产生人数上限
	int n = rand() % 16;
	*data << n << " ";
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n, m;  //学生人数n，部门个数m
	m = 20;
	n = 300;
	ofstream data("import.txt");
	data << m << " " << n << endl;
	srand((unsigned int)time(NULL));//随机种子
	for (int i = 0; i < m; i++)
	{
		data << DepName[i] << " ";
		generateLimit(&data);
		generateTags(&data);
		generateDate(&data);
		data << endl;
	}

	for (int j = 0; j < n; j++)
	{
		generateID(&data);
		generateName(&data);
		generateGpa(&data);
		generateTags(&data);
		generateIntentDep(&data);
		generateDate(&data);
		data << endl;
	}

	data.close();
	return 0;
}

