#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

# include"stdio.h"
#include"stdlib.h"
#include"assert.h"
#include"contact.h"

//����˳���ṹ

//��̬˳���
typedef  peoInfo SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	size_t size;//��Ч���ݸ���
	size_t capacity;//�ռ��С
}SL;

//˳����ʼ��
void SLInit(SL* s);

//˳�������
void SLDestroy(SL* ps);

//���ռ��Ƿ�Ϊ�պ�����
void CheckCapacity(SL* ps);

//��ӡ 
void Print(SL ps);
//ͷ��
void SLPushFront(SL* ps, SLDataType x);

//β��
void SLPushBack(SL* ps, SLDataType x);

//ͷɾ
void SLPopFront(SL* ps);

//βɾ
void SLPopBack(SL* ps);

//ָ��λ�ò���
void Insert(SL* ps, int pos, SLDataType x);

void Erase(SL* ps, int pos);

//int Find(SL* ps, int pos)
//{
//	assert(ps);
//
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == pos)
//		{
//
//			return i;
//		}
//	}
//}
