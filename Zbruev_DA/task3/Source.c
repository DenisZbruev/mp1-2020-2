#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 5
void main()
{
	int n;//���������� ���� � �����
	int t;//
	int P, ost, step, i, h, b=0;//P-����� ������������
	int clon;//� ��� ������������ ����� ����� P
	int cow = 0;
	int buffalo = 0;
	int arr[N];//
	char c = 0;
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� ���� � ����� (�������� �� 2 �� 5): ");
	scanf_s("%d", &n);
	while ((n < 2) || (n > 5))
	{
		printf("������� ������������ �������� ����� �����, ����������� ������: ");
		scanf_s("%d", &n);
	}
	srand(time(NULL));
	arr[0] = rand() % 9+1;
	for (i = 1; i < N; i++)
		arr[i] = arr[0];
	for (i = 1; i < n; i++)
	{
			do
			{
				t = rand() % 10;
			} while ((arr[0] == t)|| (arr[1] == t) || (arr[2] == t) || (arr[3] == t) || (arr[4] == t));
		arr[i] = t;
	}
	for (i = 0; i < n; i++)//������ ����� 
		b = b * 10 + arr[i];
	                                        printf("����� b:%i \n", b);
	while (1)
	{
		printf("����������� �������� �����, �� ���������� ���������� ����.  \n");
		scanf_s("%d", &P);
		for (i = n - 1; i >= 0; i--)
		{
			step = P % 10;
			P = P / 10;
			if ((step == arr[0]) || (step == arr[1]) || (step == arr[2]) || (step == arr[3]) || (step == arr[4]))
				cow++;
			if (step == arr[i])
				buffalo++;
		}
		if (buffalo == n)
		{
			printf("�� ��������!\n");
			break;
		}
		else
		{
			printf("���������� �����: %i\n", cow);
			printf("���������� �����: %i\n", buffalo);
			cow = 0;
			buffalo = 0;
			printf("���� ������ ��������� �������, ������� ������ !. ���� ������ ����������, ������ ������� Enter\n");
			c = getchar();
			c = getchar();
			if (c == '!')
			{
				printf("��������� ����������� \n");
				break;
			}
		}
	}
	system("pause");
}
