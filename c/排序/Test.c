#include"Stack.h"

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
void PrintSort(int *arr,int n)
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

//����һ�����gap����Ԥ���򣬣����ֵ������3
// ÿһ��ѭ��������һ�μ��
// Ȼ��Ե���ѭ�����з��鴦��
// �ڵ���ѭ�����в�������
// 
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

//ѡ�������˼·�ǣ�����˫ָ�룬left��right,����ָ�룬Ȼ�󴴽�����������С������,
// ÿ��ѭ�����������бȽ�,����ҵ���С��ֵ���������ģ��͸���������Сֵ�������±�
// ������ѭ������֮�󣬽����������µ�ֵ�������ұ߻��������A
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
//��ʵ�ֿ���
void _simpleQuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyi = left;
	int begin = left, end = right;

	//�Ƚ�ȥ����ѭ����ָ��һ��keyiֵ����keyiֵ��ߵĶ�����С���ұߵĶ�������Ȼ��keyiֵ�����м�λ����Ϊ�ֽ���
	while (begin < end)
	{
		//�����������ѭ�������������ҵ��˱�keyi��ģ��ұ��ҵ��˱�keyiС�ģ��򲻽���ѭ�������ǽ��н���
		//�ұ�����С 
	// �ȴ��������ҵ�һ��С�ڻ�׼��Ԫ��
		while (begin < end && arr[end] >= arr[keyi])
		{
			end--;
		}

		// �ٴ��������ҵ�һ�����ڻ�׼��Ԫ��
		while (begin < end && arr[begin] <= arr[keyi])
		{
			begin++;
		}

		Swap(&arr[begin], &arr[end]);
	}
	//����ѭ���󣬽���keyiֵ
	Swap(&arr[keyi], &arr[begin]);
	keyi = begin;

	//�ٽ���ݹ飬�Էָ��õ����������������
	//�ָ������Ϊ[begin,keyi-1],key,[keyi+1,end]
	_simpleQuickSort(arr, left, keyi - 1);
	_simpleQuickSort(arr, keyi + 1, right);

}

//����ȡ��1
int medianOfThree(int* arr, int left, int right)
{
	int mind = left + (right - left) / 2;
	//ȷ��arr[left]<arr[mind]<arr[right]
	if (arr[left] > arr[mind])
	{
		Swap(&arr[left], &arr[mind]);
	}
	if (arr[left] > arr[right])
	{
		Swap(&arr[left], &arr[right]);
	}
	if (arr[mind] > arr[right])
	{
		Swap(&arr[mind], &arr[right]);
	}

	//����ֵ����right-1��λ����Ϊ��׼
	Swap(&arr[mind], &arr[right - 1]);

	return arr[right - 1];
}

