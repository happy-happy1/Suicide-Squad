// Suicide_Squard_branch1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Suicide_title.h"
using namespace std;

void Suicide_Squard()
{
	int n, m;
	node* head, * p, * tail, * q;	//设置head，p，tail，q指针
	head = new node;
	head->next = NULL;			//初始化链表
	tail = head;

	cout << "从1号开始数数：\n" << endl;
	cout << "请输入n,n代表总人数：" << endl;
	cin >> n;
	cout << "请输入m,m代表每数到第m个就去执行任务" << endl;
	cin >> m;

	for (int i = 1; i <= n; i++)		//链表后插法，初始一个表格，将尾指针指向表格
	{
		p = new node;
		p->next = NULL;
		p->data = i;
		tail->next = p;
		tail = p;
	}

	tail->next = head->next;		//将链表形成一个圈
	int ans = 1;			//初始化若n=1时，答案为1
	q = head;		
	p = head->next;

	while (n != 1)				//在不剩下最后一个人（即n！=1）的时候运行
	{
		if (ans % m != 0)		//把ans作为计数器，，若符合第m的时候（ans一直连加）派第m人前往
		{
			p = p->next;
			q = q->next;
		}
		else {
			q->next = p->next;
			free(p);
			p = q->next;
			n--;
		}
		ans++;
	}
	cout << "幸运的是："<<p->data<<"号" << endl;
	cout << "因此应在从一号开始数数的基础上倒退" << p->data - 1 << "位" << endl;
	cout << "开始数数，可保证排长最后一个留下" << endl;
	cout << "任意键关闭";
	cin.get();
	cin.get();
}