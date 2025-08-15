#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	//需要parent指针,后续更新平稳因子可以看到
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

				//链接父亲
				cur->_parent = parent;

				//控制平衡
				//更新平衡因子

				while (parent)
				{
					//更新平衡因子
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
						//更新结束
						break;
					}
					else if (parent->_bf == 1 || parent->_bf == -1)
					{
						//继续往上更新
						cur = parent;
						parent = parent->_parent;
					}
					else if (parent->_bf == 2 || parent->_bf == -2)
					{
						//不平衡了，旋转处理
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