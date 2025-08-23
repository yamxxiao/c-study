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
	//���ݿ��ռ�
	Node<T>* Checksize(const T& data)
	{
		//������ռ�
		Node<T>* NewNode = new Node<T>(data);

		if (NewNode == nullptr)
		{
			cout << "����ʧ��!" << endl;
			return nullptr;
		}
	/*	NewNode->_data = data;
		NewNode->_next = nullptr;*/

		return NewNode;
	}

	//��������
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

	//����
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

	//��ӡ
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
	//β��
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
			//����һ����ʱ�ڵ�ָ����
			Node<T>* ptr = phead;
			while (ptr->_next!=nullptr)
			{
				ptr = ptr->_next;
			}
			ptr->_next = NewNode;
		}
	}

	//ͷ��
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
			phead = NewNode;//����һ��ͷ���
		}
	}

	//βɾ��
	void Pop_Back()
	{
		if (phead->_next==nullptr)
		{
			delete phead;
			phead = nullptr;
			return;
		}

		//����������ʱָ��ָ��ͷ�ڵ�
		Node<T>* perv = phead;//ǰ��
		Node<T>* pail = phead;//���

		while (pail->_next != nullptr)
		{
			perv = pail;
			pail = pail->_next;
		}
		perv->_next =nullptr;
		delete pail;
	}

	//ͷɾ
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

//������Ļ����������⣺����ָ��
//1.Ϊʲôһ����������û�п��ܴ������Զ׷���ϣ���֤��
//2.slowһ����һ����fast��3����4����5����n�� ��֤��
// 
// 
//1.����slow����ѭ��ʱ��fast��slow���n��fast׷��slow�ľ������£�
//n->n-2->n-4->n-6->....4->2->0�����ջ�������
//
//2.������ΪnΪż��ʱ�����ϣ�����׷�ϣ��������nΪ������׷���������£�
//n->n-2->n-4->...3->1->-1;��ʱΪ-1ʱ������Ȼ��������һ��׷����ʱ�ľ���Ϊc-1
//Ȼ���c-1���з��������c-1Ϊż��������׷�ϣ����Ϊ����������Զ׷���ϡ