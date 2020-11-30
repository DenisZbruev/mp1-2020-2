//����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� ����������� / �������� �������.

//������� ������ :
//���� �� ����������, � ������� ���������� ������������� ����������.
//����� ����������.
//�������� ������ :
//��������������� ������ ���� ������ � ��������� �������.
//����� ����������.
//��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.
//��������� ������ ������������� ������ � ������������� ����������� ����������, ������� �������� :
//����������� ����� ���� �� ��������� ��������;
//����������� ������ ������ ����������;
//����������� ��������� ���������������� ������ ������ � ��������� �������.
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <omp.h>


#define N 8  //���������� ������
struct File
{
    char* File_Name;
    int File_long;
};

void clean(void)//������� ����� �����
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int setmin(struct File* arr, int size)//������� ����� ��������. �� �������, ����� ��� ����������!
{
    int tmp = INT_MAX, i;

    for (i = 0; i < size; i++)
    {
        if (arr[i].File_long < tmp)
            tmp = arr[i].File_long;
    }
    return tmp;
}

int setmax(int* arr, int size)//������� ����� ���������
{
    int tmp = INT_MIN, i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] > tmp)
            tmp = arr[i];
    }
    return tmp;
}

int increment(int inc[], int size) {
    int p1, p2, p3, s;
    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2)
        {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else
        {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);
    return (s > 0 ? --s : 0);
}

