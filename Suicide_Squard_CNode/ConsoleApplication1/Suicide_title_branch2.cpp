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
	int count = 0, i = 0, num = 0,j=0,Temp[100];//count保证下标合理，num计数器，保证每次出队的总人数小于队伍总人数
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
	return Temp[cn->last - 1];//返回最后一个士兵的序号
}

void Suicide_Squard()
{
	int n, m;
	cout << "*********************敢死队问题*********************\n";
	cout << "请输入总人数 n:" << endl;
	cin >> n;
	cout << "请输入间隔人数 m:" << endl;
	cin >> m;
	CNode temp = CreateCirCleNode(n);
	int result = PushCirCleNode(temp, m);
	int Templete =0;//最终求得的幸运数字
	if (result != 0)
	{
		Templete = (n - result + 2) % n;//求出第一个开始的位置
		if (Templete == 0)
		{
			printf("\n要使排长安全则应从第%d号开始报数.\n", n);
		}
		else 
		{
			printf("\n要使排长安全则应从第%d号开始报数.\n", Templete);
		}
	}


}
