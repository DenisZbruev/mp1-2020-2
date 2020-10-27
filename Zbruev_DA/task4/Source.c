#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 4
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
	int kod;
	float s;
	setlocale(LC_ALL, "Russian");
	printf("���������� � ������� \n- ");
	printf("1001 - ��������� ��� ��� 2113-2115 \n- ");
	printf("2001 - ����� ��������������� �� �������� ��� ��� 2113-2115 \n- ");
	printf("3001 - ����� ��������� ��� ��� 2113-2115 \n- ");
	printf("3002 - ������� ��� ��� 2113-2115 \n- ");
	printf("3101 - ������� ��� ������������� ��� 2109 \n- ");
	printf("3102 - ������ ����������� ����������� �������� ��� ��� 2109 \n- ");
	printf("4001 - �������� ��������� �������� ������ \n- ");
	printf("4002 - ����� ��������������� \n- ");
	printf("4003 - �������� ��������� ��-03 \n- ");
	printf("5001 - ��������� ������� ������ ��� ��� 2109-2115 \n- ");
	printf("5002 - ��������� ������� �������� ��� ��� 2109-2115 \n ");
	printf("������� �����-��� ������ (����������� �������������� �����): ");
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
		printf("- ��������� ��� ��� 2113-2115    %5.2f", stoimost(1500, 40));
		printf(" ������\n");
		break;
	case 2001:
		printf("- ����� ��������������� �� �������� ��� ��� 2113-2115    %5.2f\n ", stoimost(3000, 15));
		printf(" ������\n");
		break;
	case 3001:
		printf("- ����� ��������� ��� ��� 2113-2115    %5.2f\n ", stoimost(250, 15));
		printf(" ������\n");
		break;
	case 3002:
		printf("- ������� ��� ��� 2113-2115    %5.2f\n ", stoimost(150, 5));
		printf(" ������\n");
		break;
	case 3101:
		printf("- ������� ��� ������������� ��� 2109    %5.2f\n ", stoimost(800, 10));
		printf(" ������\n");
		break;
	case 3102:
		printf("- ������ ����������� ����������� �������� ��� ��� 2109    %5.2f\n ", stoimost(200, 15));
		printf(" ������\n");
		break;
	case 4001:
		printf("- �������� ��������� �������� ������    %5.2f\n ", stoimost(150, 10));
		printf(" ������\n");
		break;
	case 4002:
		printf("- ����� ���������������    %5.2f\n ", stoimost(150, 10));
		printf(" ������\n");
		break;
	case 4003:
		printf("- �������� ��������� ��-03    %5.2f\n ", stoimost(1500, 20));
		printf(" ������\n");
		break;
	case 5001:
		printf("- ��������� ������� ������ ��� ��� 2109-2115    %5.2f\n ", stoimost(600, 5));
		printf(" ������\n");
		break;
	case 5002:
		printf("- ��������� ������� �������� ��� ��� 2109-2115    %5.2f\n ", stoimost(500, 5));
		printf(" ������\n");
		break;
	} 
	system("pause");
}