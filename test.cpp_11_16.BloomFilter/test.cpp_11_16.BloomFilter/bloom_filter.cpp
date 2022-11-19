#pragma once
#include <bitset>
#include <string>
#include <time.h>
#include<iostream>
using namespace std;

//��ͬ���ַ����õõ����β�һ��
struct BKDRHash
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};

struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

template<size_t N,
	size_t X = 8,
	class K = string,
	class HashFunc1 = BKDRHash,
	class HashFunc2 = APHash,
	class HashFunc3 = DJBHash>
//x=8,char��8������λ��N��char������
class BloomFilter
{
public:
	//ӳ��3��λ��
	void Set(const K& key)
	{
		size_t len = X * N;
		size_t index1 = HashFunc1()(key) % len;
		size_t index2 = HashFunc2()(key) % len;
		size_t index3 = HashFunc3()(key) % len;

		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}
	//ӳ��3��λ�ã���һ��λ�ò���˵���Ͳ��ڣ��������Ҳ�п���������
	bool Test(const K& key)
	{
		size_t len = X * N;
		size_t index1 = HashFunc1()(key) % len;
		if (_bs.test(index1) == false)
			return false;

		size_t index2 = HashFunc2()(key) % len;
		if (_bs.test(index2) == false)
			return false;

		size_t index3 = HashFunc3()(key) % len;

		if (_bs.test(index3) == false)
			return false;

		return true;  // �������е�
	}

	// ��֧��ɾ����ɾ�����ܻ�Ӱ������ֵ��
	void Reset(const K& key);
private:
	bitset<X* N> _bs;
};
