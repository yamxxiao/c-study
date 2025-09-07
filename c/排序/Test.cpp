#include<stdio.h>

//��������
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
//����
void Swap(int *arr1,int *arr2)
{
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

//������
//���ϵ�����
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

//���µ�����
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
	//����->��ѣ���������һ����Ҷ�ӽڵ���ǰ����
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(arr, i, size);
	}

	//����ÿ�ν��Ѷ���Ԫ�غ�ĩβԪ�ؽ��н�����Ȼ�����
	for (int i = size - 1; i > 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		HeapAdjustDown(arr, 0, i);
	}
}

//ϣ������
//1.Ԥ����
//2.��������
void ShellSort(int* arr, int size)
{
	int gap = size;
	
	while (gap > 1)
	{
		//���¼��
		gap = gap / 3 + 1;

		//����ѭ���������÷���
		for (int i = gap; i < size; i++)
		{
			int temp = arr[i];
			int end = i - gap;

			//�ڵ�ǰ�����ڽ��в�������

			while (end >= 0 && temp < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}

			arr[end + gap] = temp;
		}
	}
}

//ѡ������:����
void  SelectSort_dan(int* arr, int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;//��СԪ������

		//��ĩ�����в���Ѱ����СԪ��
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
			//���ҵ�����СԪ�ؽ��н���
			if (minIndex != i)
			{
				Swap(&arr[i], &arr[minIndex]);
			}
		}

	}
}

//ѡ������˫��
void SelectSort_shuang(int* arr, int size)
{
	int left = 0, right = size - 1;
	int maxIndex = right, minIndex = left;

	while (left < right)
	{

		//�ҵ���Χ�������С��Ԫ��
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

		//����СԪ�ط��������
		if (minIndex != left)
		{
			Swap(&arr[left], &arr[minIndex]);
		}
		// ������Ԫ������ߣ���Ҫ����maxIndex
		if (maxIndex == left)
		{
			maxIndex == minIndex;
		}

		//������Ԫ�ط������ұ�
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