#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	int count;
	float x1, y1, r1, x2, y2, r2; 
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� ������ ������ ���������� � �� ������ ����� ������: ");
	count = scanf_s("%f, %f, %f", &x1, &y1, &r1);//�������� �������
	while ((count != 3) && (r1<=0))
	{
		printf("������ �����, ����������� ������: \n");
		count = scanf_s("%f, %f, %f", &x1, &y1, &r1);
	}
	printf("������� ���������� ������ ������ ���������� � �� ������ ����� ������: ");
	count = scanf_s("%f, %f, %f", &x2, &y2, &r2);//�������� �������
	while (count != 3)
	{
		printf("������ �����, ����������� ������: \n");
		count = scanf_s("%f, %f, %f", &x2, &y2, &r2);
	}
	if ((r1 == r2) && ((y1 == y2) && (x1 == x2)))
	{
		printf("���������� ���������");
	}
	else
		if (((r2 > r1) || (r2 < r1)) && (y1 == y2) && (x1 == x2))
		{
			printf("���� ���������� ����� ������ ������");
		}
	if ((r1 + r2) < sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
	{
		printf("���������� ����� ��� ���� ����� ");
	}

	if ((r1 + r2) == sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
	{
		printf("���������� �������� ���� ����� �����");
	}
	else 
		if (fabs(r1 - r2) == sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
		{
			printf("���������� �������� ���� ����� �������");
		}

	






}