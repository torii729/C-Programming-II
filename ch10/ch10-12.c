/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch10 PPT ���� 10-10 : ����ü�� �����ͷ� �����Ϸ��� ���
	��¥ : 2025.10.01
*/

/*
    ���� ���� :
    �Ϲ����� ������ ����ó�� �ּ� �����ڸ� ���Ͽ� �Ű������� ������ ��
	-> �����ڸ� �̿��Ͽ� ����ü ����� �����Ѵ�.
    ����ü�� �����ϴ� ��� �ּҸ� �����ϴ� ����̴�.
	�̷��� �Ǹ� pass by value ����� �ƴ� pass by reference ����� �䳻�� �� �ִ�.
*/

#include <stdio.h>

typedef struct point {
    int x; // x ��ǥ
    int y; // y ��ǥ
} Point;

void print_point(Point *pt); // ����ü�� �Ű������� �޴� �Լ� ����

int main(void)
{
    Point arr[] = {
        {0, 0},
        {10, 10},
        {20, 20},
        {30, 30},
        {40, 40}
    };
    int sz = sizeof(arr) / sizeof(arr[0]); // �迭 ���� ����
    int i;

    for (i = 0; i < sz; i++)
    {
        print_point(&arr[i]); // ����ü �� ����
        printf(" ");
    }
    printf("\n");

    return 0;
}

void print_point(Point *pt)
{
    printf("(%d, %d)", pt->x, pt->y); // ����ü ��� ���
}
