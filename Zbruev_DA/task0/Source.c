#include <stdio.h>
#include <locale.h>
//#include <iostream>
void main()
{
	float x1, y1, r1, x2, y2, r2, count; 
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






}