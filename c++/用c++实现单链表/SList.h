#pragma once
#include<iostream>
#include<assert.h>

using namespace std;
template<class T>
class Node
{
public:
	T _data;
	Node* _next;

	Node(const T& data) :_data(data), _next(nullptr) {}
};
template<class T>
class SList
{
public:
	SList():phead(nullptr){}
	//扩容开空间
	Node<T>* Checksize(const T& data)
	{
		//先申请空间
		Node<T>* NewNode = new Node<T>(data);

		if (NewNode == nullptr)
		{
			cout << "扩容失败!" << endl;
			return nullptr;
		}
	/*	NewNode->_data = data;
		NewNode->_next = nullptr;*/

		return NewNode;
	}

	//拷贝构造
	SList(const SList& other):phead(nullptr)
	{
		if (other.phead != nullptr)
		{
			Node<T>* current = other.phead;
			Node<T>* newTail = nullptr;

			while (current != nullptr)
			{
				Node<T>* NewNode = new Node<T>(current->_data);
				if (!newTail)
				{
					phead = NewNode;
					newTail = NewNode;
				}
				else
				{
					newTail->_next = NewNode;
					newTail = NewNode;
				}
				current = current->_next;
			}
		}
	}

	//析构
	~SList()
	{
		Node<T>* pail = phead;
		Node<T>* next = pail->_next;
		while (pail != nullptr)
		{
			delete pail;
			pail = next;

		}
		phead = nullptr;
	}

	//打印
	void Print()
	{
		Node<T>* ptr = phead;
		while (ptr != nullptr)
		{
			cout << ptr->_data << "->";
			ptr = ptr->_next;
		}
		cout << "nullptr";
		cout << endl;
	}
	//尾插
	void Push_Back(const T& data)
	{
		/*assert(phead);*/
		Node<T>* NewNode = Checksize(data);

		if (!phead)
		{
			phead = NewNode;
		}
		else
		{
			//创建一个临时节点指向结点
			Node<T>* ptr = phead;
			while (ptr->_next!=nullptr)
			{
				ptr = ptr->_next;
			}
			ptr->_next = NewNode;
		}
	}

	//头插
	void Push_Front(const T& data)
	{
		Node<T>* NewNode = Checksize(data);

		if (!phead)
		{
			phead = NewNode;
		}

		else
		{
			NewNode->_next = phead;
			phead = NewNode;//更新一下头结点
		}
	}

	//尾删除
	void Pop_Back()
	{
		if (phead->_next==nullptr)
		{
			delete phead;
			phead = nullptr;
			return;
		}

		//创建两个临时指针指向头节点
		Node<T>* perv = phead;//前驱
		Node<T>* pail = phead;//后继

		while (pail->_next != nullptr)
		{
			perv = pail;
			pail = pail->_next;
		}
		perv->_next =nullptr;
		delete pail;
	}

	//头删
	void Pop_Front()
	{
		if (phead == nullptr)
		{
			delete phead;
			phead = nullptr;
			return;
		}
		else
		{
			Node<T>* pail = phead->_next;
			delete phead;
			phead = nullptr;
			phead = pail;
		}
	}
private:
	Node<T>* phead;
};

//单链表的环形链表问题：快慢指针
//1.为什么一定会相遇，没有可能错过，永远追不上？请证明
//2.slow一次走一步，fast走3步，4步，5步，n步 请证明
// 
// 
//1.假设slow进入循环时，fast和slow相聚n，fast追击slow的距离如下：
//n->n-2->n-4->n-6->....4->2->0，最终会相遇。
//
//2.如果相聚为n为偶数时，如上，可以追上，但是如果n为奇数那追击距离如下：
//n->n-2->n-4->...3->1->-1;此时为-1时会错过，然后会进行新一轮追击此时的距离为c-1
//然后对c-1进行分析，如果c-1为偶数，可以追上，如果为奇数，则永远追不上。