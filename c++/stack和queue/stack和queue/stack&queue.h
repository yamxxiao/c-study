#pragma once  
#include<iostream>  
#include <vector>  
#include<stack>  
#include<list>  
#include<deque>  
#include<queue>  

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
		_con.pop_front(); // �޸����󣬶���Ӧ��ǰ�˵���  
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

//ģ��ʵ�����ȼ����м���
namespace yamxxiao  
{

template<class T, class Container=vector<T>,class Compare=less<T>>  
class priority_queue  
{  
public:  
	void AdjustUp(int child)//С����
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

	void AdjustDown(int parent)//�����
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

//�º���:������һ���࣬�������operator()�����Ķ����������һ��ʹ��
template<class T>
class lessfunc//����һ���º���
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
//>����
//<����
template<class Compare>
void BubbleSort(int* a, int n,Compare com)
{
	for (int j = 0; j < n; j++)
	{
		int flag = 0;

		for (int i = 1; i < n - j; i++)
		{
			/*if (a[i] < a[i-1])*/
			//����ԭ����Ĭ�����򣬵���Ϊ�˸��õؿ������������ǿ���дһ���º��������ƣ���ˣ����԰�ð������д��ģ��
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
