#include<stdio.h>

//插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = arr[end + 1];

		while (end >= 0)
		{
			if (temp < arr[end])
			{
				arr[end + 1] = arr[end];
			}
			else
			{
				break;
			}
			end--;
		}

		arr[end + 1] = temp;
	}
}
void Print(int *arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//交换
void Swap(int *arr1,int *arr2)
{
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

//堆排序
//向上调整法
void HeapAdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

//向下调整法
void HeapAdjustDown(int* arr, int parent,int size)
{

	int child = parent * 2 + 1;

	while (child < size)
	{


		if (child + 1<size && arr[child] < arr[child + 1])
		{
			++child;
		}

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *arr,int size)
{
	//建队->大堆，升序从最后一个非叶子节点向前遍历
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(arr, i, size);
	}

	//排序，每次将堆顶的元素和末尾元素进行交换，然后调整
	for (int i = size - 1; i > 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		HeapAdjustDown(arr, 0, i);
	}
}

//希尔排序
//1.预排序
//2.插入排序
void ShellSort(int* arr, int size)
{
	int gap = size;
	
	while (gap > 1)
	{
		//更新间隔
		gap = gap / 3 + 1;

		//单层循环处理所用分组
		for (int i = gap; i < size; i++)
		{
			int temp = arr[i];
			int end = i - gap;

			//在当前分组内进行插入排序

			while (end >= 0 && temp < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}

			arr[end + gap] = temp;
		}
	}
}

//选择排序:单向
void  SelectSort_dan(int* arr, int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;//最小元素索引

		//在末排序中部分寻找最小元素
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
			//将找到的最小元素进行交换
			if (minIndex != i)
			{
				Swap(&arr[i], &arr[minIndex]);
			}
		}

	}
}

//选择排序：双向
void SelectSort_shuang(int* arr, int size)
{
	int left = 0, right = size - 1;
	int maxIndex = right, minIndex = left;

	while (left < right)
	{

		//找到范围内最大最小的元素
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
			if (arr[i] > arr[maxIndex])
			{
				maxIndex = i;
			}
		}

		//将最小元素放在最左边
		if (minIndex != left)
		{
			Swap(&arr[left], &arr[minIndex]);
		}
		// 如果最大元素在左边，需要更新maxIndex
		if (maxIndex == left)
		{
			maxIndex == minIndex;
		}

		//将最大的元素放在最右边
		if (maxIndex != right)
		{
			Swap(&arr[right], &arr[maxIndex]);
		}
		left++;
		right--;
	}
}

int main()
{

	int arr[] = {14,74,2,34,55,24,74,11,8,9,5,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	/*InsertSort(arr, n);
	Print(arr,n);*/
	/*HeapSort(arr, n);
	Print(arr, n);*/
	/*ShellSort(arr, n);
	Print(arr, n);*/
	SelectSort_shuang(arr, n);
	Print(arr, n);

	return 0;
}