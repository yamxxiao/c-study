#include"Stack.h"

int main()
{

	ST st;
	STInit(&st);

	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);

	Print(&st);
	printf("%d\n", STTop(&st));
	STTop(&st);
	return 0;
}