


#include "stdafx.h"
#include"Match.h"



void Match::start()
{
	//����5��־Ը
	for (int i = 0; i < 5; i++)
	{
		//ѧ���������
		vector<Student>::iterator stuIter = stu.begin();
		while (stuIter != stu.end())
		{
			//ƥ��ѧ����i־Ը���ţ����ж�Ӧ��ƥ������
			string intent = stuIter->getIntentDepart()[i];
			if (intent == "")
			{
				stuIter->setNotMatch();
				matchOver.push_back(*stuIter);
				stuIter = stu.erase(stuIter);
				continue;
			}
			vector<Department>::iterator Iter = dep.begin();
			//���ҵ�ѧ����i־Ը���Ŷ���
			while (Iter != dep.end())
			{
				Iter->getName();
				if (Iter->getName() == intent)
				{
					break;
				}
				Iter++;
			}
			//��������Ϊ�ɼ���һ��������ƥ�����
			stuIter->changeMark(intent, stuIter->getGpa());
			//���ѧ������ʱ��Ͳ��Żʱ����ȫ��ƥ����������㣬ƥ����һѧ����־Ը
			timeMatch(*stuIter, *Iter);

			//ƥ����Ȥ��ǩ�����
			tagMatch(*stuIter, *Iter);
			//ѧ��δƥ��־Ը��һ
			stuIter->setNotMatch();
			stuIter++;
		}
		vector<Department>::iterator depIter = dep.begin();
		//�ڵ�i��־Ը�£����ղ�ͬ���Ŷ�ѧ���ֱ���з�������ȡ��ÿ�����Ŷ�Ӧ�ĳɼ������ͬѧ���벿��
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
				//���ѧ������־Ը���ƥ�䣬��ת��ѧ��������matchOver����
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
			//ƥ��ѧ������ʱ���볣��ʱ�������
			if ((*stuTimeIter)[0] != (*timeIter)[0])
			{
				timeIter++;
				continue;
			}
			//��ѧ������ʱ����������ȫ����ĳ������ʱ�䣬��2��
			if ((*stuTimeIter)[1] <= (*timeIter)[1] && (*stuTimeIter)[2] >= (*timeIter)[2])
			{
				s.changeMark(d.getName(), 2);
				count++;
			}
			//��ѧ������ʱ�����޴���ĳ������ʱ�䣬���޲�����������ʼʱ���Сʱ����1��
			if (((*stuTimeIter)[1] - (*timeIter)[1])<0.5 && (*stuTimeIter)[2] >= (*timeIter)[2])
			{
				s.changeMark(d.getName(), 1);
				count++;
			}
			//��ѧ������ʱ����������ĳ������ʱ�䣬���޲����ڳ�������ʱ���Сʱ����1��
			if (((*timeIter)[2] - (*stuTimeIter)[2])<0.5 && (*stuTimeIter)[1] <= (*timeIter)[1])
			{
				s.changeMark(d.getName(), 1);
				count++;
			}
			//��ѧ������ʱ����������ĳ������ʱ���ʮ���ӣ���������ĳ������ʱ���ʮ���ӣ���0.5��
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
	matchedResult << "δ¼ȡ����:" << endl;
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