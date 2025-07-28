#pragma once
#include<iostream>
using namespace std;

//模版分为类型模版和非类型模版
//非类型模版参数和宏定义有区别，是可以更改的,只能用于整型。c++20下支持double
//array数组模版 可以检查越界问题
template<size_t n=10>
class Stack
{
private:
	int _a[n];
	int _top;
};

class Date
{
public:
	Date(int year=1000,int month=1,int day=1):_year(year),_month(month),_day(day){}
	friend ostream& operator<<(ostream& out, Date& d);
	bool operator<(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

bool Date::operator<(const Date& d)const
{
	if (_year != d._year)
		return _year < d._year;
	if (_month != d._month)
		return _month < d._month;
	return _day < d._day;
}
//函数模版特化--参数匹配
template<class T>
bool Less(T left, T right)
{
	return left < right;
}
//模版特化
//函数模板的特化步骤：
//1. 必须要先有一个基础的函数模板
//2. 关键字template后面接一对空的尖括号 < >
//3. 函数名后跟一对尖括号，尖括号中指定需要特化的类型
//4. 函数形参表: 必须要和模板函数的基础参数类型完全相同，如果不同编译器可能会报一些奇
//怪的错误。
template<>
bool Less<Date>(Date left, Date right)
{
	return left < right;
}
//注意：一般情况下如果函数模板遇到不能处理或者处理有误的类型，为了实现简单通常都是将该
//函数直接给出。对于一些参数类型复杂的函数模板，特化
//时特别给出，因此函数模板不建议特化。

//类模版特化
//又分为全特化，偏特化，部分特化
//1.全特化：将类模版参数全部特化
template<class T1,class T2>
class Data
{
public:
	Data() { cout << "Data<T1,T2>" << endl; }

private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int,char>" << endl; }
private:
	int _d1;
	char _d2;
};

void TestData()
{
	Data<int, int> d1;
	Data<int, char> d2;
}
//2.偏特化：任何针对模版参数进一步进行条件限制设计的特化版本。比如对于以下模板类：
//template<class T1,class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//偏特化有两种表现方式
//第一种：部分特化
// 将第二个参数特化为int
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
//第二种：参数更一步的限制偏特化并不仅仅是指特化部分参数，而是针对模板参数更进一步的条件限制所设计出来的一个版本
//两个参数偏特化成指针
template<class T1,class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*,T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

void Test2()
{
	Data<double, int> d1; // 调用特化的int版本
	Data<int, double> d2; // 调用基础的模板
	Data<int*, int*> d3; // 调用特化的指针版本
	Data<int&, int&> d4(1, 2); // 调用特化的指针版本
}