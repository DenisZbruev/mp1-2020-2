#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 11
void clean(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
float stoimost(int stoimost, int sale)//������� ��������� � ������ ������
{
	int s;
	s= (stoimost*((100-sale))/100);
	return (s);
}
void main()
{
	//int kod[N];
	int kod, i, flag=0;
	int count[N] = {0};//������ ���������
	char* tovar[N] = {"��������� ��� ��� 2113-2115", "����� ��������������� �� �������� ��� ��� 2113-2115", "����� ��������� ��� ��� 2113-2115", 
		"������� ��� ��� 2113 - 2115", "������� ��� ������������� ��� 2109", "������ ����������� ����������� �������� ��� ��� 2109", 
		"�������� ��������� �������� ������", "����� ���������������", "�������� ��������� �� - 03", 
		"��������� ������� ������ ��� ��� 2109 - 2115", "��������� ������� �������� ��� ��� 2109 - 2115"};
	char* tovar_number[N] = {"1001", "2001", "3001", "3002", "3101", "3102", "4001", "4002", "4003", "5001", "5002"};
    float st[N];
	float sum;
	setlocale(LC_ALL, "Russian");
	printf("���������� � �������: \n");
	//printf("1001 - ��������� ��� ��� 2113-2115 \n- ");
	//printf("2001 - ����� ��������������� �� �������� ��� ��� 2113-2115 \n- ");
	//printf("3001 - ����� ��������� ��� ��� 2113-2115 \n- ");
	//printf("3002 - ������� ��� ��� 2113-2115 \n- ");
	//printf("3101 - ������� ��� ������������� ��� 2109 \n- ");
	//printf("3102 - ������ ����������� ����������� �������� ��� ��� 2109 \n- ");
	//printf("4001 - �������� ��������� �������� ������ \n- ");
	//printf("4002 - ����� ��������������� \n- ");
	//printf("4003 - �������� ��������� ��-03 \n- ");
	//printf("5001 - ��������� ������� ������ ��� ��� 2109-2115 \n- ");
	//printf("5002 - ��������� ������� �������� ��� ��� 2109-2115 \n ");
	for (i = 0; i < N; i++)
	{
		printf("%s ", tovar_number[i]);
		printf(" - ");
		printf("%s \n", tovar[i]);
	}
	printf("������� �����-��� ������ (����������� �������������� �����): ");
	while (flag!=1)
	{
		scanf_s("%d", &kod);
		while ((kod < 1000) || (kod > 9999))
		{
			clean();
			printf("������� ������������ �������� �����-���� ������, ����������� ������: ");
			scanf_s("%d", &kod);
		}
		switch (kod)
		{
		case 1001:
			st[0] = stoimost(1500, 40);
			count[0]++;
			break;
		case 2001:
			st[1] = stoimost(3000, 15);
			count[1]++;
			break;
		case 3001:
			st[2] = stoimost(250, 15);
			count[2]++;
			break;
		case 3002:
			st[3] = stoimost(150, 5);
			count[3]++;
			break;
		case 3101:
			st[2] = stoimost(800, 10);
			count[4]++;
			break;
		case 3102:
			st[2] = stoimost(200, 15);
			count[5]++;
			break;
		case 4001:
			st[2] = stoimost(150, 10);
			count[6]++;
			break;
		case 4002:
			st[2] = stoimost(150, 10);
			count[7]++;
			break;
		case 4003:
			st[2] = stoimost(1500, 20);
			count[8]++;
			break;
		case 5001:
			st[2] = stoimost(600, 5);
			count[9]++;
			break;
		case 5002:
			st[2] = stoimost(500, 5);
			count[10]++;
			break;
		case 0:
			flag = 1;
			break;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (count[i] > 0)
			printf("%s", tovar[i]);
		    printf("    %d  ", count[i]);
			printf("   %5.2f ", st[i]);
			printf(" ������\n");
	}
	system("pause");
}