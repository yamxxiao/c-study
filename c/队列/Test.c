#include"queue.h"

int main()
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);
	QueuePush(&que, 5);

	Print(&que);
	QueuePop(&que);
	Print(&que);
	return 0;
}