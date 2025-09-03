 #pragma once
#include<iostream>

using namespace std;

template<class T>
class TreeNode
{
public:

	TreeNode(const T& data) :val(data),left(nullptr),right(nullptr){}

	T val;
	TreeNode* left;
	TreeNode* right;
};

template<class T>
class Tree
{
public:
	
	Tree() :root(nullptr){}

	//创建节点
	TreeNode<T>* CreateTreeNode(const T& data)
	{
		TreeNode<T>* node = new TreeNode<T>(data);
		if (node == nullptr)
		{
			cout << "fail!" << endl;
			return nullptr;
		}

		return node;
	}

	//插入
	void Insert(const T& data)
	{
		if (root == nullptr)
		{
			root = CreateTreeNode(data);
		}

		TreeNode<T>* current = root;
		TreeNode<T>* parent = nullptr;

		while (current != nullptr)
		{
			parent = current;
			if (data < current->val)
			{
				current = current->left;
			}
			else if (data > current->val)
			{
				current = current->right;
			}
			else
			{
				return;
			}
		}
			TreeNode<T>* NewNode = CreateTreeNode(data);

			if (data < parent->val)
			{
				parent->left = NewNode;
			}
			else if(data>parent->val)
			{
				parent->right = NewNode;
			}
		
	}
	//前序遍历前置函数
	void Perv_PervOrder(TreeNode<T>* root)
	{
		if (root == nullptr)
		{
			cout << "N" << " ";
			return;
		}

		cout << root->val << " ";
		Perv_PervOrder(root->left);
		Perv_PervOrder(root->right);
		cout << endl;
	}
	
	//前序遍历
	void PervOrder()
	{
		cout << "前序遍历:" << endl;
		Perv_PervOrder(root);
	}

	//中序遍历前置函数
	void Perv_InOrder(TreeNode<T>* root)
	{
		if (root == nullptr)
		{
			cout << "N" << " ";
			return;
		}

		Perv_InOrder(root->left);
		cout << root->val << " ";
		Perv_InOrder(root->right);
		cout << endl;
	}

	//中序遍历
	void InOrder()
	{
		cout << "中序遍历:" << endl;
		Perv_InOrder(root);
	}

	//后序遍历前置函数
	void Perv_PostOrder(TreeNode<T>* root)
	{
		if (root == nullptr)
		{
			cout << "N" << " ";
			return;
	
		}

		Perv_PostOrder(root->left);
		Perv_PostOrder(root->right);
		cout << root->val << " ";
	}

	//后序遍历
	void PostOrder()
	{
		cout << "后序遍历:" << endl;
		Perv_PostOrder(root);
	}
private:

	TreeNode<T>* root;
};

