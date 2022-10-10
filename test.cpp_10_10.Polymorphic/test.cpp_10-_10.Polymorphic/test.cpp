#include<iostream>
using namespace std;

//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	//��̬��̬������ʱ����������
//	swap(a, b);
//	swap(c,d);
//	return 0;
//}

class Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};

class Student : public Person
{
public:
	// ������麯����д�˸�����麯��
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};

class Soldier : public Person
{
public:
	// ������麯����д�˸�����麯��
	virtual void BuyTicket() { cout << "����-��Ʊ" << endl; }
};

void f(Person& p)
{
	// ����ͬ���͵Ķ��󣬵��õ��ǲ�ͬ�ĺ�����ʵ���˵��õĶ�����̬
	p.BuyTicket();
}

void f(Person* p)
{
	// ����ͬ���͵Ķ��󣬵��õ��ǲ�ͬ�ĺ�����ʵ���˵��õĶ�����̬
	p->BuyTicket();
}

int main()
{
	Person p; // ��ͨ��
	Student st; // ѧ��
	Soldier so; // ����

	f(p);
	f(st);
	f(so);
	cout << endl;

	f(&p);
	f(&st);
	f(&so);

	return 0;
}