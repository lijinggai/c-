#include <iostream>
using namespace std;

////������--�޷�ʵ��������
////1�����Ը��õ�ȥ��ʾ��ʵ�����У�û��ʵ�������Ӧ�ĳ�������  ���磺ֲ��ˡ�����
////2�����ֽӿڼ̳У�ǿ������ȥ��д�麯��(����д������Ҳ�ǳ�����)
//// Ҫע���override���֣�override��������麯���Ƿ������д��
//class Person
//{
//public:
//	//���麯��
//	virtual void jog() = 0;
//};
//class Student:public Person
//{
//public:
//	virtual void jog()
//	{
//		cout << "void jog" << endl;
//	}
//};
//int main()
//{
//	//Person p;
//	Student s;
//	Person* ps = &s;
//	ps->jog();
//	return 0;
//}

//// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch = '\0';
//};
//
//int main()
//{
//	Base bs;
//	cout << sizeof(Base) << endl;
//	return 0;
//}