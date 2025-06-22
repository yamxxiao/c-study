#pragma once
#include<cassert>
#include<iostream>
#include <vector>
#include<stack>
#include<list>
#include<deque>

using namespace std;
// ��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
class Test
{
	bool INfor(vector<int>& push, vector<int>& pop)
	{
		stack<int> st;
		size_t popi = 0;

		for (auto e : push)
		{
			// ѹ��ջ
			st.push(e);

			while (!st.empty() && popi < pop.size() && st.top() == pop[popi])
			{
				// ����ջ
				st.pop();
				++popi;
			}

		}
		return st.empty();
	}
};
namespace yamx
{
	//ʹ����ģ����ʵ��stack
	//template <typename T>
	//class stack
	//{

	//private:
	//	T* _data; // ���ݴ洢
	//	size_t _capacity; // ����
	//	size_t _top; // ջ������
	//};
	//Ҳ����ʹ��vector��ʵ��stack
	//��contianer������ת��stack
	template <typename T,typename Container=vector<T>>//���Ը�containerһ��ȱʡֵvector<T>
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
	//ʹ����ģ����ʵ�ֶ���
	template<class T,class Container=deque<T>>//�����ȱʡֵ�Ͳ��ܸ�vector����Ϊ������
	class queue								//�Ƚ��ȳ�����Ҫ˫��ָ������ʹ��list��Ϊȱʡֵ������ʹ��deque											
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
