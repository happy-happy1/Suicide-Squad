#include<iostream>
#include"Suicide_title2.h"

using namespace std;

int array[100], num, Templete;

CNode CreateCirCleNode(int n) //往顺序表中读入数据
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

int PushCirCleNode(CNode cn, int m)//顺序表出队
{
	int count = 0, i = 0, num = 0,j=0,Temp[100];
	while (count < cn->last)
	{
		while (num < m && count < cn->last)
		{
			i = i % cn->last + 1;//约瑟夫环的每轮起始位置
			if(cn->data[i - 1])//非0的时候让计数器自加
			{
				num++;
			}
		}
		count++;
		Temp[j++] = cn->data[i - 1];
		cn->data[i - 1] = 0;//出队的时候置为0
		num = 0;//计数器清零
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
