#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	float x1, y1, r1, x2, y2, r2; 
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� ������ ������ ���������� � �� ������, ������ ��� ������� Enter: ");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("������� ���������� ������ ������ ���������� � �� ������, ������ ��� ������� Enter: ");
	scanf_s("%f%f%f", &x2, &y2, &r2);
	if ((r1 == r2) && ((y1 == y2) && (x1 == x2)))
	{
		printf("���������� ��������� \n");
	}
	else
	  if ((pow((x2 - x1), 2) + pow((y2 - y1), 2)) < pow((r2 - r1), 2))
	   {
		  printf("���� ���������� ����� ������ ������ \n");
	   }
	  else    
	    if ((r1 + r2) < sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
	     {
		    printf("���������� ����� ��� ���� ����� \n");
	     }
		else
	      if ((r1 + r2) == (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))))
	       {
		      printf("���������� �������� ���� ����� ����� \n");
	       }
	      else 
		    if (fabs(r1 - r2) == (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))))
		     {
			    printf("���������� �������� ���� ����� ������� \n");
		     }
			else 
				printf("���������� ������������ \n");
	system("pause");
}
