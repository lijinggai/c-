#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<assert.h>
using namespace std;

//class Point
//{
//public:
// Point(int x = 0, int y = 0) 
//	 : _x(x), _y(y)
// {}
//private:
// int _x;
// int _y;
//};
//class A
//{
//public:
//	//explicit A(int a)
//	//	:_a(a)
//	//{}
//
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//int main()
//{
//	//���������캯����֧����ʽ����ת��
//	A aa(1);
//	A aa1 = 1;//��ʹ��1���죬�ٸ�ֵ
//	string s1("hello");
//	string s2{ "hello" };
//	vector<string> v1;
//	v1.push_back("hello");
//	v1.push_back(s1);
//	// C++11 
//	// ��������캯����֧����ʽ����ת��
//	Point p1 = { 1,2 };
//	Point p2{ 1,2 };
//
//	int b = 2;
//	int a = { 1 };
//	int b{ 3 };
//	int array1[5]{ 1,2,3 };
//	int array2[2]{ 0 };
//	return 0;
//}

//int main()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	vector<int> v2{ 1,2,3,4,5 };
//	pair<string, string> kv{"delete", "ɾ��"};
//	map<string, string> m1 = { {"insert","����"},{"sort","����"},kv,make_pair("hello","���") };
//	initializer_list<int> init = { 1,2,3,4 };
//	initializer_list<int>::iterator it = init.begin();
//	while (it != init.end())
//	{
//		v1.push_back(*it);
//		it++;
//	}
//	for (auto e : init)
//	{
//		v1.push_back(e);
//	}
//#include <initializer_list>
//	template<class T>
//	class Vector {
//	public:
//		// ... 
//		Vector(initializer_list<T> l) : _capacity(l.size()), _size(0)
//		{
//			_array = new T[_capacity];
//			for (auto e : l)
//				_array[_size++] = e;
//		}
//
//		Vector<T>& operator=(initializer_list<T> l) {
//			delete[] _array;
//			size_t i = 0;
//			for (auto e : l)
//				_array[i++] = e;
//			return *this;
//		}
//		// ...
//	private:
//		T* _array;
//		size_t _capacity;
//		size_t _size;
//	};
	//�Ƶ�����
	//const int x = 2;
	//decltype(x) y = 3;
//	// decltype��һ��ʹ�ó���
//	//decltype(it) copyIt = it;
//	auto copyIt = it;
//	vector<decltype(it)> v;
//	v.push_back(it);
//	return 0;
//}


// �����﷨
//int main()
//{
//	int a1[10];
//	array<int, 10> a2;
//	cout << sizeof(a2) << endl;
//
//	// 1��֧�ֵ����������ü���STL�����淨
//	// 2������Խ��ļ��
//	a1[14] = 0; // *(a1+14) = 0;  ���
//	a2[14] = 0; // a2.operator[](14) = 0; // �ؼ�
//
//
//	return 0;
//}

// ����ȡ��ַ���󣬾�����ֵ
//int main()
//{
//	int a = 10;
//	int& r1 = a;
//	int* p = &a;
//	int& r2 = *p;
//
//	const int b = 10;
//	const int& r3 = b;
//
//	return 0;
//}

// ����ȡ��ַ���󣬾�����ֵ
//int main()
//{
//	double x = 1.1, y = 2.2;
//
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	//cout << &fmin(x, y) << endl;
//
//	// ���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//
//	return 0;
//}

// ��������
// ��ֵ�����ܷ�������ֵ
// ��ֵ�����ܷ�������ֵ
//int main()
//{
//	// ���¼������ǳ�������ֵ
//	double x = 1.1, y = 2.2;
//	10;
//	x + y;
//	fmin(x, y);
//
//	// ���µ�p��b��c��*p������ֵ
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	// ��ֵ�����ܷ�������ֵ -- ����ֱ�����ã�����const ��ֵ���ÿ���������ֵ
//	// void push_back(const T& x)
//	const int& r1 = 10;
//	const double& r2 = x+y;
//	const double& r3 = fmin(x, y);
//
//	// ��ֵ�����ܷ�������ֵ -- ����ֱ�����ã����ǿ�����ֵ���ÿ�������move�Ժ���ֵ
//	int*&& rr1 = move(p);
//	int&& rr2 = move(*p);
//	int&& rr3 = move(b);
//	const int&& rr4 = move(c);
//
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	const double&& rr3 = x + y;
//
//	cout << &rr1 << endl;
//	cout << &rr2 << endl;
//	rr1 = 20;
//	rr2 = 30.33;
//	//rr3 = 1.1;
//
//	return 0;
//}



namespace LJ
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- ��Դת��" << endl;

			this->swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			//cout << "~string()" << endl;

			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string operator+(char ch)
		{
			string tmp(*this);
			push_back(ch);

			return tmp;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
}

// ����1
// ��ֵ���������������������Ľ����������
void func1(LJ::string s)
{}

void func2(const LJ::string& s)
{}

// ����2
// ��ֵ����������ֵ��ֻ�ܽ����������
// string& operator+=(char ch) �����
// string operator+(char ch)   û�н��

// ��ֵ���ã���ν��operator+��ֵ���ش��ڿ����������أ�
// C++11 ����ֵ��Ϊ������ֵ������ֵ
LJ::string func3()
{
	LJ::string str("hello world");
	//cin >> str;

	return str;
}

int main()
{
	LJ::string str("hello world");
	//func1(str);
	//func2(str);

	/*str += '!';
	str + '!';*/
	func3();

	return 0;
}