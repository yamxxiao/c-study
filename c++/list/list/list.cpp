#include "list.h"

int main()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	Print_list(lt);

	Print_const_list(lt);

	return 0;
}