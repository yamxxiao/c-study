#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

# include"stdio.h"
#include"stdlib.h"
#include"assert.h"
#include"contact.h"

//定义顺序表结构

//动态顺序表
typedef  peoInfo SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	size_t size;//有效数据个数
	size_t capacity;//空间大小
}SL;

//顺序表初始化
void SLInit(SL* s);

//顺序表销毁
void SLDestroy(SL* ps);

//检查空间是否为空和扩容
void CheckCapacity(SL* ps);

//打印 
void Print(SL ps);
//头插
void SLPushFront(SL* ps, SLDataType x);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//头删
void SLPopFront(SL* ps);

//尾删
void SLPopBack(SL* ps);

//指定位置插入
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
