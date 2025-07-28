#include"Test.h"

int main()
{
	/*Stack<5> s1;
	Stack<12> s2;*/
	/*cout << Less(1, 2) << endl;*/ // 输出1
	Date d1(2025, 7, 27);
	Date d2(2025, 7, 28);
	//cout << Less(d1, d2) << endl;
	//此时编译器会报错c2676，原因是T未定义类型，因为这里要比较的是Date日期类，所以需要进行模版特化
	cout << Less(d1, d2) << endl;
	//模版特化之后，就不会报错了
	/*TestData();*/
	Test2();
	return 0;
}