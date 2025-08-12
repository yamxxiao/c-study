#include"Test.h"


//数组查重

vector<int> func(vector<int>& num1, vector<int>& num2)
{
	vector<int> ret;

	set<int>s1(num1.begin(), num2.end());
	set<int>s2(num2.begin(), num2.end());

	// 因为set遍历是有序的，有序值，依次⽐较
// ⼩的++，相等的就是交集

	auto it1 = num1.begin();
	auto it2 = num2.begin();

	while (it1 != num1.end() && it2 != num2.end())
	{
		if (*it1 > *it2)
		{
			it2++;
		}
		else if (*it1 < *it2)
		{
			it1++;
		}
		else
		{
			ret.push_back(*it1);
			it1++;
			it2++;
		}
	}
		return ret;
}
int main()
{
	vector<int> num1;
	vector<int> num2;

	return 0;
}
