#pragma once
#include"stdio.h"
#include"assert.h"
#include"stdlib.h"
#include"stdbool.h"
#include"math.h"

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//void BTreeInit(BTNode* root)
//{
//	root->left = NULL;
//	root->right = NULL;
//
//}
//BTNode* BuyNode(BTDataType x)
//{
//	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//
//	if (node == NULL)
//	{
//		printf("fail!\n");
//		exit(1);
//	}
//
//	node->val = x;
//	node->left = NULL;
//	node->right = NULL;
//
//	return node;
//}
//
//BTNode* CreateBTree()
//{
//	BTNode* node1 = BuyNode(1);
//	BTNode* node2 = BuyNode(2);
//	BTNode* node3 = BuyNode(3);
//	BTNode* node4 = BuyNode(4);
//	BTNode* node5 = BuyNode(5);
//	BTNode* node6 = BuyNode(6);
//
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	node4->left = node5;
//	node4->right = node6;
//
//	return node1;
//
//}
//
//void PervOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	printf("%d ", root->val);
//	PervOrder( root->left);
//	PervOrder( root->right);
//}
typedef struct BTree
{
	BTNode* root;
}BTree;

//�����ڵ�
BTNode* CreateBTree(BTDataType data)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));

	if (node == NULL)
	{
		printf("fail!\n");
		return NULL;
	}
	
	node->val = data;
	node->right = NULL;
	node->left = NULL;
	
	return node;
}
//��ʼ��
BTree* InitBTree()
{
	BTree* tree = (BTree*)malloc(sizeof(BTree));
	tree->root = NULL;
	return tree;
}
//ǰ�����
void BTPervOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	printf("%d ", root->val);
	BTPervOrder(root->left);
	BTPervOrder(root->right);
}

//�������
void BTInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BTInOrder(root->left);
	printf("%d ", root->val);
	BTInOrder(root->right);
}
//�������
void BTPostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BTPostOrder(root->left);
	BTPostOrder(root->right);
	printf("%d ", root->val);
}
void PervOrder(BTree* tree)
{
	if (tree->root == NULL)
	{
		return;
	}
	printf("ǰ�����:");
	BTPervOrder(tree->root);
	printf("\n");
}
void InOrder(BTree* tree)
{
	if (tree->root == NULL)
	{
		return;
	}
	printf("�������:");
	BTInOrder(tree->root);
	printf("\n");
}
void PostOrder(BTree* tree)
{
	if (tree->root == NULL)
	{
		return;
	}
	printf("�������:");
	BTPostOrder(tree->root);
	printf("\n");
}
//�������ڵ�
BTNode* InsertBTree(BTNode*root, BTDataType data)
{
	//�ݹ鷨
	if (root == NULL)
	{
		root = CreateBTree(data);
		return root;
	}
	else
	{
		if (data < root->val)
		{
			root->left=InsertBTree(root->left,data);
		}
		else if (data > root->val)
		{
			root->right=InsertBTree(root->right, data);
		}
		return root;
	}
	////������
	//if (root == NULL)
	//{
	//	root = CreateBTree(data);
	//}
	//else
	//{
	//	BTNode* current = root;
	//	BTNode* parent = NULL;

	//	while (current != NULL)
	//	{
	//		if (data < current->val)
	//		{
	//			parent = current;
	//			current = current->left;
	//		}
	//		else if (data > current->val)
	//		{
	//			parent = current;
	//			current = current->right;
	//		}
	//		else
	//		{
	//			return;
	//		}
	//	}

	//	BTNode* newnode = CreateBTree(data);

	//	if (data < parent->val)
	//	{
	//		parent->left = newnode;
	//	}
	//	else if(data>parent->val)
	//	{
	//		parent->right = newnode;
	//	}
	//}
}

//�ӿڲ���
void Insert(BTree* tree, BTDataType data)
{
	tree->root = InsertBTree(tree->root, data);
}

//��߶ȸ���
int BTreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return fmax(BTreeHeight(root->left), BTreeHeight(root->right)) + 1;
}

//��Ҷ�ӽ�����
int BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BTreeLeafSize(root->left) + BTreeLeafSize(root->right);
}

//���ܽڵ�����
int BTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

//�������k�ڵ��ֵ

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val == x)
	{
		return root;
	}
	BTNode* rte1 = TreeFind(root->left, x);
	return rte1;

	BTNode* rte2 = TreeFind(root->right, x);
	return rte2;
}
