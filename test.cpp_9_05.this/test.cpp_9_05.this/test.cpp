
#include<iostream>
using namespace std;
//class Date{
//public:
//	void Init(int year, int month, int day)
//	//������������һ��������thisָ�룬void Init(Date* this(����),int year, int month, int day)
//	//1.thisָ���������ģ��Ǳ������ڱ���׶μӵģ����ǲ�����ʾ�ڵ��ú��ں��������
//	//2.�����ڳ�Ա������
//	//thisָ�����ջ��
//	{
//		this->_year = year;
//		this->_month = month;
//		_day = day;
//	}
//
//private:
//	//
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	cout << "d1:" << &d1 << endl;
//	d1.Init(2022, 9, 5);
//	Date d2;
//	d2.Init(2022, 9, 17);
//	cout << "d2:" << &d2 << endl;
//	return 0;
//}

class A{
public:
	void Print()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "show" << endl;
	}

private:
	int _a;
};
int main()
{
	A* pa = nullptr;
	//pa->Print();
	//pa->Show();
	return 0;
}