struct File* bubbleSort(struct File* arr, int size)//� ����� ������� ����� ����� ���������� ������� ����� � switch. ���������� ���������
{
    int i, j;
    struct File tmp;
    for (i = 0; i < size; i++)
    {            // i - ����� �������
        for (j = size - 1; j > i; j--)
        {     // ���������� ���� �������
            if (arr[j - 1].File_long > arr[j].File_long)//��������� �����, � ������ ������� ������ ���������
            {
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    return arr;
}

struct File* selectSort(struct File* arr, int size)//� ����� ������� ����� ����� ���������� ������� ����� � switch. �������
{
    int i, j, k;
    struct File tmp;
    for (i = 0; i < size; i++) {   	// i - ����� �������� ����
        k = i; tmp = arr[i];

        for (j = i + 1; j < size; j++)	// ���� ������ ����������� ��������
            if (arr[j].File_long < tmp.File_long) {
                k = j;
                tmp = arr[j];	        // k - ������ ����������� ��������
            }

        arr[k] = arr[i];
        arr[i] = tmp;   	// ������ ������� ���������� � a[i]
    }
    return arr;
}

struct File* insertSortGuarded(struct File* arr, int size)//� ����� ������� ����� ����� ���������� ������� ����� � switch//���������
{
    int i, j;
    struct File tmp_st;
    int tmp;
    int backup = setmin(arr, size);				// �������� �� �����������
    for (i = 1; i < size; i++) // ������������� ������
    {
        tmp = arr[i].File_long;
        tmp_st = arr[i];
        for (j = i - 1; arr[j].File_long > tmp; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = tmp_st;
    }
    for (j = 1; j < size && arr[j].File_long < backup; j++)// �������� backup �� ���������� �����
        arr[j - 1] = arr[j];
    arr[j - 1].File_long = backup;// ������� �������� 
    return arr;
}

struct File* mergeSort(struct File* arr, int size)
{
    int step = 1;  // ��� ��������� ������������������
    struct File* temp;
    temp = (struct File*)malloc(size * sizeof(struct File)); // �������������� ������
    while (step < size)  // ���� ��� ������ ����� �������
    {
        int index = 0;    // ������ ��������������� �������
        int l = 0;      // ����� ������� �������
        int m = l + step;  // �������� �������
        int r = l + step * 2;  // ������ ������� �������
        do
        {
            m = m < size ? m : size;  // ����������� ������� �� ������� �� ������� ������������������
            r = r < size ? r : size;
            int i1 = l, i2 = m; // ������� ������������ ���������
            for (; i1 < m && i2 < r; ) // ���� i1 �� ����� �� �������� � i2 �� ����� �� �����
            {//
                if (arr[i1].File_long < arr[i2].File_long)
                {
                    temp[index++] = arr[i1++];
                } // ��������� ������� �������������� ������������������
                else
                {
                    temp[index++] = arr[i2++];
                }
            }
            // ��� i1 < m ��� i2 < r - ������ ���� �� ���������� while ����� �����������
            while (i1 < m)
                temp[index++] = arr[i1++]; // ������� ���������� �������� ����������� ��������
            while (i2 < r)
                temp[index++] = arr[i2++]; // � �������������� ������
            l += step * 2; // ������������ �� ��������� ����������� �������
            m += step * 2;
            r += step * 2;
        } while (l < size); // ���� ����� ������� ������������ ������� - � �������� �����������������
        for (int i = 0; i < size; i++) // ��������� �������������� ������ ������� � a
            arr[i] = temp[i];
        step *= 2; // ����������� � 2 ���� ��� ���������
    }
    free(temp);
    return (arr);
}

struct File* quickSort(struct File* arr, int left, int right)//� ����� ������� ����� ����� ���������� ������� ����� � switch
{
    int l_hold = left; //����� �������
    int r_hold = right; // ������ �������
    struct File pivot = arr[left];
    while (left < right) // ���� ������� �� ���������
    {
        while ((arr[right].File_long >= pivot.File_long) && (left < right))
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            arr[left] = arr[right]; // ���������� ������� [right] �� ����� ������������
            left++; // �������� ����� ������� ������
        }
        while ((arr[left].File_long <= pivot.File_long) && (left < right))
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
        if (left != right) // ���� ������� �� ����������
        {
            arr[right] = arr[left]; // ���������� ������� [left] �� ����� [right]
            right--; // �������� ������ ������� ������
        }
    }
    arr[left] = pivot; // ������ ����������� ������� �� �����
    pivot.File_long = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot.File_long) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        quickSort(arr, left, pivot.File_long - 1);
    if (right > pivot.File_long)
        quickSort(arr, pivot.File_long + 1, right);
    return(arr);
}

struct File* shellSort(struct File* arr, int size)//� ����� ������� ����� ����� ���������� ������� ����� � switch ��������
{
    struct File temp;
    int inc, i, j, seq[40];
    int s;
    s = increment(seq, size);// ���������� ������������������ ����������
    while (s >= 0)
    {
        // ���������� ��������� � ������������ inc[] 
        inc = seq[s--];

        for (i = inc; i < size; i++)
        {
            temp = arr[i];
            for (j = i - inc; (j >= 0) && (arr[j].File_long > temp.File_long); j -= inc)
                arr[j + inc] = arr[j];
            arr[j + inc] = temp;
        }
    }
    return (arr);
}

struct File* countSort(struct File* osnova, int size)
{
    int* count;
    int i, j, pos = 0;
    struct File tmp;
    int* arr;
    int max;
    int min;
    arr = (int*)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
        arr[i] = osnova[i].File_long;//������������� ������� ���� ������
    max = setmax(arr, size);
    min = setmin(osnova, size);
    count = (int*)malloc(sizeof(int) * (max - min + 2));
    for (i = 0; i < (max - min + 1); i++)
        count[i] = 0;
    for (i = min; i < (max + 1); i++)
        for (j = 0; j < size; j++)
        {
            if (arr[j] == i)
                count[i - min]++;
        }
    for (i = 0; i < (max - min + 1); i++)
        for (j = 0; j < count[i]; j++)
        {
            arr[pos] = min + i;
            pos++;
        }
    pos = 0;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if (osnova[j].File_long == arr[i])//��������� ��������� � ����������� � ������
            {
                tmp = osnova[pos];
                osnova[pos] = osnova[j];
                osnova[j] = tmp;
                pos++;
            }
    free(arr);
    free(count);
    return(osnova);
}
void showmenu()
{
    char* menu[N] = { "���������� ���������", "���������� �������", "���������� ���������", "���������� ��������", "���������� �����", "���������� �����", "���������� ���������", "�����" };//������ � ���������� ����������
    short int menu_number[N] = { 1, 2, 3, 4, 5, 6, 7, 0 };//������ � ������ ������� ������
    int i, n = 8;
    for (i = 0; i < n; i++)
    {
        printf("%d", menu_number[i]);
        printf(". %s\n", menu[i]);
    }
    printf("������� ����� ����������: ");
}


void main()

{
    int num, flag = 1, j = 0, k;
    struct _finddata_t c_file;
    struct File* Filearr;
    intptr_t hFile;
    char path[260];
    int count = 0;
    int size, i = 0;
    double t1, t2;
    char way[265] = { 0 };//�������� ������
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (flag == 1)
    {
        if (j == 0)
            printf("������� ���� �� ����������: ");
        else
            printf("������ ������� ���� �� ����������? ���� ���, ������� 0: ");
        j++;
        gets(path);
        showmenu();
        scanf_s("%d", &num);
        while ((num < 0) || (num > 7))
        {
            clean();
            printf("������� ������������ ��������, ����������� ������: ");
            scanf_s("%d", &num);
        }
        if (num == 0)
            break;
        size = strlen(path);
        if (size != 1)
        {
            for (i = 0; i < size; i++)
            {
                if (path[i] == '\\')
                    path[i] = '/';
            }
            for (i = 0; i < size; i++)//������������ ������, ��������� �������������, � �������� ������
            {
                way[i] = path[i];
            }
            way[size] = '/';//��� 4 ������� - ���������� � �������� ������ ��������� "/*.*"
            way[size + 1] = '*';
            way[size + 2] = '.';
            way[size + 3] = '*';
            way[size + 4] = '\0';
        }
        if ((hFile = _findfirst(way, &c_file)) == -1L)
            printf("No files in current directory!\n");
        else
        {
            count = 0;
            printf("Listing of .c files\n\n");
            printf("FILE SIZE\n", ' ');//
            printf("--------\n", ' ');//
            do {
                count++;
            } while (_findnext(hFile, &c_file) == 0);//������� ���������� ������
            _findclose(hFile);
            Filearr = (struct File*)malloc(sizeof(struct File) * count);//�������� ������������ ������
            hFile = _findfirst(way, &c_file);
            i = 0;

            do {//�������� �� ����� ������ ���, ������������� ���������� � ����� � ������ �������� Filearr
                Filearr[i].File_long = c_file.size;
                Filearr[i].File_Name = (char*)malloc(sizeof(char) * 265);
                for (k = 0; k < 265; k++)
                    Filearr[i].File_Name[k] = c_file.name[k];//���������� ��� ����� � ������ Filearr[i].File_Name �����������
                //printf("%-12.12s %d\n", Filearr[i].File_Name, Filearr[i].File_long);//�������� ���������� � �����
                i++;
            } while (_findnext(hFile, &c_file) == 0);
            _findclose(hFile);

            switch (num)
            {
            case 1:
                t1 = omp_get_wtime();
                Filearr = bubbleSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 2:
                t1 = omp_get_wtime();
                Filearr=selectSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 3:
                t1 = omp_get_wtime();
                Filearr = insertSortGuarded(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 4:
                t1 = omp_get_wtime();
                Filearr = mergeSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 5:
                t1 = omp_get_wtime();
                Filearr = quickSort(Filearr, 0, count);
                t2 = omp_get_wtime();
                break;
            case 6:
                t1 = omp_get_wtime();
                Filearr = shellSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 7:
                t1 = omp_get_wtime();
                Filearr = countSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            }
            for(i=0; i<count; i++)//?
                printf("%-12.12s %d\n", Filearr[i].File_Name, Filearr[i].File_long);
            printf("����� ����������: %lf\n", (t2 - t1));
            for (i = 0; i < count; i++)
                free(Filearr[i].File_Name);
            free(Filearr);
            clean();//����� ������ ����� �����, ��� ��� ���� ���� �� ����������, ���������� ����� ������� ���� �� ����������
        }
    }
    system("pause");
}