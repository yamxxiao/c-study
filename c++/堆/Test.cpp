#include"Heap.h"
#include<algorithm>
#include<vector>

//�����µ�����������ʱ�临�Ӷ�ΪO(logN)���������ѹ�������ʱ�临�Ӷ�ΪO(N)��
void AdjustDown(vector<int>& arr,int size,int parent)
{
	int child = parent * 2 + 1;//����

	while (child < size)
	{
		if (child+1<size && arr[child + 1] < arr[child])
		{
			++child;//�Һ��ӣ���С
		}

		if (arr[child] < arr[parent])
		{
			std::swap(arr[child],arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//���ϵ���������ʱ�临�Ӷ�Ҳ��O(logN)������n��Ԫ�ؽ��ѵ�ʱ�临�Ӷ�ΪO(N logN)��
void AdjustUp(vector<int>& arr,int child)
{
	int parent = (child - 1) / 2;


	while(child>0)
	{
		if (arr[child] < arr[parent])
		{
			std::swap(arr[child], arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapTestAdjustDown()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	int size = arr.size();

	cout << "ԭʼ����: ";
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;
	//�ȹ�����С��
	for (int i = (size/2)-1; i >= 0; --i)//��Ч��->(size-1-1)/2,ԭ����Ҫ�ҵ����һ����Ҷ�ӽڵ㣬size-1�����һ��Ԫ�ص����������ݶ�����������(size-1-1)/2->parent=(child-1)/2;
	{
		AdjustDown(arr, size , i);
	}
	cout << "���Ѻ�: ";
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;

	//��ȡ�Ѷ�Ԫ�ز��ؽ���
	for (int i = size - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);
		AdjustDown(arr, i, 0);	
	}

	cout << "ʹ�ö�����֮��: ";
	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
}
void HeapTestAdjustUp()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	int size = arr.size();

	cout << "ԭʼ����: ";
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;

	// ������Ԫ�ص����е�������
	int newElement = 0;
	arr.push_back(newElement);
	size++;

	// ʹ�� AdjustUp ������С��
	AdjustUp(arr, size - 1);

	cout << "����Ԫ�غ������¹����Ķ� " << newElement << ": ";
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	Heap<int> hp;
	hp.HeapPush(1);
	hp.HeapPush(2);
	hp.HeapPush(3);
	hp.HeapPush(4);
	hp.HeapPush(5);
	Heap<int> hp1 = hp;
	hp1.HeapPrint();
	hp.HeapPrint();
	HeapTestAdjustDown();
	HeapTestAdjustUp();
	return 0;
}