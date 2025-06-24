#include "stack&queue.h"

void Test_1()
{
	yamx::stack<int, vector<int>>st;//类模版实例化时，只会把那些用到的函数实例化,不会全部实例化
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

void Test_3()
{
	//测试优先级队列，这是从大到小,greater是从小到大排序
	priority_queue<int, vector<int>/**greater<int>*/>pq;

	pq.push(4);
	pq.push(7);
	pq.push(1);
	pq.push(9);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void Test_4()
{
	yamxxiao::priority_queue<int, vector<int>/**greater<int>*/>pq;

	pq.push(4);
	pq.push(7);
	pq.push(1);
	pq.push(9);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void Test_5()
{
	lessfunc<int> less;
	greaterfunc<int> greater;

	cout << less(1, 2) << endl; 
	int a[] = { 5,9,8,4,3,6,10,2 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]),less);
}
int main()
{
	/*Test_1();*/
	/*Test_2();*/
	/*Test_3();*/
	/*cout << "hello world" << endl;*/
	//Test_4();
	Test_5();
	return 0;
}