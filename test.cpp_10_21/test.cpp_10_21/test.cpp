void test_map1()
{
	map<int, double> m;
	//����pair�Ĺ��캯��������һ����������������
	m.insert(pair<int, double>(1, 1.2));
	m.insert(pair<int, double>(3, 3.2));
	m.insert(pair<int, double>(2, 2.2));

	//���ú���ģ�壬�������
	//�ô�������Ҫ����pair��ģ��������ñ��������ݣ�д����������
	m.insert(make_pair(4, 4.2));
	map<int, double>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << *it << endl;
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	// ͨ��typedef ������
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;

	DICT dict;
	dict.insert(DICT_KV("insert", "����"));
	dict.insert(std::make_pair("sort", "����"));
	dict.insert(std::make_pair("left", "���"));

	DICT_ITER dit = dict.begin();
	//auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}
void test_map2()
{
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;

	DICT dict;
	dict.insert(DICT_KV("insert", "����"));
	dict.insert(DICT_KV("sort", "����"));
	dict.insert(DICT_KV("left", "���"));

	DICT_ITER dit = dict.begin();
	while (dit != dict.end())
	{
		dit->second.insert(0, "{");
		dit->second += "}";

		++dit;
	}
	cout << endl;

	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;

	// �޸�map��value����
	auto ret = dict.find("left");
	if (ret != dict.end())
	{
		//ret->second.insert(ret->second.size() - 1, "��ʣ��");
		// �ɶ����Ż�����
		string& str = ret->second;
		str.insert(str.size() - 1, "��ʣ��");
	}

	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}
void test_map3()
{
	//ͳ��
	string arr[] = { "����","����", "����", "����", "����", "����","����","ƹ����","����","ƹ����","ƹ����", };
	map<string, int> countMap;
	//���ã��������
	//for (const auto& str : arr)
	//{
	//	map<string, int>::iterator it = countMap.find(str);
	//	//��map��û���ҵ����룬�ҵ�++
	//	if (it != countMap.end())
	//	{
	//		it->second++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//}
	//for (const auto& e : countMap)
	//{
	//	cout << e.first << ":" << e.second<<endl;
	//}
	//2
	//for (const auto& str : arr)
	//{
	//	//�Ȳ��룬���str�Ѿ���map�У�insert��Ż�str���ڽڵ�ĵ���������++��
	//	pair<map<string,int>::iterator, bool> it = countMap.insert(make_pair(str,1));
	//	if (it.second ==false )
	//	{
	//		it.first->second++;
	//	}
	//}
	//3
	for (const auto& str : arr)
	{
		countMap[str]++;
	}
	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	map<string, string> dict;
	dict.insert(make_pair("right", "�ұ�"));
	dict["key"] = "�ؼ�";//����+�޸�
	dict["insert"];//����
	dict["insert"] = "����";//�޸�
	dict["right"] = "�ұߣ���ȷ";//�޸�
}
struct compare
{
	bool operator()(map<string, int>::iterator x, map<string, int>::iterator y)
	{
		return x->second < y->second;
	}
};
void test_map4()
{
	string arr[] = { "����","����", "����", "����", "����", "����","����","ƹ����","����","ƹ����","ƹ����", };
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}
	vector<map<string, int>::iterator> v;
	map<string, int>::iterator countMapit = countMap.begin();
	while (countMapit != countMap.end())
	{
		v.push_back(countMapit);
		++countMapit;
	}
	sort(v.begin(), v.end(), compare());
	// ����map����  -- ����pair����
//map<int, string> sortMap;
	map<int, string, greater<int>> sortMap;
	for (auto e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}
	// ����set����  --������pair����
	set<map<string, int>::iterator, compare> sortSet;
	countMapit = countMap.begin();
	while (countMapit != countMap.end())
	{
		sortSet.insert(countMapit);
		++countMapit;
	}
}
