#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<class T>
class ListNode
{
public:
	T _data;
	ListNode* _perv;
	ListNode* _next;

	ListNode(const T& data) :_data(data), _perv(nullptr), _next(nullptr){}

};

template<class T>
class List
{
public:
	//���캯������ʼ���ڱ�λ
	List()
	{
		_phead = new ListNode<T>(-1);
		_phead->_perv = _phead->_next = _phead;//��ʼʱ���ڱ�λ��ǰ���ͺ��ָ�붼ָ���Լ�
	}
	//����
	~List()
	{
		clear();
	}

	//����
	void clear()
	{
		ListNode<T>* puctr = _phead->_next;

		while (puctr!= _phead)
		{
			ListNode<T>* OldPuctr = puctr->_next;
			delete puctr;
			puctr = OldPuctr;
		}
		_phead->_perv = _phead;
		_phead->_next = _phead;
		delete _phead;
		cout << "������" << endl;
	}
	//��Ч����,��Ҳ���ԸĽ�
	////����
	//ListNode<T>* BuyCapacity(const T& data)
	//{
	//	assert(_phead);
	//	ListNode<T>* NewNode =new ListNode<T>(data);

	//	if (_phead->_next==nullptr)
	//	{
	//		NewNode->_perv = _phead;
	//		NewNode->_next = _phead;

	//		_phead->_perv = NewNode;
	//		_phead->_next = NewNode;

	//	}
	//	else
	//	{
	//		NewNode->_perv = _phead->_perv;
	//		NewNode->_next = _phead;
	//		_phead->_perv->_next = NewNode;
	//		_phead->_perv = NewNode;
	//	}
	//	return NewNode;
	//}

	void Print()
	{
		assert(_phead->_next);
		ListNode<T>* puctr = _phead->_next;

		while (puctr!=_phead)
		{
			cout << puctr->_data << "->";
			puctr = puctr->_next;
		}
		cout << "nullptr" << endl;
	}

	//β����
	void Push_Back(const T& data)
	{
		ListNode<T>* NewNode = new ListNode<T>(data);

		if (_phead->_next == nullptr)
		{
			NewNode->_perv = _phead;
			NewNode->_next = _phead;

			_phead->_perv = NewNode;
			_phead->_next = NewNode;

		}
		else
		{
			NewNode->_perv = _phead->_perv;
			NewNode->_next = _phead;
			_phead->_perv->_next = NewNode;
			_phead->_perv = NewNode;
		}
	}

	//ͷ��
	void Push_Front(const T& data)
	{
		assert(_phead);

		ListNode<T>* NewNode =new ListNode<T>(data);

		NewNode->_perv = _phead;
		NewNode->_next = _phead->_next;

		_phead->_next->_perv = NewNode;
		_phead->_next = NewNode;

	}

	//βɾ��
	void Pop_Back()
	{
		assert(_phead && _phead->_next != _phead);

		_phead->_perv = _phead->_perv->_perv;
		_phead->_perv->_perv->_next = _phead;
		
		delete _phead->_perv;
		_phead->_perv = nullptr;
	}

	//ͷɾ
	void Pop_Front()
	{
		assert(_phead && _phead->_next != _phead);

		ListNode<T>* putr = _phead->_next;
		putr->_perv = _phead;
		_phead->_next = putr->_next;
		
		delete putr;
		putr = nullptr;
	}

	//ָ��ֵ����
	ListNode<T>* Find(const T& pos)
	{
		assert(_phead);

		ListNode<T>* puctr = _phead->_next;

		while (puctr != _phead)
		{
			if (puctr->_data == pos)
			{
				cout << "�ҵ���" << endl;
				return puctr;
			}
			puctr = puctr->_next;
		}
		cout << "û���ҵ�" << endl;
		//û���ҵ�
		return nullptr;
	}

	//ָ��ֵɾ��
	void Erase(const T& pos)
	{
		assert(_phead && _phead->_next != _phead);

		ListNode<T>* find =_phead->_next;
		
		while (find != _phead)
		{
			if (find->_data == pos)
			{
				ListNode<T>* oldfind = find->_next;
				find->_perv->_next = oldfind;
				oldfind->_perv = find->_perv;

				delete find;
				find = nullptr;
				find = oldfind;
				cout << "ɾ���ɹ�" << endl;
			}
			else
			{
				find = find->_next;
			}
		}
	}
private:
	ListNode<T>* _phead;//�ڱ�λ
};
