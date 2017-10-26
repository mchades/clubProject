
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
	string name;   //��������
	int limitNum;  //��������
	int existing;  //��ѡ����
	vector<string> feature; //�ص��ǩ
	vector<vector<float>> normalDate;    //����ʱ��
	vector<Student> stuList;//������¼ȡѧ������
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