
#include<iostream>
using namespace std;
//����Ĭ�ϳ�Ա������
// ���캯��--��ʼ�����󲿷�ʱ����Ҫ�����Լ�д
// ��������--��������е���Դ
// ������������--������ʼ�������⹹�캯��   ��ǳ��������
// ��ֵ���������--Ҳ�ǿ�����Ϊ�����ǲ�һ�����ǣ����������Ǵ���һ������ʱ����ͬ��Ķ����ʼ���Ŀ���
// ���︴�ƿ����Ƕ����Ѿ������ˣ�������ʼ���������һ�������ƿ�������һ������
//���ǲ�д���������Զ����ɣ���Ȼ���Զ����ɣ����Ǵ��ʱ������Ҫ�����Լ�д�������ɵĲ�һ������
//Ĭ�Ϲ��캯����1.����������2.�޲εĹ��캯��3.ȫȱʡ�Ĺ��캯��
//�������������ǲ���Ҫд��������û����Դ����������Ĭ�����ɵľ͹���
//Ĭ�����ɵ���������������Ҳ����ʲô���飬release���Ż�����û��
//�ܽ᣺
//��������������������Ƶģ����ǲ�д���������Զ�����һ�����������Ͳ������Զ������ͻ�������Ĺ��������
//��������͸�ֵ��������������Ƶģ��������ͻ����ǳ�������Զ������ͻ�������ǵĿ�������͸�ֵ����
class Date
{
public:
	//Date()
	////{
	////	_year = 2022;
	////	_month = 9;
	////	_day = 12;
	////}
	Date(int year = 2022,int month = 9,int day = 13)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//Date(Date& d)//
	//{
	//	_year = d._year;
	//	this->_month = d._month;
	//	this->_day = d._day;
	//}
	//Ĭ�ϳ�Ա���������ǲ�д������Ҳ���Զ�����
	//������������������������ǳ��������ֵ����
	Date& operator=(Date& d)//��ֵ���������
	{
		if(this!=&d)
		{
			_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
			return *this;
		}
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class Stack
{
public:
	Stack(int capacity = 4)
	{
		if (capacity == 0)
		{
			_a = nullptr;
			_size = _capacity = 0;
		}
		else
		{
			_a = (int*)malloc(sizeof(capacity));
			_size = _capacity = capacity;
		}
	}
	~Stack()
	{
		free(_a);
		_size = _capacity = 0;
		_a = nullptr;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};
int main()
{
	Date d1(2021, 3, 12);
	Date d2(d1);
	Date d3;
	d3 = d1;
	d3.Print();
	return 0;
}

