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

//扩容插入
STLNode* SLTBuyNode(SLDataType x);
//打印节点
void Print(STLNode* phead);

//尾插
void Push_Back(STLNode** phead, SLDataType x);

//头插

void Push_Front(STLNode** phead, SLDataType x);

//尾删除
void Pop_Back(STLNode** phead);

//头删
void Pop_Front(STLNode** phead);

//查找
STLNode* Find(STLNode* phead, SLDataType x);

//在pos位置之前插入
void Insert(STLNode** phead, STLNode* pos, SLDataType x);

//在pos位置之后插入
void InsertAther(STLNode* pos, SLDataType x);

//在pos位置之前删除
void Erase(STLNode**phead,STLNode* pos);
//在pos位置之后删除
void EraseAther(STLNode* pos);
//销毁
void Destroy(STLNode* phead);