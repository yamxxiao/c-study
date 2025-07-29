#include<iostream>
#include<vector>

using namespace std;

class Person
{
public:
	//进入校园的身份认证
void identity()
	{
		cout << "void identity()" << _name << endl;
	}

protected:
	string _name = "张三";
	string _address;
	string _tel;
	int _age = 18;
};

class Student : public Person
{
public:
	void study()
	{

	}

protected:
	int _studi;//学号
};

class Teacher : public Person
{
public:
	void teaching()
	{

	}

protected:
	string	title;//职称
};
//1. 基类private成员在派⽣类中⽆论以什么⽅式继承都是不可⻅的。这⾥的不可⻅是指基类的私有成员
//还是被继承到了派⽣类对象中，但是语法上限制派⽣类对象不管在类⾥⾯还是类外⾯都不能去访问
//它。
//2. 基类private成员在派⽣类中是不能被访问，如果基类成员不想在类外直接被访问，但需要在派⽣类
//中能访问，就定义为protected。可以看出保护成员限定符是因继承才出现的。
//3. 实际上⾯的表格我们进⾏⼀下总结会发现，基类的私有成员在派⽣类都是不可⻅。基类的其他成员
//在派⽣类的访问⽅式 == Min(成员在基类的访问限定符，继承⽅式)，public > protected >
//private。
//4. 使⽤关键字class时默认的继承⽅式是private，使⽤struct时默认的继承⽅式是public，不过最好显
//⽰的写出继承⽅式。
 
namespace yamx
{
	template<class T>
	class Stack : public std::vector<T>
	{
	public:
		void push(const T& x)
		{
			vector<T>::push_back(x);
		}

		void pop()
		{
			vector<T>::pop_back();
		}

		const T& top()
		{
			return vector<T>::back();
		}

		bool empty()
		{
			return vector<T>::empty(); 
		}
	};
	//父类是类模板时，需要指定一下，否则会报错

}