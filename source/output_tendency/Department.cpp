

#include "stdafx.h"
#include"Department.h"


void Department::setLimitNum(string limitNum)
{

	this->limitNum = atoi(limitNum.c_str());
}

void Department::setExisting()
{
	this->existing++;
}

void Department::setFeature(string feature)
{
	this->feature = slice(feature, ",");
}

void Department::setNormalDate(string normalDate)
{
	vector<string>spareDateVec = slice(normalDate, ";");
	vector<string>::iterator it = spareDateVec.begin();
	while (it != spareDateVec.end() - 1)
	{
		this->normalDate.push_back(timeCut(*it));
		it++;
	}
}


void Department::addMember()
{
	this->existing++;
}

void Department::setName(string name)
{
	this->name = name;
}

string Department::getName()
{
	return this->name;
}

int Department::getExisting()
{
	return this->existing;
}

int Department::getLimitNum()
{
	return this->limitNum;
}

vector<vector<float>> Department::getNormalDate()
{
	return this->normalDate;
}

vector<string> Department::getFeature()
{
	return this->feature;
}

void Department::setStu(Student s)
{
	this->stuList.push_back(s);
}

vector<Student> Department::getStu()
{
	return this->stuList;
}