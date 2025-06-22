#pragma once
#include<cassert>
#include<iostream>
#include <vector>
#include<stack>
#include<list>
#include<deque>

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
			_con.pop_back();
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
