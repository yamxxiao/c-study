#include"Date.h"

ostream& operator<<(ostream& out, const Date& d){
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}
 istream& operator>>(istream& in, Date& d){
	 cout << "请依次输入年月日：" << endl;
	 in >> d._year >> d._month >> d._day;
	 return in;
}

 bool Date::operator<(const Date& d)const
 {
	 if (_year < d._year)
	 {
		 return true;
	 }
	 else if (_year == d._year && _month < d._month)
	 {
		 return true;
	 }
	 else if (_year == d._year && _month == d._month && _day < d._day)
	 {
		 return true;
	 }
	 return false;
 }
 //这样写可以除去重复的代码
 bool Date::operator<=(const Date& d)const
 {
	 return *this == d || *this < d;
 }
bool Date::operator==(const Date& d)const
 {
	 return _year == d._year && _month == d._month && _day == d._day;
 }

bool Date::operator>(const Date& d)const
{
	return !(*this < d);
}

bool Date::operator>=(const Date& d)const
{
	return !(*this <= d) ;
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}
Date Date::operator+(int day)const
{
	Date tmp = *this;
	tmp += day;
	return tmp;

}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator-(int day)const
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator-=(int day)
{

}
//void Date::Init1(int year, int month, int day) {
//	_year = year;
//	_month = month;
//	_day = day;
//}
//void Date:: operator<<(ostream& out) {
//	out << _year << "/" << _month << "/" << _day<<endl;
//}
//或者
//ostream&  operator<<(ostream& out，const Date& d) {
//	out << d._year << "/" << d._month << "/" << d._day << endl;
//	return out;
//}
int main()
{
	/*Date d1(2025, 5, 17);
	Date d2(2025, 5, 16);
	cout << d1 << d2;*/
	/*d1 << cout;
	d1.operator<<(cout);
	*/
	Date d1;
	Date d2;
	cin >> d1>>d2;
	cout << d1 - d2 << endl;;
	/*cout << d1 << d2;*/
	return 0;
}
