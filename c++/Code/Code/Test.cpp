#define _CRT_SECURE_NO_WARNINGS1
#include<iostream>
#include<assert.h>
#include<cstring>
#include<vector>
using namespace std;


int arr[10][10];

class String
{
private: char* _str;

public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	void swap(const String& s)
	{
		String tmp(s._str);
		swap(tmp);
	}
	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(strTmp);
	}

	String& operator=(String s)
	{
		String tmp(s._str);
		swap(tmp);
		return *this;
	}
	friend ostream& operator<<(ostream& out,const String& str);

};
ostream& operator<<(ostream& out,const String& str)
{
	
	  out << str << endl;
	  return out;
	
	
}

void Test1()
{
	for (int i = 0; i <= 10; i++)
	{
		arr[i][0] = 1;
		for (int j = 0; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			if (i == j)
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Test2()
{
	vector<int> v(10,0);
	vector<vector<int>> vv(10,v);



	for (int i = 2; i < vv.size(); i++)
	{
		vv[i].front() =vv[i].back()= 1;
		for (int j = 1; j <= vv[i].size(); j++)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}

	for (int i = 2; i < vv.size(); i++)
	{
		for (int j = 1; j <= vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}
int main1()
{
	String s1("xxxxxqee");
	String s2 = s1;
	cout << s1<<s2;
	Test2();

	return 0;
}


