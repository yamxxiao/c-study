#include<iostream>

using namespace std;

//实现多态有两个必须条件：必须是基类的指针或者引用调用虚函数，被调用的函数必须是虚函数
//class Person
//{
//public:
//	virtual void BuyTicket() 
//	{
//		cout << "买票——全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票——半价" << endl;
//	}
//};
//void func(Person& ptr)
//{
//	ptr.BuyTicket();
//}
////在重写派生类的时候可以不写virtual 关键字，虽然这样也能构成重写，但是不规范
//
//
////多个子类之间也能形成多态
//class Animal
//{
//public:
//	virtual void talk() const
//	{
//	}
//};
//class Dog : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "汪汪" << std::endl;
//	}
//};
//class Cat : public Animal
//{
//public:
//virtual void talk() const
//{
//std::cout << "(>^ω^<)喵" << std::endl;
//}
//};
//void letsHear(const Animal& animal)
//{
//	animal.talk();
//}
//
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};

//override 和final关键字：override是写在函数后面，帮助用户检查函数是否需要重写，类似assert，final是不让派生类重写这个虚函数。
	
//多态的原理

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
private:
	string _name;
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-打折" << endl; }
private:
	string _id;
};
class Soldier : public Person {
public:
	virtual void BuyTicket() { cout << "买票-优先" << endl; }
private:
	string _codename;
};
void Func(Person* ptr)
{
	// 这⾥可以看到虽然都是Person指针Ptr在调⽤BuyTicket
	// 但是跟ptr没关系，⽽是由ptr指向的对象决定的。
	ptr->BuyTicket();
}
	
int main()
{
	/*Person pr;
	Student st;
	func(pr);
	func(st);*/
	//Cat cat;
	//Dog dog;
	//letsHear(cat);
	//letsHear(dog);
	//B* p = new B;

	//p->test();
	/*Person ps;
	Student st;
	Soldier sr;
	Func(&ps);
	Func(&st);
	Func(&sr);*/

	// 其次多态不仅仅发⽣在派⽣类对象之间，多个派⽣类继承基类，重写虚函数后
	// 多态也会发⽣在多个派⽣类之间。

		string a = "hello world";

		string b = a;

		if (a.c_str() == b.c_str())

		{

			cout << "true" << endl;

		}

		else cout << "false" << endl;

		string c = b;

		c = "";

		if (a.c_str() == b.c_str())

		{

			cout << "true" << endl;

		}

		else cout << "false" << endl;

		a = "";

		if (a.c_str() == b.c_str())

		{

			cout << "true" << endl;

		}

		else cout << "false" << endl;


	return 0;
}