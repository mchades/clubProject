#ifndef Match_h
#define Match_h

#include "stdafx.h"
#include"Department.h"
#include"Student.h"

#include<fstream>
#include<iostream>

using namespace std;

class Match
{
public:
	Match(string path)
	{
		ifstream infile(path);
		if (!infile.is_open())
		{
			this->flag = 0;
		}
		else
		{
			string buffer;
			string studentNum;
			string departmentNum;
			getline(infile, buffer);
			int locate = buffer.find(" ");
			departmentNum = buffer.substr(0, locate);
			studentNum = buffer.substr(locate + 1);
			this->studentNum = atoi(studentNum.c_str());       //得到学生人数
			this->departmentNum = atoi(departmentNum.c_str()); //得到部门个数
			/*getline(infile, buffer);
			=slice(buffer," ");*/
			vector<string> vect;
			//实例化指定数量的部门对象
			for (int j = 0; j < this->departmentNum; j++)
			{
				getline(infile, buffer);
				vect = slice(buffer, " ");
				this->dep.push_back(*new Department(vect[0], vect[1], vect[2], vect[3]));
			}
			//实例化指定数量的学生对象
			for (int i = 0; i < this->studentNum; i++)
			{
				getline(infile, buffer);
				vect = slice(buffer, " ");
				this->stu.push_back(*new Student(vect[0], vect[1], vect[2], vect[3], vect[4], vect[5]));
			}
		}
	}
private:
	bool flag;               //标识输入的文件路径是否正确
	int studentNum;      //学生总数
	int departmentNum;    //部门总数
	vector<Student> stu;   //学生对象向量
	vector<Student> matchOver;  //所有志愿匹配完成的学生向量
	vector<Department> dep;     //部门对象向量

public:
	void start();
	friend vector<string> slice(string s, const char* b);
	int getDepNum();
	bool timeMatch(Student &s, Department d);
	void tagMatch(Student &s, Department d);
	void swap(Student &a, Student &b);
	void order(vector<Student> &s, string key);
	vector<Student> getMatchOver();
	void output();
};

#endif