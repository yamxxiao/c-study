#pragma once
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"
//����˳���ṹ

//��̬˳���
typedef size_t SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	size_t size;//��Ч���ݸ���
	size_t capacity;//�ռ��С
}SL;

//˳����ʼ��
void SLInit(SL* s)
{
	s->arr = NULL;
	s->size = 0, s->capacity = 0;
}

//˳�������
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}

	ps->capacity = ps->size = 0;
}

//���ռ��Ƿ�Ϊ�պ�����
void CheckCapacity(SL* ps)
{
	if (ps->capacity = ps->size)
	{
		//����ռ�
		//��Realloc��������ռ�
		//�ȴ���һ����ʱ����NewCapacity�����տռ��Tmp��ʱ������Ŀ����Ϊ�˷�ֹ�ռ�����ʧ��

		SLDataType NewCapacity = ps->capacity == 0 ? 2 : 4 * ps->capacity;
		SLDataType* Tmp = (SLDataType*)realloc(ps->arr, NewCapacity * sizeof(SLDataType));

		if (Tmp == NULL)
		{
			perror("����ʧ�ܣ��˳���");
			exit(1);
		}
		//�ռ�����ɹ�
		ps->capacity = NewCapacity;
		ps->arr = Tmp;
	}
}

//��ӡ 
void Print(SL ps)
{
	for (int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.arr[i]);
	}
	printf("\n");
}
//ͷ��
	void SLPushFront(SL * ps, SLDataType x)
	{
		assert(ps);
		//�жϿռ��Ƿ�Ϊ��
		CheckCapacity(ps);

		for (int i = ps->size; i > 0; i--)
		{
			ps->arr[i] = ps->arr[i - 1];
		}
		ps->arr[0] = x;
		ps->size++;
	}

//β��
	void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//�ж�˳�����
	//�жϿռ��Ƿ�Ϊ��
		CheckCapacity(ps);
		ps->arr[ps->capacity++] = x;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->arr[0] = -1;
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//βɾ
void SLPopBack(SL* ps)
{
		assert(ps);
	assert(ps->size);//˳�����Ϊ�գ�����ᱨ��
	ps->size--;
}