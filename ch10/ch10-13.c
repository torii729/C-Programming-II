/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch10 PPT ���� 10-11 : ����ü���� ��� �Ű������� ���� �Լ��� ����
	��¥ : 2025.10.01
*/

/*
    ���� ���� :
    srand�� ���� �߻����� �ʱⰪ�� �����ϸ�, time(NULL)�� �̿��� ������ ������ �ٸ� ������ �����Ѵ�.
    rand�� ������ ��ȯ�ϸ�, % ������ ���� ���ϴ� ������ ���� ���� �� �ִ�.
    ����ü �����͸� ����ϸ� �Լ����� ���� ����ü ��� ���� ������ �� �ִ�.
    const �����͸� ����ϸ� �Լ� ������ ����ü �����͸� ������ �� ������ �����Ѵ�.

    �޸� ���� :
    arr �迭�� Point ����ü 5���� �������� �����Ѵ�.
    set_point �Լ��� ����ü �����͸� �޾� ������ ����� ���� �����Ѵ�.
    print_point �Լ��� const �����͸� ���� ����� �б� �������� �����Ѵ�.

	srand, rand�� stdlib.h�� time.h�� ����Ǿ� �ִ�.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point {
    int x; // x ��ǥ
    int y; // y ��ǥ
} Point;

void print_point(const Point* pt); // ����ü �б� ���� ��� �Լ�
void set_point(Point* pt, int x, int y); // ����ü ��� ���� �Լ�

int main(void)
{
    Point arr[5] = { 0 }; // ����ü �迭 �ʱ�ȭ
    int sz = sizeof(arr) / sizeof(arr[0]); // �迭 ũ�� ���
    int i;

    srand((unsigned int)time(NULL)); // ���� �߻��� �ʱ�ȭ
    for (i = 0; i < sz; i++) {
        int x = rand() % 100; // 0~99 ���� ����
        int y = rand() % 100; // 0~99 ���� ����
        set_point(&arr[i], x, y); // ���� ��ǥ�� ����ü �� ����
    }

    for (i = 0; i < sz; i++)
    {
        print_point(&arr[i]); // ����ü ���
        printf(" ");
    }
    printf("\n");

    return 0;
}

void print_point(const Point* pt)
{
    printf("(%d, %d)", pt->x, pt->y); // ����ü ��� ���
}

void set_point(Point* pt, int x, int y)
{
    pt->x = x; // x �� ����
    pt->y = y; // y �� ����
}
