#include<iostream>

using namespace std;

//template<class T>
////void Swap(T& x, T& y) {
////	T tmp = x;
////	x = y;
////	y = tmp;
////	cout << x << " " << y << endl;
////}
////用函数模版生成对应函数->模版的实例化
//T Add(const T& x, const T& y) {
//	return x + y;
//}
template<typename T>
class Stack {
private:
	T* _arrary;
	T _capacity;
	T _size;
public:
	Stack(int n = 4) :_arrary(new T[n]), _capacity(n), _size(0) {};
	~Stack() {
		delete[] _arrary;
		_arrary = nullptr;
		_size = _capacity = 0;
	}
	void push(const T& x) {
		if (_size = _capacity) {
			T* tmp = new T[_capacity * 2];
			memcpy(tmp, _arrary, sizeof(T) * _size);
			delete[]_arrary;

			_arrary = tmp;
			_capacity *= 2;
		}
		_arrary[_size++] = x;
	}
};
int main()
{
	//int x, y;
	//x = 1, y = 2;
	//Swap(x, y);
	/*int a1 = 10, a2 = 20;
	double a3 = 1.1, a4 = 1.2;
	Add(a1, a2);
	Add(a3, a4);*/

	//推导实例化
	//cout << Add((double)a1, a4) << endl;

	////显示实例化
	//cout << Add<int>(a3, a4) << endl;
	//类模版都是显示实例化		
	Stack<int>st1;
	st1.push(1);

	return 0;
}