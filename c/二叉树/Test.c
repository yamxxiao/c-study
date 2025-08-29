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
	return 0;
}