#include<stdio.h>
#include<string.h>
#pragma once
//��ţ�������á��ߡ����򡢺�����������Լ���˵�е���
void Zodiac(int x)//switch�ж���Ф
{
	switch (x)
	{
	case 1:
		printf("�����Ф����");
		break;
	case 2:
		printf("�����Ф��ţ");
		break;
	case 3:
		printf("�����Ф�ǻ�");
		break;
	case 4:
		printf("�����Ф����");
		break;
	case 5:
		printf("�����Ф����");
		break;
	case 6:
		printf("�����Ф����");
		break;
	case 7:
		printf("�����Ф����");
		break;
	case 8:
		printf("�����Ф�Ǻ�");
		break;
	case 9:
		printf("�����Ф�Ǽ�");
		break;
	case 10:
		printf("�����Ф�ǹ�");
		break;
	case 11:
		printf("�����Ф����");
		break;
	case 12:
		printf("�����Ф����");
		break;
	}
	printf("\n");
}
void Constellation(month, day)//switch�ж�����
{
	switch (month)
	{
	case 1:
		if(day<=19)
			printf("���������Ħ����");
		else
			printf("���������ˮƿ��");
		break;
	case 2:
		if (day <= 18)
			printf("���������ˮƿ��");
		else
			printf("���������˫����");
		break;
	case 3:
		if (day <= 20)
			printf("���������˫����");
		else
			printf("��������ǰ�����");
		break;
	case 4:
		if (day <= 20)
			printf("��������ǰ�����");
		else
			printf("��������ǽ�ţ��");
		break;
	case 5:
		if (day <= 20)
			printf("��������ǽ�ţ��");
		else
			printf("���������˫����");
		break;
	case 6:
		if (day <= 21)
			printf("���������˫����");
		else
			printf("��������Ǿ�з��");
		break;
	case 7:
		if (day <= 22)
			printf("��������Ǿ�з��");
		else
			printf("���������ʨ����");
		break;
	case 8:
		if (day <= 22)
			printf("���������ʨ����");
		else
			printf("��������Ǵ�Ů��");
		break;
	case 9:
		if (day <= 22)
			printf("��������Ǵ�Ů��");
		else
			printf("��������������");
		break;
	case 10:
		if (day <= 22)
			printf("��������������");
		else
			printf("�����������Ы��");
		break;
	case 11:
		if (day <= 21)
			printf("�����������Ы��");
		else
			printf("���������������");
		break;
	case 12:
		if (day <= 2)
			printf("���������������");
		else
			printf("���������Ħ����");
		break;
	}
	printf("\n");
}

int main()
{
	//50024220030512
	char name[10];
	char ID[19];
	printf("������������֣�");
	scanf("%s", name);
	printf("������������֤���룺");
	scanf("%s", ID);
	//char* pID = ID;
	//char year[5];
	//char* pyear=year;
	//strncpy(year, pID + 6, 4);
	//year[4] = '\0';
	int year=0,month=0,day=0;
	int index = 1;
	for (int i = 0; i < 4; i++)//ȡ������
	{
		
		year +=(ID[9 - i] - '0') * index;
		if (i < 2)
		{
			month += (ID[11 - i] - '0')*index;
			day += (ID[13 - i] - '0') * index;

		}
		index *= 10;
	}
	if ((ID[16] - '0') % 2 == 0)//����ż���ж���Ů
		printf("%sŮʿ\n",name);
	else
		printf("%s��ʿ\n", name);
	printf("��ĳ�����\%d�꣬", year);
	Zodiac(year % 12);//switch�ж���Ф
	printf("���������%d��%d�գ�",month,day);
	Constellation(month,day);//switch�ж�����
	return 0;
}