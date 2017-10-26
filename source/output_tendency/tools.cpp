
#include "stdafx.h"
#include"tools.h"



vector<string> slice(string s, const char* b)
{
	vector<string> str;
	int locate = 0;
	while (locate != -1)
	{
		locate = s.find(b);
		str.push_back(s.substr(0, locate));
		s = s.substr(locate + 1);
	}
	return str;
}

vector<float> timeCut(string normalDate)
{
	vector<string> timeVec = slice(normalDate, ",");
	string day = timeVec[0];
	string startTime = timeVec[1];
	vector<string>startTimeVec = slice(startTime, ":");
	string endTime = timeVec[2];
	vector<string>endTimeVec = slice(endTime, ":");
	vector<float> normalDateVec;
	if (day == "Mon")
	{
		normalDateVec.push_back(1);
	}
	else if (day == "Tue")
	{
		normalDateVec.push_back(2);
	}
	else if (day == "Wed")
	{
		normalDateVec.push_back(3);
	}
	else if (day == "Thu")
	{
		normalDateVec.push_back(4);
	}
	else if (day == "Fri")
	{
		normalDateVec.push_back(5);
	}
	else if (day == "Sat")
	{
		normalDateVec.push_back(6);
	}
	else if (day == "Sun")
	{
		normalDateVec.push_back(7);
	}
	float startHour = atof(startTimeVec[0].c_str()) + atof(startTimeVec[1].c_str()) / 60;
	float endHour = atof(endTimeVec[0].c_str()) + atof(endTimeVec[1].c_str()) / 60;
	normalDateVec.push_back(startHour);
	normalDateVec.push_back(endHour);
	return normalDateVec;
}