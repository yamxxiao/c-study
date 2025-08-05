#include"Test.h"
int main()
{
	//int a[] = { 1,3,4,6,7,8,10,13,14 };
	//BSTree<int> tree;
	//for (auto e : a)
	//{
	//	tree.Insert(e);
	//}
	//tree.InOrder();

	//tree.Insert(16);
	//tree.InOrder();

	//tree.Erase(8);
	//tree.InOrder();
	//key_value::BSTree<string, string> dict;
	////BSTree<string, string> copy = dict;
	//dict.Insert("left", "左边");
	//dict.Insert("right", "右边");
	//dict.Insert("insert", "插⼊");
	//dict.Insert("string", "字符串");

	//string str;
	//while (cin >> str)
	//{
	//	auto ret = dict.Find(str);
	//	if (ret)
	//	{
	//		cout << "->" << ret->_value << endl;
	//	}
	//	else
	//	{
	//			cout << "⽆此单词，请重新输⼊" << endl;
	//	}
	//}

	string arr[] = { "苹果", "西⽠", "苹果", "西⽠", "苹果", "苹果", "西⽠", "苹果","⾹蕉", "苹果", "⾹蕉" };
key_value::BSTree<string, int> countTree;
for (const auto& str : arr)
{
	// 先查找⽔果在不在搜索树中
	// 1、不在，说明⽔果第—次出现，则插⼊<⽔果, 1>
	// 2、在，则查找到的结点中⽔果对应的次数++
	//BSTreeNode<string, int>* ret = countTree.Find(str);
	auto ret = countTree.Find(str);
	if (ret == NULL)
	{
	countTree.Insert(str, 1);
	}
	else
	{
	ret->_value++;
	}
	}
	countTree.InOrder();
	return 0;
}