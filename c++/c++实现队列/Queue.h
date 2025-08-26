#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<class T>
class QueueNode
{
public:

	T data;
	QueueNode<T>* next;

	QueueNode(const T& _data):data(_data),next(nullptr){}

};

template<class T>
class Queue
{
public:
	Queue():phead(nullptr),ptail(nullptr),size(0){}

	//���
	Queue(const Queue<T>& other)
	{
		if (other.phead == nullptr)
		{
			phead = ptail = nullptr;
			size = 0;
		}
		else
		{
			//�ȴ�����һ�����У�����ԭ���еĵ�һ��Ԫ��
			phead = new QueueNode<T>(other.phead->data);
			
			QueueNode<T>* current = other.phead->next;
			QueueNode<T>* last = phead;//�¶��е����һ���ڵ�

			//����ԭ����
			while (current != nullptr)
			{
				QueueNode<T>* OtherNode = new QueueNode<T>(current->data);//ÿ��һ�δ���һ���½ڵ㲢��ԭ�ڵ��Ԫ�ز���
				last->next = OtherNode;
				last = OtherNode;//���������ǲ���Ĺ���
				current = current->next;//�ƶ�����һ���ڵ�
			}

			ptail = last;//���½ڵ���³�ԭ�ڵ��βָ�룬���ﲻ�ܵ������->last=ptail
			//ԭ���ǣ�ptail���¶��е�βָ�룬��last�Ǳ�������������Ѱ��βָ���һ����ʱָ��
			size = other.size;//�����¶��е�Ԫ�ش�С
		}
	}

	//����
	~Queue()
	{
		Clear();
	}
	void Print()
	{
		QueueNode<T>* cur = phead;
		while (cur)
		{
			cout << cur->data << "->";
			cur = cur->next;
		}
		cout<<"nullptr" << endl;
	}
	//���У��Ƚ��ȳ�
	//���
	void Push(const T& data)
	{
		//����
		QueueNode<T>* NewNode = new QueueNode<T>(data);

		if (phead == nullptr)
		{
			phead = ptail = NewNode;
			NewNode->next = nullptr;
		}
		else
		{
			ptail->next = NewNode;
			ptail = NewNode;
			NewNode->next = nullptr;
		}
		this->size++;
	}
	//����
	void Pop()
	{
		if (phead == nullptr)
		{
			return;
		}
		else
		{
			QueueNode<T>* next = phead->next;
			delete phead;
			phead = next;
		}
		size--;
	}

	//��ȡ��Ԫ��
	QueueNode<T>* InFront()
	{
		assert(phead != nullptr && "Queue is empty");
		return phead->data;
	}

	//��ȡ��βԪ��
	QueueNode<T>* InBack()
	{
		assert(ptail != nullptr && "Queue is empty");
		return ptail->data;
	}

	//��ȡԪ�ظ���
	size_t Size()
	{
		return size;
	}
	
	//�ж��Ƿ�Ϊ��
	bool Empty()
	{
		assert(size);
		return size == 0;
	}

	//���
	void Clear()
	{
		if (!Empty())
		{
			Pop();
		}
	}
private:

	QueueNode<T>* phead;
	QueueNode<T>* ptail;

	size_t size;
};