
#ifndef Department_h
#define Department_h

#include "stdafx.h"
#include"Student.h"
#include<string>
#include<vector>

using namespace std;

class Department
{
public:
	Department(string name, string limitNum, string feature, string normalDate)
	{
		setLimitNum(limitNum);
		setFeature(feature);
		setNormalDate(normalDate);
		setName(name);
	}
private:
	string name;   //部门名称
	int limitNum;  //人数上限
	int existing;  //已选人数
	vector<string> feature; //特点标签
	vector<vector<float>> normalDate;    //常规活动时间
	vector<Student> stuList;//创建被录取学生名单
public:
	void setLimitNum(string limitNum);
	void setExisting();
	void setFeature(string feature);
	void setNormalDate(string normalDate);
	void addMember();
	void setName(string name);
	string getName();
	int getExisting();
	int getLimitNum();
	vector<vector<float>> getNormalDate();
	vector<string>getFeature();
	friend vector<float> timeCut(string normalDate);
	friend vector<string> slice(string s, const char* b);
	void setStu(Student s);
	vector<Student> getStu();
};

#endif