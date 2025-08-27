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

//��ʼ��
void HPInit(HP* hp);
//����
void HPDestroy(HP* hp);
//����
void HPPush(HP* hp, HPDataType x);
//ɾ��
void HPPop(HP* hp);
//�п�
bool HPEmpty(HP* hp);
//��ӡ
void HPPrint(HP* hp);
//ȡ��Ԫ��
HPDataType HPTop(HP* hp);
//����
void Swap(HPDataType* Array1, HPDataType* Array2);
//���ϵ�����
void AdjustUP(HPDataType* arr, int child);