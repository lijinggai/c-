#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//	string _addr;
//protected:
//	string _name; // ����
//private:
//	int _age; // ����
//};
//
//class Student : public Person
//{
//public:
//	void funcprotected()
//	{
//		cout << _name << endl;
//	}
//	void func()
//	{
//		//����̳�������˽�г�Ա���ɼ�:�ڴ��ϣ�����������������Ա�������﷨�涨�����ǲ���ȥ����
//		cout << _age << endl;
//	}
//protected:
//	int _stunum; // ѧ��
//};
//int main()
//{
//	Student s;
//	s._addr;
//	s.funcprotected();
//	s.func();
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//	string _name; // ����
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _stunum; // ѧ��
//};
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "����";
//	s._age = 20;
//	s._stunum = 100234;
//
//	p = s;//��<-�ӣ���Ƭ/�и�
//	Person* ptr = &s;//ָ��ָ���������ptrֻ�ܷ��ʼ̳еĸ����Ա
//	Person& ref = s;//��������а������ಿ�ֳ�Ա�ı���
//}

////Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ��ݺ�:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//int main()
//{
//	Student s;
//	s.Print();
//}

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//}

//class Person
//{
//public:
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//
//	~Person() // -> ��Ϊ�����̬��һЩԭ���κ����������������ᱻͳһ�����destructor()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int id)
//		: Person(name)
//		,_id(id)
//	{
//		// ���ø��๹�캯����ʼ���̳еĸ��ಿ��
//		// �ٳ�ʼ���Լ��ĳ�Ա
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)  // ->s���ݸ�Person& s ��һ����Ƭ��Ϊ
//		, _id(s._id)
//	{
//		// ���ƹ��캯��
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		// ͬ��
//		if (this != &s)
//		{
//			// С������������
//			Person::operator=(s);
//			_id = s._id;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	~Student() // ��������Ϊ��������������͸��������������������
//	{
//		//Person::~Person(); // ������������ã���Ҫָ�������
//
//		// �����Լ���
//		// delete ptr;
//
//		cout << "~Student()"<<endl;
//		// Ϊ�˱�֤����ʱ�����������ٸ��ĺ���ȳ���˳������
//		// ��������������ɺ󣬻��Զ�ȥ���ø������������
//	}
//private:
//	int _id;
//};
//int main()
//{
//	Student s1("����", 10);
//	Student s2(s1);
//	Student s3("����",30);
//	s3 = s2;
//}


class Person
{
public:
 Person() { ++_count; }
protected:
 string _name; // ����
public:
 static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}
