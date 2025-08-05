#pragma once
#include<iostream>

using namespace std;
namespace key
{
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

		/*⼆叉搜索树的删除
			⾸先查找元素是否在⼆叉搜索树中，如果不存在，则返回false。
			如果查找元素存在则分以下四种情况分别处理：（假设要删除的结点为N）
			1. 要删除结点N左右孩⼦均为空
			2. 要删除的结点N左孩⼦位空，右孩⼦结点不为空
			3. 要删除的结点N右孩⼦位空，左孩⼦结点不为空
			4. 要删除的结点N左右孩⼦结点均不为空
			对应以上四种情况的解决⽅案：
			1. 把N结点的⽗亲对应孩⼦指针指向空，直接删除N结点（情况1可以当成2或者3处理，效果是⼀样
			的）
			2. 把N结点的⽗亲对应孩⼦指针指向N的右孩⼦，直接删除N结点
			3. 把N结点的⽗亲对应孩⼦指针指向N的左孩⼦，直接删除N结点
			4. ⽆法直接删除N结点，因为N的两个孩⼦⽆处安放，只能⽤替换法删除。找N左⼦树的值最⼤结点
			R(最右结点)或者N右⼦树的值最⼩结点R(最左结点)替代N，因为这两个结点中任意⼀个，放到N的
			位置，都满⾜⼆叉搜索树的规则。替代N的意思就是N和R的两个结点的值交换，转⽽变成删除R结
			点，R结点符合情况2或情况3，可以直接删除。*/
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

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
					//判断有0-1个孩子
					//如果左孩子为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
						return true;
					}
					//如果右孩子为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
						return true;
					}
					//左右不为空
					//找一个节点，右子树的最左节点或者左子树的最右节点
					else
					{
						Node* replaceParent = cur;
						Node* replace = cur->_right;//这里是找的一个替代节点：cur的右子树
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;
						if (replaceParent->_left == replace)
						{
							replaceParent->_left = replace->_right;
						}
						else
						{
							replaceParent->_right = replace->_right;
						}
						delete replace;
					}
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
	private:
		Node* _root = nullptr;
	};
}
 /*key / value搜索场景：
每⼀个关键码key，都有与之对应的值value，value可以任意类型对象。树的结构中(结点)除了需要存
储key还要存储对应的value，增 / 删 / 查还是以key为关键字⾛⼆叉搜索树的规则进⾏⽐较，可以快速查
比特就业课
找到key对应的value。key / value的搜索场景实现的⼆叉树搜索树⽀持修改，但是不⽀持修改key，修
改key破坏搜索树性质了，可以修改value。
场景1：简单中英互译字典，树的结构中(结点)存储key(英⽂)和vlaue(中⽂)，搜索时输⼊英⽂，则同时
查找到了英⽂对应的中⽂。
场景2：商场⽆⼈值守⻋库，⼊⼝进场时扫描⻋牌，记录⻋牌和⼊场时间，出⼝离场时，扫描⻋牌，查
找⼊场时间，⽤当前时间 - ⼊场时间计算出停⻋时⻓，计算出停⻋费⽤，缴费后抬杆，⻋辆离场。
场景3：统计⼀篇⽂章中单词出现的次数，读取⼀个单词，查找单词是否存在，不存在这个说明第⼀次
出现，（单词，1），单词存在，则++单词对应的次数。*/
namespace key_value
{
	template<class K,class V>

	struct BSTNode
	{
		K _key;
		V _value;
		BSTNode<K,V>* _left;
		BSTNode<K,V>* _right;

		BSTNode(const K& key,const V& value) :_key(key),_value(value), _left(nullptr), _right(nullptr) {}

	};

	template<class K,class V>
	class BSTree
	{
		typedef BSTNode<K,V> Node;//定义了Node作为BSTNode<K>的别名，方便使用
		//用using Node=BSTNode<K>也行
	public:
		//强制构造
		BSTree() = default;

		//拷贝构造
		BSTree(const BSTree<K, V>& t)
		{
			_root = Copy(t._root);
		}

		//析构
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		//赋值重载
		//现代写法
		BSTree<K, V>& operator=(const BSTree<K, V>& t)
		{
			std::swap(_root, t._root);
			return *this;
		}
		bool Insert(const K& key,const V& value)
		{
			if (_root == nullptr)//树为空，直接开空间增加节点
			{
				_root = new Node(key,value);
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
			cur = new Node(key,value);

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

		Node* Find(const K& key)
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
					return cur;
				}
			}
			return nullptr;
		}

		
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

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
					//判断有0-1个孩子
					//如果左孩子为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
						return true;
					}
					//如果右孩子为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
						return true;
					}
					//左右不为空
					//找一个节点，右子树的最左节点或者左子树的最右节点
					else
					{
						Node* replaceParent = cur;
						Node* replace = cur->_right;//这里是找的一个替代节点：cur的右子树
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;
						if (replaceParent->_left == replace)
						{
							replaceParent->_left = replace->_right;
						}
						else
						{
							replaceParent->_right = replace->_right;
						}
						delete replace;
					}
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
			cout << _root->_key << " " << _root->_value << endl;;
			_InOrder(_root->_right);
		}
		//析构
		void Destroy(Node* _root)
		{
			if (_root == nullptr)
			{
				return;
			}
			Destroy(_root->_left);
			Destroy(_root->_right);

			delete _root;
		}
		
		//深拷贝
		Node* Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* newRoot = new Node(root->_key, root->_value);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);

			return newRoot;
		}

	private:
		Node* _root = nullptr;
	};
}

