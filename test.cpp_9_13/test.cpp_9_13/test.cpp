#include <iostream>
using namespace std;
//struct ListNode
//{
//public:
//	ListNode(int val=0)
//	:_next(nullptr)
//	,_prev(nullptr)
//	,_val(val)
//	{}
//private:
//	ListNode* _next;
//	ListNode* _prev;
//	int _val=5;
//};
//int main()
//{
//	//operator new�ú���ʵ��ͨ��malloc����ռ�,��malloc����ɹ�ʱֱ�ӷ��أ�����ʧ�ܣ�����ִ�пռ䲻��Ӧ�Դ�ʩ��
//	//����û���Ӧ�Դ�ʩ�ˣ���������룬�������쳣
//	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	free(p1);
//
//	struct ListNode* p2 = (struct ListNode*)operator new(sizeof(struct ListNode));
//	operator delete(p2);
//	return 0;
//}

//void Swap(int& x1, int& x2)//���2�������㣬���ȵ�������д��
//{
//	int tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//template <class T>//����ģ�����T������class����typename
////���ͱ��--ģ��
////����ģ��
////template <typename T>
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	//��������ͨ��ʵ�����βε�����t�Ǳ�Ϊint��double
//	//���ַ�ʽ����ʽʵ����
//
//	//Add<int>(a, c);
//	//���ñ������������ͣ���ʾָ������
//	//���ַ�ʽ������ʾʵ����
//	return 0;
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
////ģ����ã����ֳ�ƥ�亯�������Բ�ʵ����ģ��
////�и�ƥ��ģ�����ƥ����������ʵ�
//int main()
//{
//	int a = 1;
//	int b = 2;
//	double c = 2.2;
//	Add(a, b);
//	Add(a, c);
//	return 0;
//}

// ��ģ��
namespace Lj
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_a(nullptr)
			, _size(0)
			, _capacity(0)
		{}

		// ���������operator= �����漰��ǳ�������⣬��ͦ���ӣ���������ٽ�

		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}

		void push_back(const T& x)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T) * _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}

			_a[_size] = x;
			++_size;
		}

		// ��+д
		T& operator[](size_t pos);
		size_t size();
	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};

	// ģ�岻֧�ַ�����룬Ҳ����������.h ,������.cpp��ԭ������ٽ�
	// ������Ƕ�����һ���ļ� xxx.h  xxx.hpp
	// �������涨��
	template<class T>
	T& vector<T>::operator[](size_t pos)
	{
		assert(pos < _size);

		return _a[pos];
	}

	template<class T>
	size_t vector<T>::size()
	{
		return _size;
	}
}

int main()
{
	zj::vector<int> v1;		// int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	// v1.operator[](3);
	//cout << v1[3] << endl;
	//cout << v1[5] << endl;
	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] *= 2;
	}
	cout << endl;

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;


	zj::vector<double> v2;   // double
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);
	v2.push_back(4.4);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	return 0;
}