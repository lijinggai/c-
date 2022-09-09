#include <iostream>
using namespace std;

//const int* p1;//����*p1
//int const* p2;//����*p2
//int* const p3;//����p3
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	void operator>>(ostream& out)
	{
		out << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator==(Date& cmp)const//comst���γ�Ա����
	{
		return _year == cmp._year &&
			_month == cmp._month &&
			_day == cmp._day;
	}
	Date operator&()
	{
		return *this;
		//return nullptr;

	}
	const Date operator&()const
	{
		return *this;
		//return nullptr;
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
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in>>d._year>>d._month>>d._day;
	return in;
}

int main()
{
	return 0;
}