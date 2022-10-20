#include <iostream>
#include<string>
#include <set>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);

	// 1������+ȥ��
	// ������ʽ1��
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// �����޸��Ѿ������ֵ
		// *it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// ������ʽ2��
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ��鵥��ƴд�Ƿ���ȷ
	// ˼·���ʿ��е��ʶ��Ž�set�Ķ����У���ÿ��д�����ĵ���
	// ȥset�в�һ�£��ڲ��ڣ��ھ�����ȷ�ģ����ھ��Ǵ����ƴд
	set<string> strSet;
	strSet.insert("sort");
	strSet.insert("left");
	strSet.insert("right");
	strSet.insert("insert");

	for (const auto& e : strSet)
	{
		cout << e << " ";
	}
	cout << endl;

	// ...
	set<string>::iterator ret = strSet.find("sort");
	if (ret != strSet.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

	ret = strSet.find("map");
	if (ret != strSet.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

void test_set2()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);

	// �Ȳ��ң��ҵ�����ɾ��û�ҵ���Ҳȥɾ�ᱨ��
	auto pos = s.find(4);
	if (pos != s.end())
	{
		s.erase(pos);
	}

	pos = s.find(40);
	//s.erase(pos);
	if (pos != s.end())
	{
		s.erase(pos);
	}

	// �ھ�ɾ�������ھͲ�����Ҳ����
	s.erase(3);
	s.erase(30);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	// multiset�����ֵ���࣬ʹ�÷���������setһ��
	// �����漸���ط���һЩ����
	multiset<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(3);

	// ����
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// find���ҵ�val�ж����ʱ����ô���ҵ���������ĵ�һ��
	multiset<int>::iterator pos = s.find(3);
	while (*pos == 3)
	{
		cout << *pos << endl;
		++pos;
	}
	cout << s.count(3) << endl;
	cout << s.count(4) << endl;

	s.erase(3);
	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{

	return 0;
}