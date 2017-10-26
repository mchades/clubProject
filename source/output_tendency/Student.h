
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
	string studentID;   //ѧ��
	string name;       //����
	float gpa;         //����
	int volunteer;      //־Ը��
	int access;      //������־Ը��
	int notMatch = 0;      //δƥ��־Ը����
	vector<string> interest; //��Ȥ��ǩ
	vector<string> intentDepart;     //��Ը����
	vector<vector<float>> spareDate;        //����ʱ��
	map<string, float>mark;         //��Ӧ����ƥ�����
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