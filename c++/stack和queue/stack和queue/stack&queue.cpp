#include "stack&queue.h"

void Test_1()
{
	yamx::stack<int, vector<int>>st;//��ģ��ʵ����ʱ��ֻ�����Щ�õ��ĺ���ʵ����,����ȫ��ʵ����
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	cout << st.top() << endl;
	cout << st.size() << endl;
	st.pop();
	cout << st.size() << endl;
}

void Test_2()
{
	atarayo::queue<int/*,list<int>*/>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	cout << st.front() << endl;
	cout << st.size() << endl;
	st.pop();
	cout << st.size() << endl;
}

int main()
{
	/*Test_1();*/
	Test_2();
	/*cout << "hello world" << endl;*/
	return 0;
}