#include<iostream>
#include<cstring>
#include<assert.h>


using namespace std;

bool Islower(char is)
{
	if ('A'<=is && is <= 'Z')
	{
		return true;
	}
	else if ('a'<=is && is <= 'z')
	{
		return true;
	}
	return false;
}

string func(string s)
{
	int left = 0, right = s.size() - 1;

	while (left < right)
	{
		while (left<right&&!Islower(s[left]))//����left<right��Ŀ����Ҫ��Ϊ�˷�ֹԽ��
		{
			++left;
		}

		while (left<right&&!Islower(s[right]))
		{
			right--;
		}
		swap(s[left++], s[right--]);
		return s;
	}

}
class String//�ִ���string���д��
{
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
	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
	}
	
	String& operator=(String s)
	{
		std::swap(_str, s._str);
		return *this;
	}
	//���
	void Swap(string& s)
	{
		String tmp(s._str);
		swap(tmp);

	}
	String(const String& s)
	{
		string tmp(s._str);
		Swap(tmp);
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

int main()
{
	/*string s1("hello,atarayo");
	string s2(s1);

	cout << s2 << endl;*/

	//string s3(s2, 0, 5);
	//cout << s3 << endl;
	//s2[0] = 'x';
	//cout << s2 << endl;
	//���������
	/*string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		rit++;
	}*/
	/*string s = "abc-def-g";*/
	/*string s2=func(s);
	cout << s2 << endl;*/
	//s.erase(6, 2);
	//cout << s << endl;
	string s1("string");
	string s2 = s1;
	cout << s2 << endl;
	return 0;
}