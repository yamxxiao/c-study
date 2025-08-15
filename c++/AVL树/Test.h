#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	//��Ҫparentָ��,��������ƽ�����ӿ��Կ���
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf; //balance factor

	AVLTreeNode(const pair<K,V>& kv):_kv(kv),_left(nullptr),_right(nullpytr),_parent(nullptr),_bf(0){}

};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
	
public:
	bool Insert(pair<K, V>& avl)
	{
		if (_root == nullptr)
		{
			_root = new pair(avl);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first < avl.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > avl.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}

			cur = new Node(avl);

				if (parent->_kv.first < avl.first)
				{
					parent->_right = cur;

				}
				else if (parent->_kv.first > avl.first)
				{
					parent->_left = cur;
				}

				//���Ӹ���
				cur->_parent = parent;

				//����ƽ��
				//����ƽ������

				while (parent)
				{
					//����ƽ������
					if (cur == parent->_left)
					{
						parent->_bf--;
					}
					else
					{
						parent->_bf++;
					}

					if (parent->_bf == 0)
					{
						//���½���
						break;
					}
					else if (parent->_bf == 1 || parent->_bf == -1)
					{
						//�������ϸ���
						cur = parent;
						parent = parent->_parent;
					}
					else if (parent->_bf == 2 || parent->_bf == -2)
					{
						//��ƽ���ˣ���ת����
						break;
					}
					else
					{
						assert(false);
					}
				}
				return true;
		}
	}
private:
	Node* _root = nullptr;
};