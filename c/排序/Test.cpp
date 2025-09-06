#include<stdio.h>

//≤Â»Î≈≈–Ú
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

int main()
{

	int arr[] = {14,74,2,34,55,24,74,11,8,9,5,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, n);
	Print(arr,n);

	return 0;
}