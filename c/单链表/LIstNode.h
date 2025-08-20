#pragma once
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"

typedef int SLDataType;

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}STLNode;

//���ݲ���
STLNode* SLTBuyNode(SLDataType x);
//��ӡ�ڵ�
void Print(STLNode* phead);

//β��
void Push_Back(STLNode** phead, SLDataType x);

//ͷ��

void Push_Front(STLNode** phead, SLDataType x);

//βɾ��
void Pop_Back(STLNode** phead);

//ͷɾ
void Pop_Front(STLNode** phead);

//����
STLNode* Find(STLNode* phead, SLDataType x);

//��posλ��֮ǰ����
void Insert(STLNode** phead, STLNode* pos, SLDataType x);

//��posλ��֮�����
void InsertAther(STLNode* pos, SLDataType x);

//��posλ��֮ǰɾ��
void Erase(STLNode**phead,STLNode* pos);
//��posλ��֮��ɾ��
void EraseAther(STLNode* pos);
//����
void Destroy(STLNode* phead);