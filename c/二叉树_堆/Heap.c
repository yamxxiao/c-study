#include"Heap.h"

//初始化
void HPInit(HP* hp)
{
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}
//销毁
void HPDestroy(HP* hp)
{
	assert(hp);
	free(hp->arr);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}

//实现交换
void Swap(HPDataType* Array1, HPDataType* Array2)
{
	if (Array1 == NULL || Array2 == NULL) {
		printf("Error!\n");
		exit(1);
	}
	HPDataType temp = *Array1;
	*Array1 = *Array2;
	*Array2 = temp;
}
//向上调整法
void AdjustUP(HPDataType* arr, int child)
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
//插入
void HPPush(HP* hp, HPDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{


		int NewCapacity = hp->capacity == 0 ? 4 : 2 * hp->capacity;
		HPDataType* tmp = (HPDataType*)realloc(hp->arr, NewCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("fail!");
			exit(1);
		}
		hp->arr = tmp;
		hp->capacity = NewCapacity;
	}
		hp->arr[hp->size++] = x;
	
		AdjustUP(hp->arr, hp->size - 1);
}
//向下调整调整法
void AdjustDown(HPDataType* arr, int size, int parent)
{
	//先假设左孩子最小
	int child = parent * 2 + 1;

	while (child < size)//child>=size,说明孩子不存在，调整到叶子节点
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			++child;
		}

		if (arr[child] < arr[parent])
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
//删除
void HPPop(HP* hp)
{
	assert(hp);
	assert(hp->size > 0);
	Swap(&hp->arr[0], &hp->arr[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->arr, hp->size - 1, 0);
}
//判空
bool HPEmpty(HP* hp)
{
	assert(hp);
	return hp->size == 0;
}
//这里，无论向上还是向下调整法，用的都是小堆
//返回Top元素
HPDataType HPTop(HP* hp)
{
	assert(hp);
	return hp->arr[0];
}
//打印
void HPPrint(HP* hp)
{
	assert(hp);

	while (!HPEmpty(hp))
	{
		printf("%d ", HPTop(hp));
		HPPop(hp);
	}
}