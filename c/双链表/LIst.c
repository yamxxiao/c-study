#include"List.h"

//申请空间
LTNode* BuyNode(ListNodeType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));

	if (node == NULL)
	{
		printf("malloc fail!");
		exit(1);
	}

	node->data = x;
	node->next = node->perv = node;

	return node;
}

void LTInit(LTNode** phead)
{
	//先给双链表一个哨兵位
	*phead = BuyNode(-1);
}
void LTPush_Back(LTNode* phead, ListNodeType x)
{
	assert(phead);

	LTNode* NewNode = BuyNode(x);

	NewNode->perv = phead->perv;
	NewNode->next = phead;

	phead->perv->next = NewNode;
	phead->perv = NewNode; 
	
}

void Print(LTNode* phead)
{
	assert(phead);

	LTNode* puctr = phead->next;

	while (puctr != phead)
	{
		printf("%d->", puctr->data);
		puctr = puctr->next;
	}
	printf("NULL");
	printf("\n");
}

void LTPush_Front(LTNode* phead, ListNodeType x)
{
	assert(phead);

	LTNode* NewNode = BuyNode(x);

	NewNode->perv = phead;
	NewNode->next = phead->next;

	phead->next->perv = NewNode;
	phead->next = NewNode; 
}

void LTPop_Back(LTNode* phead)
{
	assert(phead && phead->next != phead);

	LTNode* del = phead->perv;

	del->perv->next = phead;
	phead->perv = del->perv;

	free(del); 
	del = NULL;
}

void LTPop_Front(LTNode* phead)
{
	assert(phead && phead->next != phead);

	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->perv = phead;
	free(del);
	del = NULL;
} 

LTNode* Find(LTNode* phead, ListNodeType x)
{
	LTNode* puctr = phead->next;

	while (puctr != phead)
	{
		if (puctr->data == x)
		{
			return puctr;
		}
		puctr = puctr->next;
	}

	//否则没有找到
	return NULL;
}
void LTInsert(LTNode* pos, ListNodeType x)
{
	assert(pos);
	LTNode* NewNode= BuyNode(x);

	NewNode->perv = pos;
	NewNode->next = pos->next;

	pos->next->perv = NewNode;
	pos->next = NewNode; 
}

void Erase(LTNode* pos)
{
	assert(pos);

	pos->next->perv = pos->perv;
	pos->perv->next = pos->next;
	
	free(pos);
	pos = NULL;
}

void LTDestroy(LTNode* phead)
{
	LTNode* puctr = phead->next;

	while (puctr != phead)
	{
		free(puctr);
		puctr = puctr->next;
	}

	free(phead);
	phead = NULL;
}