#pragma once
#include<iostream>
#include<cassert>
using namespace std;

typedef int HPDataType;
template<class T>
class Heap
{
public:
	Heap() :array(nullptr), capacity(0), size(0){}

	//析构
	~Heap()
	{
		cout << "调用析构" << endl;
		delete[] array;
	}
	//拷贝构造
	Heap(const Heap& other) :array(nullptr), size(0), capacity(0)
	{
		if (other.capacity == 0)
		{
			array = nullptr;
			capacity = size = 0;
		}
		else
		{
			T* NewArray = new T[other.capacity];
			for (int i = 0; i < other.size; i++)
			{
				NewArray[i] = other.array[i];
			}

			capacity = other.capacity;
			array = NewArray;//这里不能释放NewArray,原因是，原数组的值拷贝到了NewArray里面，array只是指向这个副本的指针，如果删除，array就变成悬空指针了
			size = other.size;
		}
	}
	//插入
	void HeapPush(const T& data)
	{
		if (size == capacity)
		{
			HPDataType NewCapacity = capacity == 0 ? 4 : 2 * capacity;
			T* NewArray = new T[NewCapacity];

			if (NewArray == nullptr)
			{
				cout << "fail!" << endl;
				return;
			}

			for (int i = 0; i < size; i++)
			{
				NewArray[i] = array[i];
			}
			capacity = NewCapacity;
			/*delete[] array;*/
			array = NewArray;
		}
		array[size++] = data;

		AdjustUp(size - 1);//这里传入size-1，其实就是插入元素的索引
	}
	//删除
	void HeapPop()
	{
		assert(size > 0);

		Swap(array[0], array[size - 1]);
		size--;
		AdjustDown(size-1,0);
	}
	//取根
	T& HeapTop()
	{
		assert(size > 0);
		return array[0];
	}
	//判空
	bool HeapEmpty()
	{
		return size == 0;
	}
	//打印
	void HeapPrint()
	{
		while (!HeapEmpty())
		{
			cout << HeapTop() << " ";
			HeapPop();
		}
		cout << endl;
	}
private:
	void Swap(T& array1, T& array2)
	{
		T temp = array1;
		array1 = array2;
		array2 = temp;
	}
	//向上调整法:将最后一个孩子的值与父亲和进行比较，然后进行交换,根据实际情况变成新根
	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;//根据二叉树的定义，左孩子->(parent*2)+1,
									//右孩子->(parent*2)+2
		while (child > 0)
		{
			if (array[child] < array[parent])
			{
				Swap(array[child], array[parent]);

				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	//向下调整法:将根与最后一个元素进行交换,然后寻找最小的孩子变成新的根
	void AdjustDown(int size, int parent)
	{
		int child = parent * 2 + 1;//这里假设左孩子最小

		while (child < size)//这里保证孩子节点存在，并寻找叶子节点
		{
			//先寻找最小的孩子节点
			if (child + 1 < size && array[child + 1] < array[child])//判断，如果右孩子存在，且右孩子小于左孩子，那么让child++，选择更小的右孩子
			{
				++child;
			}

			if (array[child] < array[parent])//比较，如果父亲节点大于孩子节点，就交换，然后更新节点继续走
			{
				Swap(array[child], array[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;//否则跳出循环
			}
		}
	}
	T* array;
	HPDataType capacity;
	HPDataType size;
};
