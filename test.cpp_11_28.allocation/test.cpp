#include<iostream>
using namespace std;

//volatile int a = 0;//����������д��
//int main()
//{
//	//int i = 12;
//	//int* p = &i;
//	//// ��ʾ��ǿ������ת��
//	//int address = (int)p;
//	//printf("%x, %d\n", p, address);
//
//
//	////c++
//	//double a = 10.12;
//	//double b = 20.12;
//	//int c = static_cast<int>(a+b);//������͵���ʾ����ת��
//	//cout << c << endl;
//	//printf("%d\n", c);
//
//
//	//int d = 0;
//	//int* p = &d;
//	//int address = reinterpret_cast<int>(p);//��������͵���ʾ����ת��
//	//printf("%x, %d\n", p, address);
//
//
//	//const int a = 5;//�Ż�������constֱ��ȡ��������ȥʹ�õ�ַȡֵ
//	volatile const int a = 5;//��ֹ�������Ż�volatile
//	int* p = const_cast<int*>(&a);
//	*p = 10;
//	cout << a << endl;
//	cout << *p << endl;
//
//	return 0;
//}


//class A
//{
//	virtual void f() {}
//public:
//};
//
//class B : public A
//{
//public:
//	int _b = 0;
//};
//
//// 1��paָ�������
//// 2��paָ���������
//void func(A* pa)
//{
//	// ���pa��ָ���������ô�����κδ���
//	// ���pa��ָ�����������ô��ת�����࣬���������������_b��Ա
//	// dynamic_cast--���paָ��ĸ��������ô��ת�����ɹ�������nullptr
//	//               ���paָ������������ô��ת���ɹ������ض���ָ��
//	B* pb1 = dynamic_cast<B*>(pa);
//	if (pb1 == nullptr)
//	{
//		cout << "ת��ʧ��" << endl;
//	}
//	else
//	{
//		cout << "pb1:" << pb1 << endl;
//		pb1->_b++;
//	}
//
//	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//
//int main()
//{
//	A aa;
//	B bb;
//	func(&aa);
//	func(&bb);
//
//	//aa = bb;
//	//bb = reinterpret_cast<B>(aa); // ������
//}