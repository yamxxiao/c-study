#include"Stack.h"

//��ʼ��
void STInit(ST* st)
{
	st->arr = NULL;
	st->top = st->capacity = 0;
}

//����
void STDestroy(ST* st)
{
	free(st);
	st->arr = NULL;
	st->top = 0;
	st->capacity = 0;
}

//��ջ
void STPush(ST* st, SLTDataType x)
{
	assert(st);

	int NewCapacity = st->capacity == 0 ? 4 : 2 * st->capacity;

	SLTDataType* tmp = (SLTDataType*)realloc(st->arr, NewCapacity * sizeof(SLTDataType));

	if (tmp == NULL)
	{
		printf("��ջʧ�ܣ�");
		exit(1);
	}
	st->arr = tmp;
	st->capacity = NewCapacity;


	st->arr[st->top] = x;
	st->top++;
}
//��ջ
void STPop(ST* st)
{
	assert(st && st->top && st->top > 0);
	st->top--;
}
//�п�
bool STEmpty(ST* st)
{
	assert(st);
	return st->top == 0;
}
//ջ��Ԫ��
SLTDataType* STTop(ST* st)
{
	assert(st && st->top > 0);

	return st->arr[st->top - 1];
}
//��Ч����
int STSize(ST* st)
{
	return st->top;
}

//��ӡ
void Print(ST* st)
{
	while (!STEmpty(st))
	{
		printf("%d ", STTop(st));
		STPop(st);
	}
}