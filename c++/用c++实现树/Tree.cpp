#include"Tree.h"

int main()
{
	Tree<int> tree;
	tree.Insert(1);
	tree.Insert(2);
	tree.Insert(3);
	tree.Insert(4);
	tree.Insert(5);
	tree.Insert(6);
	tree.PervOrder();
	tree.InOrder();
	tree.PostOrder();

	return 0;
}