//����ȡ��2
int Getmind(int* arr, int left, int right)
{
	int mind = (left + right) / 2;

	if (arr[left] < arr[mind])
	{
		if (arr[left] > arr[right])
		{
			return left;
		}
		else if (arr[left] < arr[right])
		{
			return right;
		}
		else if(arr[right]<arr[mind])
		{
			return mind;
		}
	}
	else//arr[left]>arr[mind]
	{
		if (arr[left] < arr[right])
		{
			return left;
		}
		else if (arr[left] > arr[right])
		{
			return right;
		}
		else if(arr[right]>arr[mind])
		{
			return mind;
		}
	}
}
//��������
int partition(int* arr, int left, int right)
{
	//ʹ������ȡ�з���ѡ���׼
	int pivot = medianOfThree(arr, left, right);

	int i = left;
	int j = right - 1;

	while (1)
	{
		//����������Ҵ��ڵ��ڻ�׼��Ԫ��
		while (arr[i++] < pivot);

		//���������ҵ���С�ڻ�׼��Ԫ��
		while (arr[j--] > pivot);

		if (i < j)
		{
			Swap(&arr[i], &arr[j]);
		}
		else
		{
			break;
		}
	}

	//����׼�ŵ���ȷ��λ��
	Swap(&arr[i], &arr[right - 1]);
	return i;
}
//����
void QQQquickSort(int *arr,int left,int right)
{
	if (left >= right)
	{
		return;
	}
	int mind = Getmind(arr, left, right);
	Swap(&arr[left], &arr[mind]);
	int keyi = left;
	int begin = left, end = right;

	//С�����Ż�,��ѡ������
	if (right - left + 1 < 10)
	{
		InsertSort(arr + left, right - left + 1);
	}
	//�Ƚ�ȥ����ѭ����ָ��һ��keyiֵ����keyiֵ��ߵĶ�����С���ұߵĶ�������Ȼ��keyiֵ�����м�λ����Ϊ�ֽ���
	while (begin < end)
	{
		//�����������ѭ�������������ҵ��˱�keyi��ģ��ұ��ҵ��˱�keyiС�ģ��򲻽���ѭ�������ǽ��н���
		//�ұ�����С 
	// �ȴ��������ҵ�һ��С�ڻ�׼��Ԫ��
		while (begin < end && arr[end] >= arr[keyi])
		{
			end--;
		}

		// �ٴ��������ҵ�һ�����ڻ�׼��Ԫ��
		while (begin < end && arr[begin] <= arr[keyi])
		{
			begin++;
		}

		Swap(&arr[begin], &arr[end]);
	}
	//����ѭ���󣬽���keyiֵ
	Swap(&arr[keyi], &arr[begin]);
	keyi = begin;

	//�ٽ���ݹ飬�Էָ��õ����������������
	//�ָ������Ϊ[begin,keyi-1],key,[keyi+1,end]
	QQQquickSort(arr, left, keyi - 1);
	QQQquickSort(arr, keyi + 1, right);


	//if (left < right)
	//{
	//	//��������ĳ��ȴ���3ʱʹ�ÿ���
	//	if (right - left > 3)
	//	{
	//		int pi = partition(arr, left, right);
	//		QQQquickSort(arr, left, pi - 1);
	//		QQQquickSort(arr, pi + 1, right);
	//	}
	//	else
	//	{
	//		//����С�����飬ʹ�ò�������

	//		if (right - left == 1)
	//		{
	//			if (arr[left] > arr[right])
	//			{
	//				Swap(&arr[left], &arr[right]);
	//			}
	//		}
	//		else if (right - left == 2)
	//		{
	//			if (arr[left] > arr[left + 1])
	//			{
	//				Swap(&arr[left], &arr[left + 1]);
	//			}

	//			if (arr[left + 1] > arr[right])
	//			{
	//				Swap(&arr[left + 1], &arr[right]);
	//			}

	//			if (arr[left] > arr[left + 1])
	//			{
	//				Swap(&arr[left], &arr[left + 1]);
	//			}
	//		}
	//	}
	//}
}

//ǰ��ָ��
int quickSort2(int* arr, int left, int right)
{
	//����ȡ��
	int Getmind = medianOfThree(arr, left, right);
	Swap(&arr[left], &arr[Getmind]);
	int keyi = left;
	int perv = keyi;
	int cur = perv + 1;

	while (cur <= right)
	{
		if (arr[cur] < arr[keyi]&&++perv!=cur)
		{
			Swap(&arr[perv], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[perv], &arr[keyi]);
	return perv;
}

//���ŷǵݹ飬ʹ��ջʵ��
//void quickSortNoneR(int* arr,int left,int right)
//{
//	ST st;
//	STInit(&st);
//	STPush(&st, left);
//	STPush(&st, right);
//	
//	while (!STEmpty(&st))
//	{
//		int begin = top(&st);
//		STPop(&st);
//		int end = top(&st);
//		STPop(&st);
//
//		int keyi = partition(arr, left, right);
//
//		//���������
//		if (keyi + 1 < end)
//		{
//			STPush(&st, keyi + 1);
//			STPush(&st, end);
//		}
//
//		if (begin < keyi - 1)
//		{
//			STPush(&st, begin);
//			STPush(&st, keyi - 1);
//		}
//	}
//}

//�鲢����
void _megmceSort()
{

}

int main()
{

	int arr[] = { 2,1,3,5,4,6,9,7,10,8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	/*InsertSort(arr, n);
	/*Print(arr,n);*/
	/*HeapSort(arr, n);
	/*Print(arr, n);*/
	/*ShellSort(arr, n);
	//Print(arr, n);*/
	/*SelectSort_shuang(arr, n);*/
	/*QQQquickSort(arr, 0,n - 1);
	/*PrintSort(arr, n);*/
	_simpleQuickSort(arr, 0, n - 1);
	/*InsertSort(arr,n);*/
	PrintSort(arr,n);

	return 0;
}