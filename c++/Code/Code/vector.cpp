#include "vector.h"
void Test_vector()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	Print_vector(v);
	v.find(3);
	Print_vector(v);
}

int main2()
{
	Test_vector();
}