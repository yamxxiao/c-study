#include"Queue.h"

int main()
{
	Queue<int> que;
	que.Push(1);
	que.Push(2);
	que.Push(3);
	que.Push(4);
	que.Push(5);
	que.Print();
	que.Pop();
	que.Print();
	Queue<int> que1 = que;
	que1.Print();
	return 0;
}