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

	//����
	~Heap()
	{
		cout << "��������" << endl;
		delete[] array;
	}
	//��������
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
			array = NewArray;//���ﲻ���ͷ�NewArray,ԭ���ǣ�ԭ�����ֵ��������NewArray���棬arrayֻ��ָ�����������ָ�룬���ɾ����array�ͱ������ָ����
			size = other.size;
		}
	}
	//����
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

		AdjustUp(size - 1);//���ﴫ��size-1����ʵ���ǲ���Ԫ�ص�����
	}
	//ɾ��
	void HeapPop()
	{
		assert(size > 0);

		Swap(array[0], array[size - 1]);
		size--;
		AdjustDown(size-1,0);
	}
	//ȡ��
	T& HeapTop()
	{
		assert(size > 0);
		return array[0];
	}
	//�п�
	bool HeapEmpty()
	{
		return size == 0;
	}
	//��ӡ
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
	//���ϵ�����:�����һ�����ӵ�ֵ�븸�׺ͽ��бȽϣ�Ȼ����н���,����ʵ���������¸�
	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;//���ݶ������Ķ��壬����->(parent*2)+1,
									//�Һ���->(parent*2)+2
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
	//���µ�����:���������һ��Ԫ�ؽ��н���,Ȼ��Ѱ����С�ĺ��ӱ���µĸ�
	void AdjustDown(int size, int parent)
	{
		int child = parent * 2 + 1;//�������������С

		while (child < size)//���ﱣ֤���ӽڵ���ڣ���Ѱ��Ҷ�ӽڵ�
		{
			//��Ѱ����С�ĺ��ӽڵ�
			if (child + 1 < size && array[child + 1] < array[child])//�жϣ�����Һ��Ӵ��ڣ����Һ���С�����ӣ���ô��child++��ѡ���С���Һ���
			{
				++child;
			}

			if (array[child] < array[parent])//�Ƚϣ�������׽ڵ���ں��ӽڵ㣬�ͽ�����Ȼ����½ڵ������
			{
				Swap(array[child], array[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;//��������ѭ��
			}
		}
	}
	T* array;
	HPDataType capacity;
	HPDataType size;
};
