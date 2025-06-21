#include<iostream>

using namespace std;

class A {
private:
	int _a1 = 1;
	int _a2 = 1;

public:
	A(int a1 = 0, int a2 = 0) :_a1(a1), _a2(a2) {
		cout << "a1=1,a2=2" << endl;
	};
	~A() {
		cout << "~A()" << endl;
	}
};
int main()
{
	//c++中new 动态申请空间

	/*int* p1 = new int;
	int* p2 = new int[10];*/

	//delete 释放空间

	/*delete p1;
	delete[] p2;*/
	//A* a1 = new A();
	//A* a2 = new A(2, 2);
	//A* a3 = new A[3];
	//两种初始化方式
	A* a1 = new A[3]{ A(1,1),A(2,2),A(3,3) };

	A* a2 = new A[3]{ {1,1},{2,2},{3,3} };
	return 0;
}