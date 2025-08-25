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

//��ʼ��
void QueueInit(Queue* que);

//����
void QueueDestroy(Queue* que);

//���
void QueuePush(Queue* que, QLDataType x);

//����
void QueuePop(Queue* que);

//������ЧԪ�ظ���
int QueueSize(Queue* que);

//���ض�ͷ�Ͷ�β
QLDataType QueueFront(Queue* que);
QLDataType QueueBack(Queue* que);

//�п�
bool QueueEmpty(Queue* que);

void Print(Queue* que);