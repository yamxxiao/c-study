#pragma once
#include<iostream>
#include<assert.h>
#include<stdlib.h>

using namespace std;

typedef size_t SLDataType;
class SeList
{
public:
	SLDataType* _arr;
	SLDataType _size;
	SLDataType _capacity;

	SeList() :_arr(nullptr), _size(0), _capacity(0) {}

	//��������
	SeList(const SeList& other):_arr(nullptr),_size(other._size),_capacity(other._capacity)
	{
		if (_capacity > 0)
		{
			_arr = new SLDataType[_capacity];

			assert(_arr != nullptr);
			assert(_size <= _capacity);


			for (SLDataType i = 0; i < _size; i++)
			{
				_arr[i] = other._arr[i];
			}
		}
	}

	//����
	~SeList()
	{
		delete[] _arr;
	}

	//��ֵ����
	SeList& operator=( const SeList& other)
	{
		if (_capacity > 0)
		{
			_size = other._size;
			_capacity = other._capacity;

			SLDataType* New_arr = new SLDataType[_capacity];
			New_arr = _arr;

			for (SLDataType i = 0; i < _size; i++)
			{
				other._arr[i] = _arr[i];
			}

			delete[] _arr;
		}
		else
		{
			_arr = nullptr;
		}

		return *this;
	}




//����
	void CheckCapacity()
	{	
	
		if (_size == _capacity)
		{

			//����
			//��һ��ʹ��Realloc����
			/*SLDataType NewCapacity =_capacity == 0 ? 2 :2 *_capacity;
			SLDataType* arr = (SLDataType*)realloc(_arr, NewCapacity * sizeof(SLDataType));
			assert(arr != nullptr);
			_capacity = NewCapacity;
			_arr = arr;*/

			//�ڶ���ʹ��New ����
			SLDataType NewCapacity = _capacity == 0 ? 2 : 4 * _capacity;
			SLDataType* arr = new SLDataType[NewCapacity];

			for (SLDataType i = 0; i < _size; i++)
			{
				arr[i] = _arr[i];
			}
			assert(arr != nullptr);
			_capacity = NewCapacity;
			_arr = arr;
		}
	}
	//ͷ��
	void Insert(SLDataType x)
	{
			/*assert(ps!=nullptr);*/
		/*	assert(ps._size);*/
			CheckCapacity();

			for (SLDataType i = _size; i > 0; i--)
			{
				 _arr[i] = _arr[i - 1];
			}

			_arr[0] = x;
			_size++;
	
	}
	
	//β��
	void PushBack(SLDataType x)
	{
		assert(_size);

		CheckCapacity();

		_arr[_size++] = x;
	}

	//ͷɾ

	void PopFront()
	{
		assert(_size);

		for (SLDataType i = 0; i < _size; i++)
		{
			_arr[i] = _arr[i + 1];
		}
		_size--;

	}

	//βɾ
	void PopBack()
	{
		assert(_size);
		_size--;
	}

	void Print()const
	{
		for (SLDataType i = 0; i < _size; i++)
		{
			cout << _arr[i] << " ";
		}
		cout << endl;
	}
};