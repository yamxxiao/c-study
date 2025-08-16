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

//À©ÈÝ²åÈë
STLNode* SLTBuyNode(SLDataType x);
//´òÓ¡½Úµã
void Print(STLNode* phead);

//Î²²å
void Push_Back(STLNode** phead, SLDataType x);

//Í·²å

void Push_Front(STLNode** phead, SLDataType x);

//Î²É¾³ý
void Pop_Back(STLNode** phead);

//Í·É¾
void Pop_Front(STLNode** phead);