#pragma once
#include<iostream>

using namespace std;

template<class K>

struct BSTNode
{
	K _key;
	BSTNode<K>* _left;
	BSTNode<K>* _right;

	BSTNode(const K& key) :_key(key), _left(nullptr), _right(nullptr) {}

};

template<class K>
class BSTree
{
	typedef BSTNode<K> Node;//定义了Node作为BSTNode<K>的别名，方便使用
	//用using Node=BSTNode<K>也行
public:
	//二叉树的插入：
	//插⼊的具体过程如下：
	/*	1. 树为空，则直接新增结点，赋值给root指针
		2. 树不空，按⼆叉搜索树性质，插⼊值⽐当前结点⼤往右⾛，插⼊值⽐当前结点⼩往左⾛，找到空位
		置，插⼊新结点。
		3. 如果⽀持插⼊相等的值，插⼊值跟当前结点相等的值可以往右⾛，也可以往左⾛，找到空位置，插
		⼊新结点。（要注意的是要保持逻辑⼀致性，插⼊相等的值不要⼀会往右⾛，⼀会往左⾛）*/
	bool Insert(const K& key)
	{
		if (_root == nullptr)//树为空，直接开空间增加节点
		{
			_root = new Node(key);
			return true;
		}
		 
		Node* parent = nullptr;// 用于记录当前节点的父节点
		Node* cur = _root;//初始时指向根节点，用于遍历树
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		/*当 cur 变为 nullptr 时，找到了合适的插入位置。
			创建一个新节点 cur 并初始化其关键值为 key。
			根据 parent 的关键值与 key 的关系，将新节点连接到 parent 的左子节点或右子节点。*/
		cur = new Node(key);

		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}//总结下来就是，先判断根节点是否为空，如果为空，开空间，不为空，创建一个cur指向初始节点根节点。
	//再根据二叉搜索树的性质，遍历左右节点。
	//最后cur为nullptr时，找到合适的位置插入，创建一个新的节点cur将值存入进去，根据 parent 的关键值与 key 的关系，将新节点连接到 parent 的左子节点或右子节点。
	
	bool Find(const K& key)
	{
		Node* cur = _root;
		
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_right;
			}
			else if (cur->_key < key)
			{
				cur = cur->_left;
			}

			else
			{
				return true;
			}
		}
		return false;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_InOrder(_root->_left);
		cout << _root->_key << " ";
		_InOrder(_root->_right);
	}

	bool Erase(const K& key)
	{

	}
private:
	Node* _root = nullptr;
};

