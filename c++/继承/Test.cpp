#include"Test.h"

int main()
{
	/*Student s1;
	Teacher t1;

	s1.identity();
	t1.identity();*/
	/*yamx::Stack<int> s1;
=======
	yamx::Stack<int> s1;
>>>>>>> e504793498c953af4f1a670ff1e3d6a317107999
=======
	yamx::Stack<int> s1;
>>>>>>> e504793498c953af4f1a670ff1e3d6a317107999
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(3);
	s1.push_back(4);
	s1.push_back(5);

	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
<<<<<<< HEAD
<<<<<<< HEAD
	}*/
	//派生类可以赋值给基类的指针和引用，基类不能赋值给派生类。
	//Student s1;
	//Person* p1 = &s1;
	//Person& p2 = s1;

	//Person p1 = s1;

	//2.基类对象不能赋值给派⽣类对象，这⾥会编译报错
	/*s1 = p1;*/

	/*xiao::Student s1;
	xiao::Person p1;*/

	/*s1.print()*/;//这里的结果为，调用了自己的同名函数，原因是派⽣类和基类中有同名成员，派⽣类成员将屏蔽基类对同名成员的直接访问，这种情况叫隐藏。
	//（在派⽣类成员函数中，可以使⽤ 基类::基类成员 显⽰访问）
	//p1. print();
	//在调用的同名函数前加上父类的作用域就可以调用父类的同名函数
	/*s1.xiao::Person::print();*/
	Test::Student s1("晓晓",12);
	Test::Student s2(s1);

	return 0;
}