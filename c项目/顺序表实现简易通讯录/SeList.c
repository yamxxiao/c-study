#include"SeList.h"

//˳����ʼ��
void SLInit(SL* s)
{
	s->arr = NULL;
	s->size = 0, s->capacity = 0;
}

//˳�������
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}

	ps->capacity = ps->size = 0;
}

//���ռ��Ƿ�Ϊ�պ�����
void CheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		//����ռ�
		//��Realloc��������ռ�
		//�ȴ���һ����ʱ����NewCapacity�����տռ��Tmp��ʱ������Ŀ����Ϊ�˷�ֹ�ռ�����ʧ��

		size_t NewCapacity = ps->capacity == 0 ? 2 : 4 * ps->capacity;
		SLDataType* Tmp = (SLDataType*)realloc(ps->arr, NewCapacity * sizeof(SLDataType));

		if (Tmp == NULL)
		{
			perror("����ʧ�ܣ��˳���");
			exit(1);
		}
		//�ռ�����ɹ�
		ps->capacity = NewCapacity;
		ps->arr = Tmp;
	}
}

//��ӡ 
void Print(SL ps)
{
	for (int i = 0; i < ps.size; i++)
	{
		/*printf("%d ", ps.arr[i]);*/
	}
	printf("\n");
}
//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//�жϿռ��Ƿ�Ϊ��
	CheckCapacity(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//�ж�˳�����
	//�жϿռ��Ƿ�Ϊ��
	CheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	/*ps->arr[0] = -1;*/
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);//˳�����Ϊ�գ�����ᱨ��
	ps->size--;
}

//ָ��λ�ò���
void Insert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos > 0 && pos <= ps->size + 1);

	CheckCapacity(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[pos] = x;
	ps->size++;
}

void Erase(SL* ps, int pos)
{
	assert(ps);
	/*assert(pos > 0);*/

	for (int i = pos; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;

}

//int Find(SL* ps, int pos)
//{
//	assert(ps);
//
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == pos)
//		{
//
//			return i;
//		}
//	}
//}
