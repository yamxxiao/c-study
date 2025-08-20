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
STLNode* SLTBuyNode(SLDataType x)//ʵ���Ͼ�������ռ�֮��ֵ����ýڵ�
{
	//������ռ�
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
		//��β�ڵ�
		STLNode* puctr = *phead;//ͷ���

		while (puctr->next)
		{
			puctr = puctr->next;//���½ڵ�
		}
		puctr->next = NewNode;//ԭ����β�ڵ��ָ��βNULL,������º�ָ���½ڵ�
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
		NewNode->next = *phead;//���½ڵ��ָ��ָ��ԭ����ͷ�ڵ�
		*phead = NewNode;//���½ڵ���³�Ϊ�µ�ͷ���
	}
	
}

void Pop_Back(STLNode** phead)
{
	assert(phead && *phead);
	
	//�жϵ�ǰ�ڵ���һ���Ͷ�������
	//һ���ڵ�������ֱ��free����
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		//�ȶ���һ��ǰ�����ͺ�ǽڵ�,�����Ƕ�����ͷ���
		STLNode* perv = *phead;//ǰ��
		STLNode* pail = *phead;//���

		//����
		while (pail->next)
		{
			perv = pail;
			pail = pail->next;
		}

		//�ҵ�֮���ͷ����һ���ڵ��ֵ��Ȼ������Ϊ�գ����ǰ��ָ������Ϊ��
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

void InsertAther(STLNode* pos, SLDataType x)//��Ϊʵ��֮��������Բ���Ҫ����ͷ���Ϊ�յ����
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

void EraseAther(STLNode* pos)//���迼��ͷ���
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