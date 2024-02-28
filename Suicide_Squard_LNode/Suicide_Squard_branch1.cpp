// Suicide_Squard_branch1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Suicide_title.h"
using namespace std;

void Suicide_Squard()
{
	int n, m;
	node* head, * p, * tail, * q;
	head = new node;
	head->next = NULL;
	tail = head;

	cout << "从1号开始数数：\n" << endl;
	cout << "请输入n,n代表总人数：" << endl;
	cin >> n;
	cout << "请输入m,m代表每数到第m个就去执行任务" << endl;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		p = new node;
		p->next = NULL;
		p->data = i;
		tail->next = p;
		tail = p;
	}

	tail->next = head->next;
	int ans = 1;
	q = head;
	p = head->next;

	while (n != 1)
	{
		if (ans % m != 0)
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