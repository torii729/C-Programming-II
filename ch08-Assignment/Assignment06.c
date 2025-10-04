/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : 6. ������ �迭�� ���Ͽ� �迭�� ���� �� �ִ񰪰� �ּڰ��� ã�� get_min_max �Լ��� �����Ͻÿ�.
        ũ�Ⱑ 10�� int �迭�� ���ؼ� ���ϴ� ������ �ʱⰪ�� ä�� ���� get_min_max �Լ��� �ִ񰪰� �ּڰ��� ã�Ƽ� ����Ͻÿ�.
    ��¥ : 2025.09.22
*/

#include <stdio.h>

void test(void);
void get_min_max(int a[], int n, int* pmax, int* pmin);

// ��ɸ�: main. ���α׷� ������
// ����: test �Լ��� ȣ���Ͽ� �迭�� �ִ񰪰� �ּڰ��� ����Ѵ�.
// �Է�: ����
// ���: �迭�� �ִ�, �ּڰ��� �ֿܼ� ����Ѵ�.
// ����: ����
int main(void)
{
    test();
    return 0;
}

/*
    ��ɸ�: get_min_max. �迭 �� �ִ� �� �ּڰ� ���
    ����: ������ �迭�� ��ȸ�ϸ� �ִ񰪰� �ּڰ��� ã�� �ܺ� ����(pmax, pmin)�� �����Ѵ�.
    �Է�: int a[] (�迭), int n (ũ��), int* pmax (�ִ� ���� �ּ�), int* pmin (�ּڰ� ���� �ּ�)
    ���: ���� (����� �����͸� ���� ��ȯ��)
    ����: �迭 ũ�Ⱑ 0 ������ ��� �Լ� ��� ����
*/
void get_min_max(int a[], int n, int* pmax, int* pmin)
{
    int i = 0;

    if (n <= 0)
    {
        return;
    }

    *pmax = a[0];
    *pmin = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > *pmax)
        {
            *pmax = a[i];
        }
        if (a[i] < *pmin)
        {
            *pmin = a[i];
        }
    }
}

/*
    ��ɸ�: test. get_min_max �Լ� �׽�Ʈ
    ����: ũ�Ⱑ 10�� ���� �迭�� �ʱ�ȭ�ϰ�, get_min_max �Լ��� ȣ���Ͽ� �ִ񰪰� �ּڰ��� ����Ѵ�.
    �Է�: ����
    ���: �迭 ��ü, �ִ�, �ּڰ��� �ֿܼ� ����Ѵ�.
    ����: ����
*/
void test(void)
{
    int a[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int n = 10;
    int maxv = 0;
    int minv = 0;
    int i = 0;

    printf("�迭: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    get_min_max(a, n, &maxv, &minv);

    printf("�ִ�: %d\n", maxv);
    printf("�ּڰ�: %d\n", minv);
}
