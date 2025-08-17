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
