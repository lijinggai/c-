#include <iostream>
#include <memory>
using namespace std;

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//
//	return a / b;
//}
//
//void func()
//{
//	int* p1 = new int;
//	int* p2 = nullptr, *p3 = nullptr;
//	try
//	{
//		p2 = new int;
//		p3 = new int;
//
//		cout << div() << endl; // �쳣��ȫ������
//	}
//	catch (...)
//	{
//
//	}
//
//	cout <<"delete:"<<p1 << endl;
//
//	delete p1;
//	delete p2;
//	delete p3;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// RAII
// ��������ָ��һ��
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}

	// ��ָ��һ��ʹ��
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//
//	return a / b;
//}
//
//void func()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//	SmartPtr<int> sp3(new int);
//
//	*sp1 = 10;
//	cout << *sp1 << endl;
//	(*sp1)++;
//	(*sp1)++;
//	cout << *sp1 << endl;
//
//	cout << div() << endl;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// ��ν���أ�
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(sp1);
//
//
//	return 0;
//}
//auto_ptr
namespace LDJ
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			// ����Ȩת��
			sp._ptr = nullptr;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		// ��ָ��һ��ʹ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}

// ���ۣ�auto_ptr��һ��ʧ����ƣ��ܶ๫˾��ȷҪ����ʹ��auto_ptr
//int main()
//{
//	std::auto_ptr<int> sp1(new int);
//	std::auto_ptr<int> sp2(sp1); // ����Ȩת��
//
//	// sp1����
//	*sp2 = 10;
//	cout << *sp2 << endl;
//	cout << *sp1 << endl;
//
//	return 0;
//}


// unique_ptr/scoped_ptr
// ԭ���򵥴ֱ� -- ������
namespace LDJ
{
	template<class T>
	class default_delete
	{
	public:
		void operator()(const T* ptr)
		{
			cout << "delete:" << ptr << endl;
			delete ptr;
		}
	};

	// �ͷŷ�ʽ��Dɾ��������
	template<class T, class D = default_delete<T>>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				//cout << "delete:" << _ptr << endl;
				//delete _ptr;
				D del;
				del(_ptr);
			}
		}

		// ��ָ��һ��ʹ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		unique_ptr(const unique_ptr<T>& sp) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;

	private:
		T* _ptr;
	};
}

namespace LDJ
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
			, _pmtx(new mutex)
		{}
		void AddRef()
		{
			return ++ * (_pRefCount);
		}
		void Release()
		{

			if (--(*_pRefCount) == 0 && _ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pRefCount;

			}

		}
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pRefCount(sp._pRefCount)
			, _pmtx(sp._pmtx)
		{
			AddRef();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp)
			if (this->_pRefCount != sp._pRefCount)
			{
				Release();

				_ptr = sp._ptr;
				_pRefCount = sp._pRefCount;
				_pmtx = sp._pmtx;
				AddRef();
				return *this;
			}
		}

		int use_count()
		{
			return *_pRefCount;
		}

		~shared_ptr()
		{
			Release();
		}

		// ��ָ��һ��ʹ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pRefCount;
	};
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}


	private:
		T* _ptr;
	};
}

	//struct ListNode
//{
//	int _val;
//	std::shared_ptr<ListNode> _next;
//	std::shared_ptr<ListNode> _prev;
//	//std::weak_ptr<ListNode> _next;
//	//std::weak_ptr<ListNode> _prev;
//
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//
//int main()
//{
//	std::shared_ptr<ListNode> n1(new ListNode);
//	std::shared_ptr<ListNode> n2(new ListNode);
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	// ѭ������
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	return 0;
//}
////////////////////////////////////////////////////////////////////
//// ����ɾ���� ���Ի���������ʵ��ʹ���м�ֵ
//// Ĭ�����������ָ��ײ㶼��delete��Դ
//// ��ô��������Դ����new�������أ����磺new[]��malloc��fopen
//// ����ɾ���� -- �ɵ��ö���
//
//template<class T>
//struct DeleteArray
//{
//	void operator()(const T* ptr)
//	{
//		cout << "delete[]:" << ptr << endl;
//		delete[] ptr;
//	}
//};
//
////int main()
////{
////	std::unique_ptr<A> sp1(new A);
////	std::unique_ptr<A, DeleteArray<A>> sp2(new A[10]);
////
////	return 0;
////}
//
//struct DeleteFile
//{
//	void operator()(FILE* ptr)
//	{
//		cout << "fclose:" << ptr << endl;
//		fclose(ptr);
//	}
//};
//
//int main()
//{
//	// ɾ��������ģ������� -- ����
//	bit::unique_ptr<A> up1(new A);
//	bit::unique_ptr<A, DeleteArray<A>> up2(new A[10]);
//	bit::unique_ptr<FILE, DeleteFile> up3(fopen("test.txt", "w"));
//
//	// ɾ�����ڹ��캯���Ĳ����� -- ����
//	std::shared_ptr<A> sp1(new A);
//	std::shared_ptr<A> sp2(new A[10], DeleteArray<A>());
//	std::shared_ptr<FILE> sp3(fopen("test.txt", "w"), DeleteFile());
//
//	std::shared_ptr<A> sp4(new A[10], [](A* p) {delete[] p; });
//	std::shared_ptr<FILE> sp5(fopen("test.txt", "w"), [](FILE* p) {fclose(p); });
//
//	return 0;
//}
