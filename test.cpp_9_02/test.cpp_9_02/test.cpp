#include<iostream>

#define ADD(x,y) ((x)+(y)//�궨�庯��
void Swap(int& ca, int& cb)
{
	int tmp = ca;
	ca = cb;
	cb = tmp;
}
int main()
{
	const int a = 10;
	//int& ra = a;//->ra����a����Ȩ�޷Ŵ����Բ���

	int b = 0;
	int& rb = b;
	const int& rrb = b;//->rrb����b����Ȩ����С�����Կ���

	int c = 10;
	double d = 1.11;
	//double& d = c;//Ϊʲô��������
	const double& d = c;//��Ϊ��ʽ����ת����c������double����ʱ�������г��ԣ����Կ��ԣ�
	Swap(c, b);

	//��������
	//c����Ϊ��С�������⽨��ջ֡������-������˺꺯��֧�֣�Ԥ����չ��
	//�Ѿ��������Ϊʲô��Ҫ�ṩinline���������꺯����ȱ�㣩�����⿼��
	//1.�����Ե��ԣ�2.�꺯���﷨���ӣ����׳���д��3.û�����͵İ�ȫ��飨add��int��int�������double������������û�а�ȫ��飩
	return 0;
}