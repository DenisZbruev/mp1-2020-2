#include <stdio.h>
#include <locale.h>
void clean(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);

}
void main()
{
	float h, w, d, DWP, DSP, WOOD, M;
	int k;//�-���������� �����
	const float P_DVP = 820;
	const float P_DSP = 720;
	const float P_WOOD = 800;
	const float TDVP = 0.005;
	const float TDSP = 0.015;
	const float TWOOD = 0.01;
	const float H_Proem = 0.415;//�������, ��� ������ ������ 40 ��
	setlocale(LC_ALL, "Russian");
	printf("������� ������ ����� h � �����������, ������� ������� ����� �������: ");
	scanf_s("%f", &h);
	while ((h > 220) || (h < 180))
	{
		clean();
		printf("������� ������������ ��������, ���������� ������ ������: ");
		scanf_s("%f", &h);
	}
	h = h / 100;
	printf("������� ������ ����� w � �����������, ������� ������� ����� �������: ");
	scanf_s("%f", &w);
	while ((w > 120) || (w < 80))
	{
		clean();
		printf("������� ������������ ��������, ���������� ������ ������: ");
		scanf_s("%f", &w);
	}
	w = w / 100;
	printf("������� ������� ����� d � �����������, ������� ������� ����� �������: ");
	scanf_s("%f", &d);
	while ((d > 90) || (d < 50))
	{
		clean();
		printf("������� ������������ ��������, ���������� ������ ������: ");
		scanf_s("%f", &d);
	}
	d = d / 100;
	k = h / H_Proem;
	if ((h - k * H_Proem) != 0)
		k = k + 1;
	M = 2 * (h - 2 * TDSP) * d * TDSP * P_DSP + w * h * TDVP * P_DVP + 2 * w * d * TDSP * TDSP + w * h * TWOOD * P_WOOD + k * d * (w - 2 * TDSP) * P_DSP * TDSP;
	printf("����� �����: %f", M);
	printf(" �� \n");
	system("pause");
}