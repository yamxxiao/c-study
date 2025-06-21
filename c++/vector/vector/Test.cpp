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
		
		//ʵ����������йصĺ���begin()��end()
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

		//���ռ��ʱ����ʹ��new������malloc����Ϊmallocֻ��ȥ���ռ䣬������ù��캯��
		void reserve(size_t n)//����
		{
			if (n > capacity())//n������������������
			{
				size_t oldsize = size();//��oidsize����_start����_finish������
				//memcpy(tmp,_start,size()*sizeof(T));
				//������ǳ������������������;�û���⣬���vector������Զ������;��Ǹ����
				//����Ҫ��������string���ͣ���ô���ݵ�ʱ�����ݴӾɿռ临�Ƶ��¿ռ�ʱ����Ϊ�ɿռ��_str�ĵ�ַ���¿ռ����ͬһ������ô��
				//�ͷſռ��ʱ�����¿ռ�Ҳһ���ͷŵ���

				T* tmp = new T[n];
				for (size_t i = 0; i < oldsize; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;

				//��_start��_inish����:�����ٳ��¿ռ��_startָ������¿ռ� ��_finish��_end_of_storageָ����Ǿɿռ䣬������ָ��ͳ���ΪҰָ����
				// �ͳ�Ϊ�����е�һ�����
				// _start=tmp;
				// _finish=tmp+size()->_start+_finish-_start->_finish=_finish
				//���³�Ա����
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
			//����Ԫ�أ�����_finish
			*_finish = x;
			_finish++;
		}


		vector() = default;	
		//��ģ��ĳ�Ա���������Լ����Ǻ���ģ��
	//�������������һ��ģ����Ϊ�˲��������Լ���ʹ��vector����������Ĺ��죬�������������������ĵ��������й���
		template<class TnputIerator>
		vector(TnputIerator first, TnputIerator last)
		{
			while (first != last)//ѭ�������ģ�-���ܸĳ�<,����vector����,��Ϊ������������last��һ����first��
			{	
				push_back(*first);
				++first;
			} 
		}

		//ʹ��n��val�����й���
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		//����
		~vector()
		{
			if(_start)
			{
				delete _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		//��������
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto V : v)
			{
				push_back(V);
			}
		}

		//������һ������
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

		//��ֵ����
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

		//��ɾ�Ĳ�
		void clear()
		{
			_finish = _start;
		}

		void pop_back()
		{
			//�ж��Ƿ�Ϊ��
			assert(!empty());
			--_finish;
		}
		/*friend ostream& operator>>(ostream& out, vector<T>& v);*/

		//����
		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			//����
			if (_finish == _end_of_storage)
			{
				//Ϊ�˷�ֹ���ݺ������ʧЧ����pos��ΪҰָ�룬��Ϊ�����ݺ�posָ�����Ȼ�Ǿɿռ��λ�ã����Ǿɿռ��Ѿ����ͷ���
				//���� �ʹ���һ��len����ʱ������¼��pos�����λ�ã����ݺ��ڼ������λ�ü���
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
		//ɾ��posλ�õ�Ԫ��
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
		iterator _start;//ָ��ͷ��Ԫ��
		iterator _finish;//ָ��β��Ԫ��
		iterator _end_of_storage;//ָ��ռ�ĩβ
		//ͨ��������ָ�����ģ���size��capacity�Ĺ���
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

	//���ֱ�����ʽ

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

	//string��int ��һ�� �ײ���ܵ����������Ҫ��const &

	for (const auto& v : v4)
	{
		cout << v << " ";
	}
	cout << endl;

	vector<int> v5(5, 1);
	//��ά����
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