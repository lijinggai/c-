#include <iostream>
using namespace std;
//class B
//{
//public:
//	B(int x = 0)
//	{
//		_x = x;
//	}
//private:
//	int _x;
//};
//class A
//{
//public:
//	A(int a=1,int* p=nullptr)
//		:_a(a)
//		,_p(p)
//		{
//		}
//private:
//	//����ȱʡֵ
//	int _a=0;
//	int* _p=nullptr;
//	int* arr = (int*)malloc(sizeof(int));
//	B _b=6;
//};
//int main()
//{
//	A a;
//	return 0;
//}
//int main()
//{
//	//new��delete��malloc��free���������������û�в��ֻ���÷���ͬ
//	//����10int���͵�����
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];//����Ҫǿת��new�ǲ�����
//	free(p1);
//	delete[] p2;
//
//	//���뵥��int����
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//}
struct ListNode
{
public:
	ListNode(int val=0)
	:next(nullptr)
	,prev(nullptr)
	,val(val)
	{}
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
private:
	ListNode* next;
	ListNode* prev;
	int val;
};
int main()
{
	//c  mallocֻ�ǿ��ռ䣬free�ͷſռ�
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	free(n1);

	//cpp   new����Զ������ͣ����ռ�+���캯����ʼ��
	//   delete����Զ������ͣ���������+�ͷſռ�
	ListNode* n2 = new ListNode;
	delete n2;
	ListNode* n3 = new ListNode[4]{1,2,3,4};
	delete[] n3;
	//delete n3;//��ƥ������

	//int* p1 = new int(3);
	//int* p2 = new int[3]{1,2,3};
	return 0;
}