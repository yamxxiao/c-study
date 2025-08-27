#include"Heap.h"

void TestHeap()
{
	int arr[] = { 4,2,8,1,5,6,9,7 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		HPPush(&hp,arr[i]);
	}
	HPPrint(&hp);
}
//¶ÑÅÅÐò
//½µÐò½¨Ð¡¶Ñ
//ÉýÐò½¨´ó¶Ñ
void HeapSort()
{
	int a[] = { 3,6,3,7,31,64,24235,12435,122,2441,11,51,1,7,4 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}
	//´ó¶Ñ
	/*for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		AdjustUP(a, i);
	}*/
	/*HPPrint(&hp);*/
}
int main()
{
	/*HP tree;
	HPInit(&tree);
	HPPush(&tree, 1);
	HPPush(&tree, 2);
	HPPush(&tree, 3);
	HPPush(&tree, 4);
	HPPush(&tree, 5)*/;
	TestHeap();
	/*HPPrint(&tree);*/
	/*HeapSort();*/
	return 0;
}