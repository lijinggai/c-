#include "singleton.h"


int Count = 0;
//GetInformation GetInformation::instance(10);//���壬��̬��Ա����������+::����
GetInformation* GetInformation::instance=nullptr;//���壬��̬��Ա����������+::����
GetInformation::CGarbo _CGarbo;//��������

void func()
{
	for (int i = 10; i > 0; i--)
	{
		++Count;
		GetInformation::GetInstance().Add(1);
		;
	}
}