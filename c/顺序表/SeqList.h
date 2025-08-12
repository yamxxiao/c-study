#pragma once
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"
//定义顺序表结构

//动态顺序表
typedef size_t SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	size_t size;//有效数据个数
	size_t capacity;//空间大小
}SL;

//顺序表初始化
void SLInit(SL* s)
{
	s->arr = NULL;
	s->size = 0, s->capacity = 0;
}

//顺序表销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}

	ps->capacity = ps->size = 0;
}

//检查空间是否为空和扩容
void CheckCapacity(SL* ps)
{
	if (ps->capacity = ps->size)
	{
		//申请空间
		//用Realloc函数申请空间
		//先创建一个临时变量NewCapacity来接收空间和Tmp临时变量，目的是为了防止空间扩容失败

		SLDataType NewCapacity = ps->capacity == 0 ? 2 : 4 * ps->capacity;
		SLDataType* Tmp = (SLDataType*)realloc(ps->arr, NewCapacity * sizeof(SLDataType));

		if (Tmp == NULL)
		{
			perror("扩容失败，退出！");
			exit(1);
		}
		//空间申请成功
		ps->capacity = NewCapacity;
		ps->arr = Tmp;
	}
}

//打印 
void Print(SL ps)
{
	for (int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.arr[i]);
	}
	printf("\n");
}
//头插
	void SLPushFront(SL * ps, SLDataType x)
	{
		assert(ps);
		//判断空间是否为空
		CheckCapacity(ps);

		for (int i = ps->size; i > 0; i--)
		{
			ps->arr[i] = ps->arr[i - 1];
		}
		ps->arr[0] = x;
		ps->size++;
	}

//尾插
	void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//判断顺序表传空
	//判断空间是否为空
		CheckCapacity(ps);
		ps->arr[ps->capacity++] = x;
}

//头删
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

//尾删
void SLPopBack(SL* ps)
{
		assert(ps);
	assert(ps->size);//顺序表不能为空，否则会报错
	ps->size--;
}