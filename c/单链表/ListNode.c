#include"LIstNode.h"

void Print(STLNode* phead)
{
	STLNode* puctr = phead;

	while (puctr!=NULL)
	{
		printf("%d->", puctr->data);
		puctr = puctr->next;
	}
	printf("NULL\n");
}
STLNode* SLTBuyNode(SLDataType x)//实际上就是申请空间之后将值放入该节点
{
	//先申请空间
	STLNode* NewNode = (STLNode*)malloc(sizeof(STLNode));

	if (NewNode == NULL)
	{
		printf("malloc fail!");
		exit(1);
	}

	NewNode -> data = x;
	NewNode->next = NULL;

	return NewNode;
}
void Push_Back(STLNode**phead, SLDataType x)
{
	assert(phead);
	STLNode* NewNode=SLTBuyNode(x);
	if (*phead == NULL)
	{	
		*phead = NewNode;
	}
	else
	{ 
		//找尾节点
		STLNode* puctr = *phead;//头结点

		while (puctr->next)
		{
			puctr = puctr->next;//更新节点
		}
		puctr->next = NewNode;//原本的尾节点的指针尾NULL,这里更新后指向新节点
	}
}


void Push_Front(STLNode** phead, SLDataType x)
{
	assert(phead);
	STLNode* NewNode= SLTBuyNode(x);
	if (*phead == NULL)
	{
		*phead = NewNode;
	}
	else
	{
		NewNode->next = *phead;//将新节点的指针指向原来的头节点
		*phead = NewNode;//将新节点更新成为新的头结点
	}
	
}

void Pop_Back(STLNode** phead)
{
	assert(phead && *phead);
	
	//判断当前节点有一个和多个的情况
	//一个节点的情况：直接free就行
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		//先定义一个前驱结点和后记节点,让他们都等于头结点
		STLNode* perv = *phead;//前驱
		STLNode* pail = *phead;//后继

		//遍历
		while (pail->next)
		{
			perv = pail;
			pail = pail->next;
		}

		//找到之后，释放最后一个节点的值，然后重置为空，最后将前驱指针重置为空
		free(pail);
		pail = NULL;
		perv->next = NULL;
	}
}

void Pop_Front(STLNode** phead) 
{
	assert(phead && *phead);
	
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		STLNode* pail = (*phead)->next;
		free(*phead);
		/**phead = NULL;*/
		*phead = pail;
	}
}

STLNode* Find(STLNode* phead, SLDataType x)
{
	STLNode* pucr = phead;

	while (pucr)
	{
		if (pucr->data == x)
		{
			return pucr;
		}
		pucr = pucr->next;
	}
	return NULL;
}


void Insert(STLNode** phead, STLNode* pos, SLDataType x)
{
	assert(phead && *phead);
	assert(pos);
	STLNode* NewNode = SLTBuyNode(x);
	if (pos == *phead)
	{
		Push_Front(phead, x);
	}
	else
	{
		STLNode* perv = *phead;
		while (perv->next != pos)
		{
			perv = perv->next;
		}
		NewNode->next = pos;
		perv->next = NewNode;
	}
}

void InsertAther(STLNode* pos, SLDataType x)//因为实在之后插入所以不需要考虑头结点为空的情况
{
	assert(pos);
	STLNode* NewNode = SLTBuyNode(x);

	STLNode* _next = pos->next;

	/*NewNode->next = pos->next;*/
	NewNode->next = _next;
	pos->next = NewNode;
}

void Erase(STLNode**phead,STLNode* pos)
{
	assert(phead && *phead);
	assert(pos);

	if (pos == *phead)
	{
		Pop_Front(pos);
	}
	else
	{
		STLNode* prev = *phead;

		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void EraseAther(STLNode* pos)//无需考虑头结点
{
	assert(pos&& pos->next);
	STLNode* tail = pos->next;
	pos->next = pos->next->next;
	free(tail);
}

void Destroy(STLNode** phead)
{
	STLNode* pail = *phead;
	
	while (pail->next != NULL)
	{
		STLNode* next = pail->next;
		free(pail);
		pail =next;
	}
	*phead = NULL;
}