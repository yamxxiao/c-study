#include"Tree.h"

int main()
{
	//BTNode* root= CreateBTree();
	//PervOrder(root);
	BTree* tree = InitBTree();
	Insert(tree, 1);
	Insert(tree, 2);
	Insert(tree, 3);
	Insert(tree, 4);
	Insert(tree, 5);
	Insert(tree, 6);
	Insert(tree, 7);

	PervOrder(tree);
	InOrder(tree);
	PostOrder(tree);
	printf("���ĸ߶ȣ�%d\n", BTreeHeight(tree->root));
	printf("����Ҷ�ӽڵ������%d\n", BTreeLeafSize(tree->root));
	printf("�����ܽ������%d\n", BTreeSize(tree->root));
	BTreeDestroy(tree->root);
	return 0;
}