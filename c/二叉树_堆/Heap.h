#pragma once
#include"stdio.h"
#include"stdlib.h"
#include"assert.h"
#include"stdbool.h"

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}HP;

//初始化
void HPInit(HP* hp);
//销毁
void HPDestroy(HP* hp);
//插入
void HPPush(HP* hp, HPDataType x);
//删除
void HPPop(HP* hp);
//判空
bool HPEmpty(HP* hp);
//打印
void HPPrint(HP* hp);
//取顶元素
HPDataType HPTop(HP* hp);
//交换
void Swap(HPDataType* Array1, HPDataType* Array2);
//向上调整法
void AdjustUP(HPDataType* arr, int child);