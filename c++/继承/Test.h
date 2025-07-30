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

namespace xiao
{
	//派生类和基类的隐藏问题
	class Person
	{
	public:
		void print()
		{
			cout << "Person->print()" << endl;
		}
	private:
		string _name;
		size_t age;
		string _address;
	};

	class Student : public Person
{
	public:
		void print()
		{
			cout << "Student->print()" << endl;
		}
	private:
		int _id;
};

	class A
	{
	public:
		void func()
		{
			cout << "A->func()" << endl;
		}
	};

	class B : public A
	{
		void func(int i)
		{
			cout << "A->func()" << endl;
		}
	};

	//提问：上述两个A类和B类中的func同名函数关系中，属于重载还是隐藏？
	//答案：隐藏。
	//原因是，两个函数重载除了同名外，还要作用于同一个作用域。因为类与类是作用在不同作用域的，所以只能构成隐藏关系。		
}
//派生类的默认成员函数
//namespace Test
//{
//	 class Person
//		 {
//	 public:
//		 Person(const string name) :_name(name) {}
//		~Person()
//		{
//			cout << "~Person()" << endl;
//		}
//	protected:
//		string _name; // 姓名
//	};
    // 修改Test::Person类，添加默认构造函数
namespace Test
{
      class Person
      {
      public:
       Person(const string name) :_name(name) {}
       Person() : _name("") {} // 添加默认构造函数
						~Person()
						{
							cout << "~Person()" << endl;
						}
					protected:
						string _name; // 姓名
	  };
	  class Student : public Person
	  {
	  public:
		  Student(const string name, int num) :Person(name), _num(num) {} // 显式调用父类构造
		  Student(const Student& s) :Person(s), _num(s._num)
		  {
			  cout << "调用拷贝构造" << endl;
		  }
		  Student& operator = (const Student& s)
		  {
			  cout << "Student& operator= (const Student& s)" << endl;
			  if (this != &s)
			  {
				  Person::operator =(s);
				  _num = s._num;
			  }
			  return *this;
		  }
		  ~Student()//派⽣类的析构函数会在被调⽤完成后⾃动调⽤基类的析构函数清理基类成员。因为这样才能保证派
			 // ⽣类对象先清理派⽣类成员再清理基类成员的顺序。
			  //子类的析构和父类的析构也构成隐藏关系 
		  {
			  cout << "~Student()" << endl;
		  }
	  protected:
		  int _num = 0; //学号
	  };
}
	//默认生成构造函数的行为
	//1.内置类型->不确定
	//2.自定义类型->调用默认构造
	//3.继承父类成员看做一个整体对象，要求调用父类的默认构造

	//子类的拷贝构造必须调用父类的拷贝构造完成父类的拷贝初始化

//使用关键字final可以让类不被继承，友元关系不能被继承

//虚继承
namespace Test1
{
	class Person
	{
	public:
		string _name; // 姓名
		/*int _tel;
	
		int _age;
		string _gender;
		string _address;*/
		// ...
	};
	// 使⽤虚继承Person类
	class Student : virtual public Person
	{
	protected:
		int _num; //学号
	};
	// 使⽤虚继承Person类
	class Teacher : virtual public Person
	{
	protected:
		int _id; // 职⼯编号
	};
	// 教授助理
	class Assistant : public Student, public Teacher
	{
	protected:
		string _majorCourse; // 主修课程
	};

	//如下：问p1，p2，p3的关系
	class Base1
	{
	public:int _b1;
	};

	class Base2
	{
	public:
		int _b2;
	};

	class Derive : public Base1, public Base2
	{
	public:
		int _b3;
	};

	int main1()
	{
		Derive d;
		Base1* p1 = &d;
		Base2* p2 = &d;
		Derive* p3 = &d;
		//这里p1=p3！=p2；
		//因为多继承的分布是按照声明的顺序的，先继承的先声明，所以，按照声明顺序，p1=p3!=p2
	}
}
//继承和组合
//继承：
//class stack : public list
//{
//
//};
//组合：
//class stack
//{
//	| list _it;
//};
