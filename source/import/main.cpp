// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <string>
#include <time.h>
#include<iomanip>
#include<algorithm>


using namespace std;

string DepName[20] = { "���", "ʵ����", "�칫��", "������", "���岿", "������", "ѧϰ��", "�߻���", "��֯��", "����",
"�ͷ���", "������", "������", "���²�", "���", "Ȩ�沿", "�Ƽ���", "�ɹ���", "��Ʒ��", "��ϯ��" };

string Interest[20] = { "����", "����", "ƹ����", "��Ӿ", "����", "����", "����Ӱ", "����", "־Ը�", "�쵼��ǿ",
"ѧϰ", "����", "������", "����", "�ĵ�", "�ݽ�", "�Ƽ�", "����", "����", "�߻�" };

string Days[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };


void generateID(ofstream *data)
{
	//����ѧ��
	*data << "1703";//ѧ��ǰ��λ�̶�����  
	*data << setfill('0') << setw(5) << rand() % 100000 << " ";//����λ�������
}


void generateName(ofstream *data)
{
	//��������
	char xing[81] = "��Ǯ��������֣��������������������������ʩ�ſײ��ϻ���κ�ս���л������ˮ���";//��  
	char ming[81] = "����ʤ������Ӣ���˶���������������٭�ٺ��ź�����������ʯѧ��¶�忡ΰԶ��յ��ٽ�";//��  

	int n = rand() % (strlen(xing) / 2) * 2;//���ѡ���ա���λ��  
	*data << xing[n] << xing[n + 1];//һ������ռ�����ֽ�  
	for (int j = 0; j < rand() % 2 + 1; ++j)//���ֵĸ�����1~2��  
	{
		n = rand() % (strlen(ming) / 2) * 2;
		*data << ming[n] << ming[n + 1];
	}
	*data << " ";
}

void generateGpa(ofstream *data)
{ 
	//��������
	*data << (rand() % 999+1) / 100.0 << " ";
}

void generateIntentDep(ofstream *data)
{
	//������Ը����
	int n = rand() % 5+1;
	random_shuffle(&DepName[0], &DepName[20]);  //�������������

	for (int i = 0; i<n; i++)
	{
		*data << DepName[i] << ",";
	}
	*data << " ";
}

void generateTags(ofstream *data)
{
	//�����ص��ǩ
	int n = rand() % 5+1;
	random_shuffle(&Interest[0], &Interest[20]);  //�������������

	for (int i = 0; i<n; i++)
	{
		*data << Interest[i] << ",";
	}
	*data << " ";
}

void generateDate(ofstream *data)
{
	//����ʱ���
	int n = rand() % 5+1;

	random_shuffle(&Days[0], &Days[7]);  //�������������
	for (int i = 0; i < n; i++)
	{
		*data << Days[i] << ",";
		int oHour = (rand() % 4) + 20;   //������ɽ���ʱ���Сʱ
		int oMin = (rand() % 2)*30 ;    //������ɽ���ʱ��ķ��ӣ�30���ӻ���0
		int sHour = rand() % (oHour-19)+19;
		int sMin = (rand() % 2) * 30;
		*data << sHour << ":" << setfill('0') << setw(2)<< sMin << ",";
		*data << oHour << ":" << setfill('0') << setw(2) << oMin << ";";
	}
}

void generateLimit(ofstream *data)
{
	//������������
	int n = rand() % 16;
	*data << n << " ";
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n, m;  //ѧ������n�����Ÿ���m
	m = 20;
	n = 300;
	ofstream data("import.txt");
	data << m << " " << n << endl;
	srand((unsigned int)time(NULL));//�������
	for (int i = 0; i < m; i++)
	{
		data << DepName[i] << " ";
		generateLimit(&data);
		generateTags(&data);
		generateDate(&data);
		data << endl;
	}

	for (int j = 0; j < n; j++)
	{
		generateID(&data);
		generateName(&data);
		generateGpa(&data);
		generateTags(&data);
		generateIntentDep(&data);
		generateDate(&data);
		data << endl;
	}

	data.close();
	return 0;
}

