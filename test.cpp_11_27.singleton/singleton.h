#pragma once
#include<iostream>
using namespace std;

extern int Count ;
void func();

////����ģʽ
//class GetInformation
//{
//public:
//	static GetInformation& GetInstance()
//	{
//		return instance;
//	}
//	void Add(const int n)
//	{
//		instance._count += n;
//	}
//	int GetConut()
//	{
//		return instance._count;
//	}
//	GetInformation(const GetInformation& instance)=delete;
//private:
//	GetInformation(int n=0)
//		:_count(n)
//	{}
//	int _count;
//	static GetInformation instance;//����
//};


//����ģʽ
class GetInformation
{
public:
	static GetInformation& GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GetInformation;
		}
		return *instance;
	}
	//static GetInformation& GetInformation()
	//{
	//	// C++98 �ж��̵߳���ʱ��static sInst�������ʼ�������ܱ�֤���̰߳�ȫ
	//	// C++11 �Ż���������⣬C++11��static sInst�������ʼ�����̰߳�ȫ��
	//	static GetInformation instance;

	//	return instance;
	//}
	void Add(const int n)
	{
		instance->_count += n;
	}
	int GetConut()
	{
		return instance->_count;
	}
	GetInformation(const GetInformation& instance) = delete;
	GetInformation(int n = 0)
		:_count(n)
	{}
	// ʵ��һ����Ƕ���������� 
	// һ�������ĵ������󣬲���Ҫ���գ���Ϊ����������������Դ���ỹ��ϵͳ���������ֻ��һ��ϵͳ�Զ�����Ҳûʲô����
	// ����������ڵ��������ͷ�����ʱ����һЩҪ��ɵĶ���������Ҫ��¼��־�ȵȡ���ô���Կ��Ǹ�һ����������Ļ��������ȥ����������
	class CGarbo
	{
		~CGarbo()
		{
			if (instance != nullptr)
			{
				delete instance;
			}
		}
	private:
	};
private:
	static CGarbo _CGarbo;

	int _count;
	static GetInformation* instance;//����
};
