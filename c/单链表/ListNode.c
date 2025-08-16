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