#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int N, number;
	int P;//� ��� ������������ ������� ������������
	setlocale(LC_ALL, "Russian");

	printf("������� ����� ������: ");
	scanf_s("%d", &number);
	if (number == 1)
	{
		srand(time(NULL));
		N = rand() % 1000 + 1;
		printf("%d\n", N);
		printf("����������� �������: ");
		scanf_s("%d", &P);
		while (N != P)
		{
			if (N > P)
			{
				printf("���������� ����� ������ \n");
			}
			else
				if (N < P)
				{
					printf("��������� ����� ������ \n");
				}
			printf("����������� ������� ��� ���: ");
			scanf_s("%d", &P);
		} 
		printf("�� �������! +100 � ���������� \n");
	}
	else if (number == 2)
	{



	}
	else
	{
		printf("������ �����");
	}
	system("pause");
}