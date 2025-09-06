 #pragma once
#include<iostream>
#include<queue>

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

	//�����ڵ�
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

	//����
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
	//ǰ�����ǰ�ú���
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
	
	//ǰ�����
	void PervOrder()
	{
		cout << "ǰ�����:" << endl;
		Perv_PervOrder(root);
	}

	//�������ǰ�ú���
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

	//�������
	void InOrder()
	{
		cout << "�������:" << endl;
		Perv_InOrder(root);
	}

	//�������ǰ�ú���
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

	//�������
	void PostOrder()
	{
		cout << "�������:" << endl;
		Perv_PostOrder(root);
	}

	void clear(TreeNode<T>* root)
	{
		if (root == nullptr)
		{
			return;
		}

		clear(root->left);
		clear(root->right);
		delete root;

	}

	~Tree()
	{
		clear(root);
	}
	
	//�������
	void BFS(TreeNode<T>& root)
	{
		queue<T> tree;
		tree.push(root);
		int levelSize = tree.size();
		while (tree != empty())
		{
			for (int i = 0; i < levelSize; i++)
			{
				TreeNode<T>* current = tree.front();
				tree.pop();
				cout << current->val << " ";

				if (current->left != nullptr)
				{
					tree.push(current->left);
				}
				if (current->right != nullptr)
				{
					tree.push(current->right);
				}
			}
			cout << endl;
		}
	}
private:

	TreeNode<T>* root;
};
