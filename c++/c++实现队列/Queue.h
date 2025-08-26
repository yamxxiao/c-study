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

	//深拷贝
	Queue(const Queue<T>& other)
	{
		if (other.phead == nullptr)
		{
			phead = ptail = nullptr;
			size = 0;
		}
		else
		{
			//先创建第一个队列，复制原队列的第一个元素
			phead = new QueueNode<T>(other.phead->data);
			
			QueueNode<T>* current = other.phead->next;
			QueueNode<T>* last = phead;//新队列的最后一个节点

			//遍历原队列
			while (current != nullptr)
			{
				QueueNode<T>* OtherNode = new QueueNode<T>(current->data);//每走一次创建一个新节点并把原节点的元素插入
				last->next = OtherNode;
				last = OtherNode;//这两步就是插入的过程
				current = current->next;//移动到下一个节点
			}

			ptail = last;//将新节点跟新成原节点的尾指针，这里不能倒反天罡->last=ptail
			//原因是，ptail是新队列的尾指针，而last是遍历过程中用于寻找尾指针的一个临时指针
			size = other.size;//设置新队列的元素大小
		}
	}

	//析构
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
	//队列：先进先出
	//入队
	void Push(const T& data)
	{
		//扩容
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
	//出队
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

	//获取首元素
	QueueNode<T>* InFront()
	{
		assert(phead != nullptr && "Queue is empty");
		return phead->data;
	}

	//获取队尾元素
	QueueNode<T>* InBack()
	{
		assert(ptail != nullptr && "Queue is empty");
		return ptail->data;
	}

	//获取元素个数
	size_t Size()
	{
		return size;
	}
	
	//判断是否为空
	bool Empty()
	{
		assert(size);
		return size == 0;
	}

	//清除
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