#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 2);
	//����,�������죬��ֵ������Date���Բ�д
	void Print();
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	bool operator<(const Date& cmp);
	int operator-(const Date& num);
	Date operator++(int);
	Date& operator++();

private:
	int _year;
	int _month;
	int _day;

};