#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	//ascall����
//	char ah1 = 'a';
//	char ah2 = 97;
//	cout << ah1 << endl;
//	cout << ah1 << endl;
//	char str[] = "�й�";
//	str[3] = -6;
//
//	cout << str << endl;
//	return 0;
//}

int main()
{
	string s1;
	string s2("hello wrold");
	string s3(s2);
	//3�ֱ�����ʽ
	//1.�±�+[]
	for (size_t i = 0; i < s2.size(); ++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	//2.������
	//[begin(),end())end()���صĲ������һ������λ�õĵ����������ص������һ��λ����һ��λ��
	//ҲҪע����ǣ�c++�з��Ǹ�������һ�㶼�Ǹ���{)����ҿ�������
	//������������ָ��һ���Ķ���
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//const����ֻ��
	string s4 = "123456";
	//class Solution {
	//public:
	//	int firstUniqChar(const string s)
	//	{
	//		int count[26] = { 0 };
	//		string::const_iterator it = s.begin();
	//		while(it!=s.end())
	//		{
	//			count[*it - 'a']++;
	//		}
	//		for (int i = 0; i < s.size(); i++)
	//		{
	//			if (count[s[i] - 'a'] == 1)
	//				return i;
	//		}
	//		return -1;
	//	}
	//};
	//���������
	string::reverse_iterator rit = s4.rbegin();
	while (rit != s4.rend())
	{
		*rit += 1;
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	//���������壺��string��vector֧��[]����������list��map�ȵ�������֧��{
	//���Ǿ�Ҫ�õ��������������Ե�������һ��ͳһʹ�õķ�ʽ

	//c++11,3.��Χfor
	//����ȡ������ֵ����e���Զ��жϽ���
	for (auto e : s4)
	{
		//e+=1;//��Ҫ����
		cout << e << " ";
	}
	cout << endl;
	return 0;
}