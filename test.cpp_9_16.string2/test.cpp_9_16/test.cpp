#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	string s1("hello wrold");
//	cout << s1 << endl;
//	s1.clear();
//	cout << s1 << endl;
//	return 0;
//}
 

//int main()
//{
//	string s2("hello wrold");
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl;
//	cout << s2 << endl;
//	
//	//û��posĬ��'\0'
//	s2.resize(20);//�ı�size�������������������
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl;
//	cout << s2 << endl;
//
//	s2.resize(5,'x');//��С������ı�������Ҳ����ѡ�x������
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl;
//	cout << s2 << endl;
//
//	string s3("hello world");
//	s3.reserve(50);
//	cout << "size:" << s3.size() << endl;
//	cout << "capacity:" << s3.capacity() << endl;
//	cout << s3 << endl;
//
//	string s4;
//	s4.reserve(127);//�����ݽ��
//	//s4.resize(127);//�ı�������ͬ��Ҳ�ı�size���������ǻ�����
//	size_t chOld = s4.capacity();
//	for (int ch = 0; ch < 127; ch++)
//	{
//		//�������Ч�ʵ�
//		if (chOld != s4.capacity())
//		{
//			cout << "����" << chOld << "->" << s4.capacity()<<endl;
//			chOld = s4.capacity();
//		}
//		s4 += ch;
//	}
//	cout << s4 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;//����operator(cout,s1)
//	cout << s1.c_str() << endl;//����operator<<(cout,char*)
//	s1.resize(30);
//	s1 += "!!!";
//	cout << s1 << endl;//����operator(cout,s1)
//	cout << s1.c_str() << endl;//����operator<<(cout,char*)
//
//	cout << s1.size() << endl;
//	cout << strlen(s1.c_str()) << endl;//�������һЩC���Ժ���ʹ��
//	return 0;
//}


//int main()
//{
//	string s1("test.cpp");
//	size_t pos = s1.find('.');
//	if (pos != -1)
//	{
//		//string suff(s1, pos);
//		//cout << suff << endl;
//		string suff = s1.substr(pos);
//		cout << suff << endl;
//	}
//
//	return 0;
//}

string GetDomain(const string& url)
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		size_t start = pos + 3;
		size_t end = url.find('/', start);
		if (end != string::npos)
		{
			return url.substr(start, end - start);
		}
		else
		{
			return string();
		}
	}
	else
	{
		return string();
	}
}

string GetProtocol(const string& url)
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		return url.substr(0, pos - 0);
	}
	else
	{
		//string s;
		//return s;
		return string();
	}
}
int main()
{
		// Ҫ��дһ������ֱ�ȡ��������Э����
	string url1 = "http://www.cplusplus.com/reference/string/string/rfind/";
	string url2 = "https://tower.im/users/sign_in";
	string url3 = "tower.im/users/sign_in";

	cout << GetDomain(url1) << endl;
	cout << GetProtocol(url1) << endl;

	cout << GetDomain(url2) << endl;
	cout << GetProtocol(url2) << endl;

	//cout << GetProtocol(url3) << endl;
	return 0;
}