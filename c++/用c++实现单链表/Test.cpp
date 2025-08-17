#include"SList.h"

int main()
{
    SList<int> list;
  /*  int a = 10, b = 20, c = 30;*/
    list.Push_Back(1);
    list.Push_Back(2);
    list.Push_Front(3);
   /* list.Pop_Back();*/
  /*  cout << "Initial List: ";*/
    list.Print();
    list.Pop_Back();
    list.Print();
    list.Pop_Front();
    list.Print();
    SList<int> list1(list);
    list1.Print();
	return 0;
}