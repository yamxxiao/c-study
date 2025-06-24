#pragma once  
#include<iostream>  
#include <vector>  
#include<stack>  
#include<list>  
#include<deque>  
#include<queue>  

using namespace std;  
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。  
class Test  
{  
bool INfor(vector<int>& push, vector<int>& pop)  
{  
	stack<int> st;  
	size_t popi = 0;  

	for (auto e : push)  
	{  
		// 压入栈  
		st.push(e);  

		while (!st.empty() && popi < pop.size() && st.top() == pop[popi])  
		{  
			// 弹出栈  
			st.pop();  
			++popi;  
		}  

	}  
	return st.empty();  
}  
};  
namespace yamx  
{  
//使用类模版来实现stack  
//template <typename T>  
//class stack  
//{  

//private:  
//	T* _data; // 数据存储  
//	size_t _capacity; // 容量  
//	size_t _top; // 栈顶索引  
//};  
//也可以使用vector来实现stack  
//用contianer来适配转出stack  
template <typename T,typename Container=vector<T>>//可以给container一个缺省值vector<T>  
class stack  
{  
public:  
	void push(const T& s)  
	{  
		_con.push_back(s);  
	}  

	void pop()  
	{  
		_con.pop_back();  
	}  


	const T& top()  
	{  
		return _con.back();  
	}  

	size_t size()const  
	{  
		return _con.size();  
	}  

	bool empty()const  
	{  
		return _con.empty();  
	}  

private:  
	Container _con;  
};  
}  
namespace atarayo  
{  
//使用类模版来实现队列  
template<class T,class Container=deque<T>>//这里的缺省值就不能给vector，因为队列是  
class queue								//先进先出，需要双向指向，所以使用list作为缺省值，或者使用deque											  
{  
public:  
	void push(const T& s)  
	{  
		_con.push_back(s);  
	}  

	void pop()  
	{  
		_con.pop_front(); // 修复错误，队列应从前端弹出  
	}  

	const T& front()  
	{  
		return _con.front();  
	}  

	const T& back()  
	{  
		return _con.back();  
	}  
	size_t size()const  
	{  
		return _con.size();  
	}  

	bool empty()  
	{  
		return _con.empty();  
	}  
private:  
	Container _con;  
};	  
}  

//模拟实现优先级队列及堆
namespace yamxxiao  
{

template<class T, class Container=vector<T>,class Compare=less<T>>  
class priority_queue  
{  
public:  
	void AdjustUp(int child)//小根堆
	{  
		size_t parent = (child - 1) / 2;  
		while (child > 0)  
		{  
			if (_con[child] < _con[parent])  
			{  
				std::swap(_con[child], _con[parent]);
				child = parent;  
				parent = (child - 1) / 2;  
			}  
			else  
			{  
				break;  
			}  
		}  
	}  

	void AdjustDown(int parent)//大根堆
	{  
		size_t child = parent * 2 + 1;

		while (child < _con.size())
		{
			if(child+1<_con.size() && _con[child + 1]<_con[child])
			{
				++child;
			}

			if (_con[child] < _con[parent])
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}  

	void push(const T & a)  
	{  
		_con.push_back(a);  
		AdjustUp(_con.size() - 1);  
	}

	void pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();

		AdjustDown(0);
	}

	const T& top()
	{
		return _con[0];
	}

	size_t size()const
	{
		return _con.size();
	}

	bool empty()const
	{
		return _con.empty();
	}

private:  
	Container _con;  
};  
}

//仿函数:本质是一个类，这个类重operator()，它的对象可以像函数一样使用
template<class T>
class lessfunc//这是一个仿函数
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class greaterfunc
{
public:
	bool operator()(const T&x, const T& y)
	{
		return x > y;
	}
};
//>升序
//<降序
template<class Compare>
void BubbleSort(int* a, int n,Compare com)
{
	for (int j = 0; j < n; j++)
	{
		int flag = 0;

		for (int i = 1; i < n - j; i++)
		{
			/*if (a[i] < a[i-1])*/
			//这里原本是默认升序，但是为了更好地控制升序降序，我们可以写一个仿函数来控制，因此，可以把冒泡排序写成模版
			if(com(a[i],a[i-1]))
			{
				swap(a[i - 1], a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}
