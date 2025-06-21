#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<class T>
class list_node
{
public:
	T _data;
	list_node<T>* _next;
	list_node<T>* _prev;

	list_node(T data=T()):_next(nullptr),_prev(nullptr){}
};
template<class T,class Ref,class Ptr>
class list_iterator//����ʹ��classҲ��һ���ģ���������ĵ�����������Ҫ�����ʹ�ã���class�ĳ�Ա������Ĭ��˽�еģ�struct���ǹ��еģ����������㡣
					//����class ����Ҫ��friend�޶���
{	
public:
	typedef list_node<T>* Node;
	typedef list_iterator<T, const T&, const T*> const_iterator;
	typedef list_iterator<T, Ref, Ptr> Self;
	Node* get_node() const { return _node; }

	Node* _node;

	list_iterator(Node* node):_node(node){}

	T& operator*()//��ͬ��vector[]����������
	{
		return _node->_data;
	}

	T* operator->()//��ͬ��vector.at()
	{
		return &_node->_data;
	}

	const T& operator*()const
	{
		return _node->_data;
	}

	const T* operator->()const
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self temp = *this; //���浱ǰ������״̬
		_node = _node->_next;
		return temp;
	}
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self temp = *this; //���浱ǰ������״̬
		_node = _node->_prev;
		return temp;
	}

	bool operator!=(const Self& s)const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)const
	{
		return _node == s._node;
	}
};
//��������߶����Ƶ�ʱ��
//template<class T>
//class list_cosnt_iterator
//	
//{
//public:
//	typedef list_node<T>* Node;
//	typedef list_cosnt_iterator<T>* Self;
//
//	Node* _node;
//
//	list_cosnt_iterator(Node* node) :_node(node) {}
//
//	const T& operator*()//��ͬ��vector[]����������
//	{
//		return _node->_data;
//	}
//
//	const T* operator->()//��ͬ��vector.at()
//	{
//		return &_node->_data;
//	}
//
//	Self& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	Self operator++(int)
//	{
//		Self temp = *this; //���浱ǰ������״̬
//		_node = _node->_next;
//		return temp;
//	}
//	Self& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//
//	Self operator--(int)
//	{
//		Self temp = *this; //���浱ǰ������״̬
//		_node = _node->_prev;
//		return temp;
//	}
//
//	bool operator!=(const Self& s)const
//	{
//		return _node != s._node;
//	}
//
//	bool operator==(const Self& s)const
//	{
//		return _node == s._node;
//	}
//};
template<class T>
class list
{
	typedef list_node<T> Node;
public:
	typedef list_iterator<T,T&,T*> iterator;
	typedef list_iterator<T,const T&,const T*> const_iterator;
	
	iterator begin()
	{
		return  _head->_next;
	}

	iterator end()//�ڱ�λ��ͷ���
	{
		return _head;
	}

	const_iterator cbegin()const
	{
		return _head->_next;
	}
	
	const_iterator cend()const
	{
		return _head;
	}
	void empty_init()//�ճ�ʼ��
	{
		_head = new Node(T());
		_head->_next = _head;
		_head->_prev = _head;
		_size = 0;
	}
	list()//�޲ι��죬�ڱ�λ��ǰ���ͺ��ָ��ָ���Լ���ʵ��һ���ռ���ѭ��
	{
		empty_init();
	}

	list(const list<T>& lt)
	{
		empty_init();//������ﲻд�ճ�ʼ������ô�ڱ�λ��λ�þ�δ֪��
		for (auto& e : lt)
		{
			push_back(e);
		}	
	}
	void swap(list<T>& lt)
	{
		std::swap(_head, lt._head);
		std::swap(_size, lt._size);
	}
	list<T>& operator=(list<T> lt)
	{
		swap(lt);
		return *this;
	}
	size_t sizer()const
	{
		return _size;
	}

	bool empty()const
	{
		return _size == 0;
	}
	void push_back(const T& x)
	{
		Node* newnode = new Node(x);
		Node* tail = _head->_prev;

		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head;
		_head->_prev = newnode;

		++_size;
	}

	iterator arase(iterator pos)
	{
		assert(pos != end());
		Node* cur = pos.getget_node();
		Node* prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;
		
		delete cur;
		--_size;

		return iterator(next);
	}

	~list()
	{
		clear();
		delete _head;
		_head = nullptr;
	}

	void clear()
	{
		auto it = begin();
		while (it != end())
		{
			arase(it);
			++it;
		}
	}

private:
	Node* _head;
	size_t _size;
};

template<class T>
void Print_list(list<T>& lt)
{
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template<class T>
void Print_const_list(const list<T>& lt)
{
	list<int>::const_iterator it = lt.cbegin();
	while (it != lt.cend())
	{
		//const_ierator ������ʵ��������޸�Ԫ��
	//�����Ҫ�޸�Ԫ�أ�����Ҫʹ�÷�const_ierator
		/**it += 10;*/
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
