#include"Test.h"
int main()
{
	int a[5] = { 1,2,3,4,5 };
	BSTree<int> tree;
	for (auto e : a)
	{
		tree.Insert(e);
	}
	tree.InOrder();

	tree.Insert(6);
	tree.InOrder();
	return 0;
}