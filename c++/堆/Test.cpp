#include"Heap.h"
#include<algorithm>
#include<vector>

//“向下调整法，单次时间复杂度为O(logN)”。而建堆过程总体时间复杂度为O(N)。
void AdjustDown(vector<int>& arr,int size,int parent)
{
	int child = parent * 2 + 1;//左孩子

	while (child < size)
	{
		if (child+1<size && arr[child + 1] < arr[child])
		{
			++child;//右孩子，更小
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

//向上调整法单次时间复杂度也是O(logN)，插入n个元素建堆的时间复杂度为O(N logN)。
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

	cout << "原始数组: ";
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;
	//先构建最小堆
	for (int i = (size/2)-1; i >= 0; --i)//等效于->(size-1-1)/2,原因是要找到最后一个非叶子节点，size-1是最后一个元素的索引，根据二叉树的性质(size-1-1)/2->parent=(child-1)/2;
	{
		AdjustDown(arr, size , i);
	}
	cout << "建堆后: ";
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;

	//提取堆顶元素并重建堆
	for (int i = size - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);
		AdjustDown(arr, i, 0);	
	}

	cout << "使用堆排序之后: ";
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

	cout << "原始数组: ";
	for (auto e : arr) {
		cout << e << " ";
	}
	cout << endl;

	// 插入新元素到已有的数组中
	int newElement = 0;
	arr.push_back(newElement);
	size++;

	// 使用 AdjustUp 构建最小堆
	AdjustUp(arr, size - 1);

	cout << "插入元素后再重新构建的堆 " << newElement << ": ";
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