#include <iostream>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;
//class Date
//{
//public:
//	friend ostream& operator<<(ostream& out, Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//
//	Date(int year=2022, int month=2, int day=2)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& out,Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;//Ϊʲô�з���ֵ��������������
//}
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day ;
//	return in;//������������
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d;
//	return 0;
//}
class A
{
public:
	A(int a)
	{
		cout << "A" << endl;
		_a = a;
	}
private:
	int _a;

};
class Date
{
public:
	//�������ɣ�һ������ĳ�Ա�����ڳ�ʼ���б���
	//����������ǳ�ʼ���б�ͺ������ڳ�ʼ����ͬ�ĵط���Ҳ������ֵ������
	Date(int year = 2022, int month = 2, int day = 2)
		//�����ֱ����ڳ�ʼ���б��ʼ��
		:_year(year)
		, _c(year)//���ó�Ա����
		, _n(10)//const��Ա����
		, _a(20)//�Զ������ͳ�Ա����û��Ĭ�Ϲ��캯����
	{
		_year = year;//�����ṹ���ڳ�ʼ��
		_month = month;
		_day = day;
		//�����ں������ڳ�ʼ��������ʹ�ó�ʼ���б��ʼ��
		_c = year;
		_n = 10;
		/*_a = 10;*/
	}


private:
	//��Ա��������
	int _year;
	int _month;
	int _day;
	//�����ڶ���ʱ���ʼ��
	const int _n;
	int& _c;
	A _a;
};
int main()
{
	Date d1;
	return 0;
}