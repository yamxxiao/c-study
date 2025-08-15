#include"SqList.h"

int main()
{
	SeList s1;

	s1.Insert(1);
	s1.Insert(2);
	s1.Insert(3);
	s1.Insert(4);
	s1.Insert(5);
	s1.Print();
	s1.PushBack(6);
	s1.Print();
	s1.PopFront();
	s1.Print();
	s1.PopBack();
	s1.Print();
	SeList s2 = s1;
	s2.Print();
	return 0;
}