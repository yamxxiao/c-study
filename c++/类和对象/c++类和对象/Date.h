#pragma once
#include<iostream>

using namespace std;

class Date {
private:
	int _year;
	int _month;
	int _day;
	//静态成员在类内声明，静态成员只能访问静态成员 非静态的都可以访问
	static int count;

public:
	/*void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	};*/
	/*void Init1(int year, int month, int day) {};*/
	int GetYear()
	{
		return _year;
	}
	int GetMonth()
	{
		return _month;
	}
	int GetDay()
	{
		return _day;
	}
	int GetMonthDay(int month, int year)
	{
		int GetMonth[] = { 0,31,28,31,30,31,30,31,3130,31,30,31 };
		if (month = 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 != 0))
		{
			return 29;
		}
		else {
			return GetMonth[month];
		}
	}

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=( int day);
	Date operator-(int day)const;

	Date operator++();
	Date operator++(int);

	Date operator--();
	Date operator--(int);
	/*bool operator==( Date d2) {

		return GetYear() == d2.GetYear() && GetMonth() == d2.GetMonth() &&GetDay() == d2.GetDay();
	}
	bool operator<(Date d2) {
		return GetYear() < d2.GetYear() && GetMonth()< d2.GetMonth() && GetDay() < d2.GetDay();
	}*/
	//Date(int year = 1, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	/*Date() {
		++count;
	}*/
	Date(int year = 1, int month = 1, int day = 1) :_year(year), _month(month), _day(day) {}const
	void Print() {
		cout << _year << "/" << _month << "/" << _day << endl;
	};
	int GetDay1()const {
		return _year * 365 + _month * 30 + _day * 1;
	}

	//拷贝构造，c++的规定，传值传参要调用拷贝构造

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//构造
	Date(const Date* d)
	{
		_year = d->_year;
		_month = d->_month;
		_day = d->_day;
	}
	/*~Date() {};*/	
	//运算符重载
	bool operator==( Date& d1) {
		return GetYear() == d1.GetYear() && GetMonth() == d1.GetMonth() && GetDay() == d1.GetDay();
	};
	//赋值运算重载
	//d1 = d2;
	void operator=(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	friend ostream& operator<<(ostream& out,const Date& d);
	friend istream& operator>>(istream& in,Date& d);
	 int operator-(const Date& d) {
		return GetDay1() - d.GetDay1();
	}
	 //静态成员函数
	 static int Getcount() {
		 return count;
	 }
};
//静态成员在类外初始化
int Date::count = 1;
////定义在全局
//void operator<<(ostream& out,const Date& d);
//ostream& operator<<(ostream& out，const Date& d);
//bool operator==(Date d1, Date d2) {
//
//	return d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay() == d2.GetDay();
//}
//class B
//{
//	void print() {};
//};
//
//class C {
//};