#include"stdio.h"
#include"stdlib.h"
#include"stdbool.h"
#include"assert.h"

typedef int SLTDataType;
typedef struct Stack
{
	SLTDataType* arr;
	int top;
	int capacity;
}ST;

//��ʼ��
void STInit(ST* st);

//����
void STDestroy(ST* st);

//��ջ
void STPush(ST* st, SLTDataType x);

//��ջ
void STPop(ST* st);

//�п�
bool STEmpty(ST* st);

//ջ��
SLTDataType* STTop(ST* st);

//��Ч����
int STSize(ST* st);

//��ӡ
void Print(ST* st);
