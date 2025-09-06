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
	printf("树的高度：%d\n", BTreeHeight(tree->root));
	printf("树的叶子节点个数：%d\n", BTreeLeafSize(tree->root));
	printf("树的总结点数：%d\n", BTreeSize(tree->root));
	BTreeDestroy(tree->root);
	return 0;
}