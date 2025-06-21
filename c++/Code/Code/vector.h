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

	size_t size()const//����Ԫ�ظ���
	{
		return _finish - _start;
	}

	size_t capacity()const//����ռ��С
	{
		return _end_of_storage - _start;
	}

	void reserve(size_t n)//����
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

	void push_back(const T& v)//β��
	{
		if (_finish == _end_of_storage)
		{
			reserve(capacity()==0?4:2*capacity());
		}
		*_finish = v;
		_finish++;
	}
	void insert(iterator pos, const T& v)//����λ�ò���
	{
		assert(pos < _finish);
		assert(pos >= _start);

		if (_finish = _end_of_storage)
		{
			//ע�����pos��λ�÷�ֹ��ΪҰָ��
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

	iterator erase(iterator pos)//����λ��ɾ��
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
	//������һ������
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
	//������ԭ�����Զ����ɲ��������Ĺ��캯����������Ϊ����д�������Ĺ��캯�������Ա������Ͳ����Զ������޲����Ĺ��캯����
	//���ʱ�����ǿ����ֶ�����
	//vector(){}
	//����ʹ��c++11�ķ��������£�
	vector() = default;
	
	//��������
	vector(const vector<T>& v)
	{
		reserve(v.size());
		for (auto e : v)
		{
			v.push_back();
		}
	}

	//��������
	~vector()
	{
		if(_start)
		delete[] _start;
		_start = _finish = _end_of_storage = nullptr;
	}
	//��ģ��ĳ�Ա���������Լ����Ǻ���ģ��
	//�������������һ��ģ����Ϊ�˲��������Լ���ʹ��vector����������Ĺ��죬�������������������ĵ��������й���
	template<typename Input>
	vector(Input first, Input last)
	{
		while (first != last)//ѭ�������ģ�-���ܸĳ�<,����vector����,��Ϊ������������last��һ����first��
		{
			push_back(*first);
			++first;
		}
	}

	//n��val���й���
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

