#include"Heap.h"

int main()
{
	Heap<int> hp;
	hp.HeapPush(1);
	hp.HeapPush(2);
	hp.HeapPush(5);
	hp.HeapPush(7);
	hp.HeapPush(3);
	Heap<int> hp1 = hp;
	hp1.HeapPrint();
	hp.HeapPrint();
	return 0;
}