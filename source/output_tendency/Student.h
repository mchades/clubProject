
#ifndef Student_h
#define Student_h

#include<string>
#include<vector>
#include<map>

using namespace std;

class Student
{
public:
	Student() {};
	Student(string studentID, string name, string gpa, string interest, string intentDepart, string spareDate)
	{
		setStudentID(studentID);
		setGpa(gpa);
		setInterest(interest);
		setIntentDepart(intentDepart);
		setSpareDate(spareDate);
		this->notMatch = this->intentDepart.size();
		this->volunteer = this->notMatch;
		this->name = name;

	}
private:
	string studentID;   //学号
	string name;       //姓名
	float gpa;         //绩点
	int volunteer;      //志愿数
	int access;      //被接受志愿数
	int notMatch = 0;      //未匹配志愿个数
	vector<string> interest; //兴趣标签
	vector<string> intentDepart;     //意愿部门
	vector<vector<float>> spareDate;        //空闲时间
	map<string, float>mark;         //对应部门匹配分数
public:
	void setStudentID(string studentID);
	void setGpa(string gpa);
	void setInterest(string interest);
	void setIntentDepart(string intentDepart);
	void setSpareDate(string spareDate);
	void setNotMatch();
	void setAccess();
	string getName();
	string getID();
	float getGpa();
	vector<string>getIntentDepart();
	int getNotMatch();
	vector<vector < float >> getSpareTime();
	vector<string>getInterest();
	int getVolunteer();
	friend vector<string> slice(string s, const char* b);
	friend vector<float> timeCut(string normalDate);
	void setMark();
	void changeMark(string key, float value);
	void setMarkZero(string key);
	float getMark(string key);
	int getAccess();
};

#endif