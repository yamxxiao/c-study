#include"LIst.h"

int main()
{
	LTNode* list=NULL;
	LTInit(&list);
	LTPush_Back(list, 1);
	LTPush_Back(list, 2);
	LTPush_Back(list, 3);
	LTPush_Back(list, 4);
	LTPush_Back(list, 5);
	LTPush_Back(list, 6);
	LTPush_Front(list, 8);
	Print(list);
	LTPop_Back(list);
	Print(list);
	LTPop_Front(list);
	Print(list);
	LTNode* find=Find(list, 3);
	if (find > 0)
	{
		printf("找到了!\n");
	}
	else
	{
		printf("没有找到!\n");
	}
	LTInsert(find, 66);
	Print(list);
	Erase(find);
	Print(list);

	/*LTInit(&list);*/
	return 0;
}