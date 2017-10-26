
#include "stdafx.h"
#include"Student.h"


void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setGpa(string gpa)
{
	this->gpa = atof(gpa.c_str());
}

void Student::setInterest(string interest)
{
	this->interest = slice(interest, ",");
}

void Student::setIntentDepart(string intentDepart)
{
	this->intentDepart = slice(intentDepart, ",");
}

void Student::setSpareDate(string spareDate)
{
	vector<string>spareDateVec = slice(spareDate, ";");
	vector<string>::iterator it = spareDateVec.begin();
	while (it != spareDateVec.end() - 1)
	{
		this->spareDate.push_back(timeCut(*it));
		it++;
	}
}

void Student::setNotMatch()
{
	this->notMatch--;
}

void Student::setAccess()
{
	this->access++;
}

string Student::getName()
{
	return this->name;
}

string Student::getID()
{
	return this->studentID;
}


float Student::getGpa()
{
	return this->gpa;
}

vector<string> Student::getIntentDepart()
{
	return this->intentDepart;
}

int Student::getNotMatch()
{
	return this->notMatch;
}

vector < vector < float >> Student::getSpareTime()
{
	return this->spareDate;
}

vector<string> Student::getInterest()
{
	return this->interest;
}

int Student::getVolunteer()
{
	return this->volunteer;
}

void Student::setMark()
{
	vector<string> intentVec = this->intentDepart;
	vector<string> ::iterator intentIter = intentVec.begin();
	while (intentIter != intentVec.end())
	{
		this->mark.insert(make_pair(*intentIter, 0));
		intentIter++;
	}
}

void Student::changeMark(string key, float value)
{
	this->mark[key] += value;
}

void Student::setMarkZero(string key)
{
	this->mark[key] = 0;
}

float Student::getMark(string key)
{
	return this->mark[key];
}

int Student::getAccess()
{
	return this->access;
}