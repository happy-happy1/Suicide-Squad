#include<iostream>
#include"Suicide_title2.h"

using namespace std;

int array[100], num, Templete;

CNode CreateCirCleNode(int n) //��˳����ж�������
{
	CNode cn;
	cn = new CirCleNode;
	int i;
	for (i = 0; i < n; i++)
	{
		cn->data[i] = i + 1;
	}
	cn->last = n;
	return cn;
}

int PushCirCleNode(CNode cn, int m)//˳������
{
	int count = 0, i = 0, num = 0,j=0,Temp[100];
	while (count < cn->last)
	{
		while (num < m && count < cn->last)
		{
			i = i % cn->last + 1;//Լɪ�򻷵�ÿ����ʼλ��
			if(cn->data[i - 1])//��0��ʱ���ü������Լ�
			{
				num++;
			}
		}
		count++;
		Temp[j++] = cn->data[i - 1];
		cn->data[i - 1] = 0;//���ӵ�ʱ����Ϊ0
		num = 0;//����������
	}
	for (j = 0; j < cn->last; j++)
	{
		printf("--%d", Temp[j]);
	}
	return Temp[cn->last - 1];
}

void Suicide_Squard()
{
	int n, m;
	cout << "zong ren shu n:" << endl;
	cin >> n;
	cout << "di m ge qu zhi xing ren wu m:" << endl;
	cin >> m;
	CNode temp = CreateCirCleNode(n);
	PushCirCleNode(temp, m);
}
