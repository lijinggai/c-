#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

void test_list1()
{
	//list<int> lt;
	//lt.push_back(1);
	//lt.push_back(2);
	//lt.push_back(3);
	//lt.push_back(4);
	////������ʽ1
	//list<int>::iterator it = lt.begin();
	//while (it != lt.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;
	////������ʽ2
	//for (auto e : lt)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	int a[] = { 13,2,32,41 };
	list<int> lt1(a, a + 4);
	//ԭ��ָ����Ե�����Ȼ�ĵ�����ʹ�ã���ʵvector/string�ĵĵ�����Ҳ��ԭ��ָ��
	list<int>::iterator it = lt1.begin();//InputIterator first, InputIterator last
	while (it != lt1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<int> v(a, a + 4);
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
}
void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	if (pos == lt.end())
	{
		exit(-1);
		cout << "find fail";
	}
	//list��Ϊ�ײ�ṹinsert���ᵼ��pos������ʧЧ
	lt.insert(pos, 30);
	//list��Ϊ�ײ�ṹerase�ᵼ��pos������ʧЧ��Ұָ��
	lt.erase(pos);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//test_list1();
	test_list2();
	return 0;
}