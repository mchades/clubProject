


#include "stdafx.h"
#include"Match.h"



void Match::start()
{
	//遍历5个志愿
	for (int i = 0; i < 5; i++)
	{
		//学生对象遍历
		vector<Student>::iterator stuIter = stu.begin();
		while (stuIter != stu.end())
		{
			//匹配学生第i志愿部门，进行对应的匹配评分
			string intent = stuIter->getIntentDepart()[i];
			if (intent == "")
			{
				stuIter->setNotMatch();
				matchOver.push_back(*stuIter);
				stuIter = stu.erase(stuIter);
				continue;
			}
			vector<Department>::iterator Iter = dep.begin();
			//查找到学生第i志愿部门对象
			while (Iter != dep.end())
			{
				Iter->getName();
				if (Iter->getName() == intent)
				{
					break;
				}
				Iter++;
			}
			//将绩点作为成绩的一部分算入匹配分数
			stuIter->changeMark(intent, stuIter->getGpa());
			//如果学生空闲时间和部门活动时间完全不匹配则分数归零，匹配下一学生的志愿
			timeMatch(*stuIter, *Iter);

			//匹配兴趣标签并打分
			tagMatch(*stuIter, *Iter);
			//学生未匹配志愿减一
			stuIter->setNotMatch();
			stuIter++;
		}
		vector<Department>::iterator depIter = dep.begin();
		//在第i个志愿下，按照不同部门对学生分别进行分数排序，取出每个部门对应的成绩非零的同学加入部门
		while (depIter != dep.end())
		{
			order(stu, depIter->getName());
			stuIter = stu.begin();
			while (stuIter != stu.end())
			{
				if (depIter->getExisting() == depIter->getLimitNum() || !stuIter->getMark(depIter->getName()))
				{
					stuIter++;
					continue;
				}
				depIter->setStu(*stuIter);
				stuIter->setMarkZero(depIter->getName());
				depIter->setExisting();
				stuIter->setAccess();
				//如果学生所有志愿完成匹配，则转移学生对象至matchOver容器
				if (!stuIter->getNotMatch())
				{
					matchOver.push_back(*stuIter);
					stuIter = stu.erase(stuIter);
				}
				else
				{
					stuIter++;
				}
			}
			depIter++;
		}
	}
}

int Match::getDepNum()
{
	return this->departmentNum;
}

bool Match::timeMatch(Student &s, Department d)
{
	int count = 0;
	vector<vector<float>> normalDate = d.getNormalDate();
	vector<vector<float>>::iterator timeIter = normalDate.begin();
	vector<vector<float>>stuSpareTime = s.getSpareTime();
	vector<vector<float>>::iterator stuTimeIter = stuSpareTime.begin();
	while (stuTimeIter != stuSpareTime.end())
	{
		timeIter = normalDate.begin();
		while (timeIter != normalDate.end())
		{
			//匹配学生空闲时间与常规活动时间的日子
			if ((*stuTimeIter)[0] != (*timeIter)[0])
			{
				timeIter++;
				continue;
			}
			//若学生空闲时间上下限完全包含某个常规活动时间，加2分
			if ((*stuTimeIter)[1] <= (*timeIter)[1] && (*stuTimeIter)[2] >= (*timeIter)[2])
			{
				s.changeMark(d.getName(), 2);
				count++;
			}
			//若学生空闲时间上限大于某个常规活动时间，下限不超过常规活动开始时间半小时，加1分
			if (((*stuTimeIter)[1] - (*timeIter)[1])<0.5 && (*stuTimeIter)[2] >= (*timeIter)[2])
			{
				s.changeMark(d.getName(), 1);
				count++;
			}
			//若学生空闲时间下限早于某个常规活动时间，上限不低于常规活动结束时间半小时，加1分
			if (((*timeIter)[2] - (*stuTimeIter)[2])<0.5 && (*stuTimeIter)[1] <= (*timeIter)[1])
			{
				s.changeMark(d.getName(), 1);
				count++;
			}
			//若学生空闲时间上限早于某个常规活动时间二十分钟，下限晚于某个常规活动时间二十分钟，加0.5分
			if (((*timeIter)[2] - (*stuTimeIter)[2])<0.33 && ((*stuTimeIter)[1] - (*timeIter)[1])<0.33)
			{
				s.changeMark(d.getName(), 0.5);
				count++;
			}
			timeIter++;
		}
		stuTimeIter++;
	}
	if (count)
	{
		return true;
	}
	return false;
}

void Match::tagMatch(Student & s, Department d)
{
	vector<string>depFeature = d.getFeature();
	vector<string>stuInterest = s.getInterest();
	vector<string>::iterator interestIter = stuInterest.begin();
	while (interestIter != stuInterest.end())
	{
		for (int i = 0; i< depFeature.size(); i++)
		{
			if (*interestIter == depFeature[i])
			{
				s.changeMark(d.getName(), 1);
			}
		}
		interestIter++;
	}
}

void Match::swap(Student &a, Student &b)
{
	Student c;

	c = a;
	a = b;
	b = c;
}

void Match::order(vector<Student>& s, string key)
{
	vector<Student>::iterator Iti = s.begin();
	vector<Student>::iterator Itj;
	while (Iti != s.end())
	{
		Itj = Iti;
		while (Itj != s.end())
		{

			if (Iti->getMark(key) < Itj->getMark(key))
			{
				swap(*Iti, *Itj);
			}
			Itj++;
		}
		Iti++;
	}
}

vector<Student> Match::getMatchOver()
{
	return this->matchOver;
}

void Match::output()
{
	ofstream matchedResult("output_tendency.txt");

	vector<Department>::iterator depIter = dep.begin();
	while (depIter != dep.end())
	{
		matchedResult << depIter->getName() << ":" << endl;
		vector<Student>stuVec = depIter->getStu();
		vector<Student>::iterator depStuList = stuVec.begin();
		while (stuVec.size() && depStuList != stuVec.end())
		{
			matchedResult << depStuList->getID() << " " << depStuList->getName() << endl;
			depStuList++;
		}
		depIter++;
	}
	matchedResult << "未录取名单:" << endl;
	vector<Student>::iterator stuIter = matchOver.begin();
	while (stuIter != matchOver.end())
	{
		if (!stuIter->getAccess())
		{
			matchedResult << stuIter->getID() << " " << stuIter->getName() << endl;
		}
		stuIter++;
	}

	matchedResult.close();
}