#pragma once
#include<iostream>
#include<string>
#include<cassert>

using namespace std;

template<typename T>
class vector
{
public:
	typedef T* iterator;
	typedef T* const_iterator;

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin()const
	{
		return _start;
	}

	const_iterator end()const
	{
		return _finish;
	}

	size_t size()const//数组元素个数
	{
		return _finish - _start;
	}

	size_t capacity()const//数组空间大小
	{
		return _end_of_storage - _start;
	}

	void reserve(size_t n)//扩容
	{
		if (n > capacity())
		{
			size_t oldsize = size();
			T* tmp = new T[n];
			for (size_t i = 0; i < oldsize; i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;

			_start = tmp;
			_finish = tmp + oldsize;
			_end_of_storage = tmp + n;
		}
	}

	void push_back(const T& v)//尾插
	{
		if (_finish == _end_of_storage)
		{
			reserve(capacity()==0?4:2*capacity());
		}
		*_finish = v;
		_finish++;
	}
	void insert(iterator pos, const T& v)//任意位置插入
	{
		assert(pos < _finish);
		assert(pos >= _start);

		if (_finish = _end_of_storage)
		{
			//注意跟新pos的位置防止成为野指针
			size_t oldpos = pos - _start;
			reserve(capacity() == 0 ? 4:2 * capacity());
			pos = oldpos+_start;
		}
		iterator end = _finish - 1;
		while (pos <= end)
		{
			*(end + 1) = *end;
			--end;
		}
		*pos = v;
		_finish++;
	}

	iterator erase(iterator pos)//任意位置删除
	{
		assert(pos < _finish);
		assert(pos >= _start);
		
		iterator it = pos + 1;

		while (it !=end())
		{
			*(it - 1) = *it;
			++it;
		}
		--_finish;
		return pos;
	}
	//向数组一样访问
	T& operator[](size_t t)
	{
		assert(t < size());
		return _start[t];
	};

	void swap(const vector<T>& v)
	{
		std::swap(_start, v._start);
		std::swap(_finish, v._finish);
		std::swap(_end_of_storage, v._end_of_storage);
	}
	vector<T>& operator=(vector<T>& v)
	{
		swap(v);
		return v;
	};
	//编译器原本会自动生成不带参数的构造函数，但是因为我们写了其他的构造函数，所以编译器就不在自动生成无参数的构造函数了
	//这个时候我们可以手动生成
	//vector(){}
	//或者使用c++11的方法，如下：
	vector() = default;
	
	//拷贝构造
	vector(const vector<T>& v)
	{
		reserve(v.size());
		for (auto e : v)
		{
			v.push_back();
		}
	}

	//析构函数
	~vector()
	{
		if(_start)
		delete[] _start;
		_start = _finish = _end_of_storage = nullptr;
	}
	//类模版的成员函数还可以继续是函数模版
	//给这个函数套上一个模版是为了不仅仅可以继续使用vector迭代器区间的构造，还能适用其他的容器的迭代器进行构造
	template<typename Input>
	vector(Input first, Input last)
	{
		while (first != last)//循环条件的！-不能改成<,但是vector可以,因为其他的容器的last不一定比first大
		{
			push_back(*first);
			++first;
		}
	}

	//n个val进行构造
	vector(size_t n, const T& val = T())
	{
		reserve(n);
		for (auto e : val)
		{
			push_back(e);
		}
	}
	iterator find(const T& pos)
	{
		return _start[pos];
	}
private:
	iterator _start=nullptr;
	iterator _finish=nullptr;
	iterator _end_of_storage=nullptr;

};
template<typename Int>
void Print_vector(const vector<Int>& v)
{
	typename vector<Int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

