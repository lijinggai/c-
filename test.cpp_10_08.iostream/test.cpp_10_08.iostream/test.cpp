#pragma once
#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

//int main()
//{
	//// ���飺
	//// 1��C++����ȥ��cin��cout��������������
	//// 2����cout��cin������ĵط�����ȥ��scanf��printf
	//double a = 1.0 / 3.0;
	//printf("%.3f\n", a);
	//cout << setprecision(4) << a << endl;
	
	//string str;
	//cin >> str;
	//cout << str<<endl;
	//cin >> str;
	//cout << str<<endl;
	//getline(cin,str);//��ȡ�ַ���ֱ������
	//cout << str<<endl;

	//��Щoj��Ҫ������ԣ�Ҫ��������
	// ctrl+c����
	//C++
	//string str;
	//while (cin >> str)
	//{
	//	cout << str << endl;
	//	//...
	//}
	////C����
	//char buf[100];
	//while(scanf("%s", buf) != EOF)
	//{
	//	printf("%s\n", buf);
	//	//...
	//}
	//return 0;
//}

//struct ServerInfo
//{
//	char _ip[20];
//	int  _port;
//};
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* filename)
//		:_filename(filename)
//	{}
//
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_filename);
//		ifs.read((char*)&info, sizeof(info));
//	}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_filename);
//		ofs.write((char*)&info, sizeof(info));
//	}
//
//	void WriteTxt(const ServerInfo& info)
//	{
//		/*ofstream ofs(_filename);
//		ofs.write(info._ip, strlen(info._ip));
//		ofs.put('\n');
//		string portstr = to_string(info._port);
//		ofs.write(portstr.c_str(), portstr.size());*/
//
//		// C++�����ṩ�ģ�������cһ��������ʵ��
//		ofstream ofs(_filename);
//		ofs << info._ip << "\n" << info._port;
//	}
//
//	void ReadTxt(ServerInfo& info)
//	{
//		//ifstream ifs(_filename);
//		//ifs.getline(info._ip, 20);
//		//// 
//		//char portbuff[20];
//		//ifs.getline(portbuff, 20);
//		//info._port = stoi(portbuff);
//
//		// C++�����ṩ�ģ�������cһ��������ʵ��
//		ifstream ifs(_filename);
//		ifs >> info._ip >> info._port;
//	}
//
//private:
//	string _filename;
//};

//int main()
//{
//	ServerInfo rinfo;
//	ServerInfo winfo = {"192.0.0.1", 8000};
//	// ��д -- ������  -- ��д�򵥡���Ч��ݡ� ȱ�㣺�����ַ����ַ������ڴ���д���ļ���������
//	/*ConfigManager cfbin("config.bin");
//	cfbin.WriteBin(winfo);*/
//	//ConfigManager cfbin("config.bin");
//	//cfbin.ReadBin(rinfo);
//
//	// ��д -- �ı�
//	//ConfigManager cftxt("config.txt");
//	//cftxt.WriteTxt(winfo);
//
//	ConfigManager cftxt("config.txt");
//	cftxt.WriteTxt(rinfo);
//	cftxt.ReadTxt(rinfo);
//	return 0;
//}


//struct ServerInfo
//{
//	char _ip[20];
//	int  _port;
//};
//int main()
//{
//	ServerInfo info = { "192.0.0.1", 8000 };
//	//char buff[128];
//	//// ���л�
//	//sprintf(buff, "%s %d", info._ip, info._port);
//
//	//// �����л�
//	//ServerInfo rinfo;
//	//sscanf(buff, "%s%d", rinfo._ip, &rinfo._port);
//
//	//stringstream ssm;
//	/*ssm << info._ip <<" "<<info._port;
//	string buff = ssm.str();*/
//
//	/*stringstream ssm;
//	ssm.str("127.0.0.1 90");*/
//
//	/*stringstream ssm("127.0.0.1 90");
//	ServerInfo rinfo;
//	ssm >> rinfo._ip >> rinfo._port;*/
//	return 0;
//}