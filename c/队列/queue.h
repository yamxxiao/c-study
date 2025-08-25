#pragma once
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"
#include"stdbool.h"

typedef int QLDataType;

typedef struct QLNode
{
	struct QLNode* next;
	QLDataType val;
}Node;

typedef struct Queue
{
	Node* phead;
	Node* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* que);

//销毁
void QueueDestroy(Queue* que);

//入队
void QueuePush(Queue* que, QLDataType x);

//出队
void QueuePop(Queue* que);

//队列有效元素个数
int QueueSize(Queue* que);

//返回队头和队尾
QLDataType QueueFront(Queue* que);
QLDataType QueueBack(Queue* que);

//判空
bool QueueEmpty(Queue* que);

void Print(Queue* que);