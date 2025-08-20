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

//��ʼ��

void LTInit(LTNode** phead);

//��ӡ
void Print(LTNode* phead);
//β��,��Ϊ���ı��ڱ�λ�ڵ㣬���Դ���һ��ָ�뼴��
void LTPush_Back(LTNode* phead, ListNodeType x);

//ͷ��
void LTPush_Front(LTNode* phead,ListNodeType x);

//βɾ
void LTPop_Back(LTNode* phead);

//ͷɾ
void LTPop_Front(LTNode* phead);

//��posλ��֮�����
void LTInsert(LTNode* pos, ListNodeType x);

//��posλ��ɾ��
void Erase(LTNode* pos);

//����
LTNode* Find(LTNode* pos, ListNodeType x);

//����
void LTDestroy(LTNode* phead);