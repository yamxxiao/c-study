#include"stdio.h"
#include"stdlib.h"
#include"assert.h"

typedef int ListNodeType;
struct ListNode
{
	ListNodeType data;
	struct ListNode* next;
	struct ListNode* perv;
};

typedef struct ListNode LTNode;

//初始化

void LTInit(LTNode** phead);

//打印
void Print(LTNode* phead);
//尾插,因为不改变哨兵位节点，所以传入一级指针即可
void LTPush_Back(LTNode* phead, ListNodeType x);

//头插
void LTPush_Front(LTNode* phead,ListNodeType x);

//尾删
void LTPop_Back(LTNode* phead);

//头删
void LTPop_Front(LTNode* phead);

//在pos位置之后插入
void LTInsert(LTNode* pos, ListNodeType x);

//在pos位置删除
void Erase(LTNode* pos);

//查找
LTNode* Find(LTNode* pos, ListNodeType x);

//销毁
void LTDestroy(LTNode* phead);