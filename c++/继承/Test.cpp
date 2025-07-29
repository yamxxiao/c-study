#include"Test.h"

int main()
{
	/*Student s1;
	Teacher t1;

	s1.identity();
	t1.identity();*/

	yamx::Stack<int> s1;
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(3);
	s1.push_back(4);
	s1.push_back(5);

	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	return 0;
}