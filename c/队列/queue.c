#include"queue.h"

//��ʼ��
void QueueInit(Queue* que)
{
	que->phead = NULL;
	que->ptail = NULL;
	que->size = 0;
}

//����
void QueueDestroy(Queue* que)
{
	assert(que);
	Node* next = que->phead->next;

	while (que->phead)
	{
		free(que->phead);
		que->phead = next;
	}
	que->phead = que->ptail = NULL;
	que->size = 0;
}

//���(������β����)
void QueuePush(Queue* que, QLDataType x)
{
	assert(que);
	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("fail!\n");
		exit(1);
	}
	
	NewNode->next = NULL;
	NewNode->val = x;

	if (que->ptail == NULL)
	{
		que->ptail=que->phead = NewNode;
	}
	else
	{
		que->ptail->next = NewNode;
		que->ptail = NewNode;
	}
	que->size++;

}

//����(ͷɾ)
void QueuePop(Queue* que)
{
	assert(que);
	assert(que->size!=0);
	if (que->phead == NULL)
	{
		free(que->phead);
		 que->ptail = NULL;
	}
	else//����ڵ�
	{
		Node* next = que->phead->next;
		free(que->phead);
		que->phead = next;
	}
	que->size--;
}

//������ЧԪ�ظ���
int QueueSize(Queue* que)
{
	assert(que);
	return que->size;
}

//���ض�ͷ�Ͷ�β
QLDataType QueueFront(Queue* que)
{
	assert(que);
	assert(que->phead);
	return que->phead->val;
}

QLDataType QueueBack(Queue* que)
{
	assert(que);
	assert(que->ptail);
	return que->ptail->val;
}

//�п�
bool QueueEmpty(Queue* que)
{
	assert(que);

	return que->size == 0;
}

void Print(Queue* que)
{
	Node* cur = que->phead;
	while (cur!=NULL)
	{
		Node* next = cur->next;
		printf("%d ", cur->val);
		cur = next;
	}
	printf("\n");
}