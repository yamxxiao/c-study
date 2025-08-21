#include"List.h"

int main()
{
	List<int> list;
	list.Push_Back(5);
	list.Print();
	list.Push_Front(6);
	list.Push_Front(7);
	list.Print();
	/*list.Pop_Back();
	list.Print()*/;
	list.Pop_Front();
	list.Print();
	list.Find(5);
	list.Erase(5);
	list.Print();
	return 0;
}