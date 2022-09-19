#pragma once
#include <iostream>
#include <cassert>
using namespace std;

namespace lj
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
		void swap(string& s)
		{
			:: swap(_str, s._str);
			:: swap(_capacity, s._capacity);
			:: swap(_size, s._size);
		}
		string(const char* str="")//���캯��
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//capacityΪ������������\0��
			strcpy(_str, str);
		}
		~string()//��������
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		//string(const string& s)//�������캯��
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}
		//string& operator=(const string& s)//��ֵ���������
		//{
		//	if(_str!=s._str)
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}
		
		//�ִ�д��
		string(const string& s)//�������캯��
			:_str(nullptr)//���������һ��ʼ����ʼ��this,tmpָ������ռ䣬����������������
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			//swap(_str, tmp._str);
			//swap(_capacity, tmp._capacity);
			//swap(_size, tmp._size);

		}
		//s3=s1
		string& operator=(string s)//��ֵ���㷨����,��ֵ���Σ�������������
		{
			//swap(_str, s._str);
			//swap(_capacity, s._capacity);
			//swap(_size, s._size);
			return *this;
		}
		const char& operator[](size_t i)const//ֻ��
		{
			assert(i < _size);//��ֹԽ��
			return _str[i];
		}
		char& operator[](size_t i)//�ɶ���д
		{
			assert(i < _size);//��ֹԽ��
			return _str[i];
		}
		void reserve(size_t n)
		{
			if(n>_capacity)
			{
				char* tmp = new char[n + 1];//+1'\0'��Ҫ
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void resize(size_t n,char val='\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}

				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = val;
				}
				_str[n] = '\0';
				_size = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity + 1);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str, str);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		// s1 += "xxxxx"
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		size_t size()
		{
			return _size;
		}
		char* c_str()const
		{
			return _str;
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	};
}
void f(const string s)
{

}


void Test1()
{
	string s1("hello wrold");
	cout << s1.c_str() << endl;
	string s2(s1);
	string s3;
	s3 = s1;
}
void Test2()
{
	string s1("hello wrold");
	cout << s1[2] << endl;
	s1[0] = 'f';
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
}
void Test3()
{
	string s1("hello wrold");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//��Χfor���ɵ�����֧��
	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
}
void Test4()
{
	string s1("hello wrold");
	s1 += '*';
	for (auto ch : s1)
	{
		cout << ch << " ";

	}
	cout << endl;
	s1 += "abcde";
	for (auto ch : s1)
	{
		cout << ch << " ";

	}
	cout << endl;
	s1.resize(30, 'x');
	for (auto ch : s1)
	{
		cout << ch << " ";

	}
	cout << endl;
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}