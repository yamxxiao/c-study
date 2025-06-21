#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

namespace yamx
{
	template<class T>
	class vector
	{ 
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector(T* start=nullptr,T* finish=nullptr,T* end_of_storage=nullptr):_start(start),_finish(finish),_end_of_storage(end_of_storage){}

		size_t size() const
		{
			return _finish-_start;
		}
		
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty() const
		{
			return _finish == _start;
		}
		
		//实现与迭代器有关的函数begin()与end()
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		//开空间的时候尽量使用new而不是malloc，因为malloc只是去开空间，不会调用构造函数
		void reserve(size_t n)//扩容
		{
			if (n > capacity())//n大于数组容量才扩容
			{
				size_t oldsize = size();//用oidsize避免_start和老_finish的问题
				//memcpy(tmp,_start,size()*sizeof(T));
				//这里是浅拷贝，如果是内置类型就没问题，如果vector存的是自定义类型就是个大坑
				//例如要拷贝的是string类型，那么扩容的时候将数据从旧空间复制到新空间时，因为旧空间的_str的地址与新空间的是同一个，那么在
				//释放空间的时候会把新空间也一起释放掉了

				T* tmp = new T[n];
				for (size_t i = 0; i < oldsize; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;

				//新_start和_inish问题:当开辟出新空间后_start指向的是新空间 而_finish和_end_of_storage指向的是旧空间，这两个指针就成能为野指针了
				// 就成为了下列的一种情况
				// _start=tmp;
				// _finish=tmp+size()->_start+_finish-_start->_finish=_finish
				//跟新成员变量
				_start = tmp;
				_finish = tmp+oldsize;
				_end_of_storage=tmp+n;
			}
		}

		void push_back( const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			//插入元素，跟新_finish
			*_finish = x;
			_finish++;
		}


		vector() = default;	
		//类模版的成员函数还可以继续是函数模版
	//给这个函数套上一个模版是为了不仅仅可以继续使用vector迭代器区间的构造，还能适用其他的容器的迭代器进行构造
		template<class TnputIerator>
		vector(TnputIerator first, TnputIerator last)
		{
			while (first != last)//循环条件的！-不能改成<,但是vector可以,因为其他的容器的last不一定比first大
			{	
				push_back(*first);
				++first;
			} 
		}

		//使用n个val来进行构造
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		//析构
		~vector()
		{
			if(_start)
			{
				delete _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		//拷贝构造
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto V : v)
			{
				push_back(V);
			}
		}

		//像数组一样访问
		T& operator[](size_t i)
		{
			assert(i < size());
				return _start[i];
		}

		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		//赋值重载
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector<T>& operator=(vector<T>& v)
		{
			swap(v);
			return *this;
		}

		//增删改查
		void clear()
		{
			_finish = _start;
		}

		void pop_back()
		{
			//判断是否为空
			assert(!empty());
			--_finish;
		}
		/*friend ostream& operator>>(ostream& out, vector<T>& v);*/

		//插入
		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			//扩容
			if (_finish == _end_of_storage)
			{
				//为了防止扩容后迭代器失效，即pos成为野指针，因为在扩容后，pos指向的任然是旧空间的位置，但是旧空间已经被释放了
				//所以 就创建一个len的临时变量记录下pos的相对位置，扩容后在加上相对位置即可
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			iterator end=_finish-1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}
		//删除pos位置的元素
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _start);

			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				--_finish;
			}
			return pos;
		}
	private:
		iterator _start;//指向头部元素
		iterator _finish;//指向尾部元素
		iterator _end_of_storage;//指向空间末尾
		//通过这三个指针可以模拟出size和capacity的功能
	};
	template<typename T>
	void Print_vector(vector<T>& v)
	{
		typename vector<T>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	/*ostream& operator>>(ostream& out, vector<T>& v)
	{
		for (auto e : v)
		{
			out << e << " ";
		}
		out << endl;
		return out;
	}*/
}
void Test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 1);

	vector<int> v3(++v2.begin(), --v2.end());

	//三种遍历方式

	for (size_t i = 0; i < v3.size() - 1; i++)
	{
		cout << v3[i] <<" ";
	}
	cout << endl;
	vector<int>::iterator it = v3.begin();

	while (it != v3.end())
	{
		cout << *it <<" ";
		++it;
	}
	cout << endl;
	for (auto v : v3)
	{
		cout << v << " ";
	}
	cout << endl;
}

void Test_vector2()
{
	vector<int> v(10, 1);

	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << endl;

	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << endl;

	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void Test_vecotor3()
{
	vector<int> v(10, 1);

	v.push_back(2);
	v.insert(v.begin(), 0);
	
	int x;
	cin >> x;
	v.push_back(x);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}

}

void Test_vector4()
{
	vector<string> v4;
	v4.push_back("xxxxxxx");

	//string与int 不一样 底层可能调用深拷贝所以要加const &

	for (const auto& v : v4)
	{
		cout << v << " ";
	}
	cout << endl;

	vector<int> v5(5, 1);
	//二维数组
	vector<vector<int>> vv(10, v5);
}
int main()
{
	/*Test_vector1();*/
	/*Test_vector2();*/
	/*Test_vecotor3();*/
	//Test_vector4();
	yamx::vector<int> v(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	/*for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;*/
	//yamx::Print_vector(v);
	//v.insert(v.begin()+2, 6);
	//yamx::Print_vector(v);
	string str("Hello Bit.");

	/*str.reserve(111);

	str.resize(5);

	str.reserve(50);*/
	string str1("eeeeeeeeeeeeeeeeeeee");
	cout << str1.size() << ":" << str1.capacity() << endl;
	return 0;
}