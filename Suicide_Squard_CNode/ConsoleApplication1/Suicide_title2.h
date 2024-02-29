#pragma once
#ifndef _SUICIDE_TITLE2_H_	//如果存在头文件叫做_SUICIDE_TITLE2_H_，则后面代码失效
#define _SUICIDE_TITLE2_H_	//定义我们的头文件叫做_SUICIDE_TITLE2_H_

//ifndef  if not define


typedef struct CirCleNode {
	int data[100];
	int last;//顺序表的大小
}*CNode;

void Suicide_Squard();

#endif