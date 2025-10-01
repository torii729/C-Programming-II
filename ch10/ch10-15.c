/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch10 PPT ���� 10-13 : LINE ����ü�� ���� �� ���
	��¥ : 2025.10.01
*/

/*
    ���� ����:
    ����ü �ȿ� �ٸ� ����ü�� ����� ���Խ�ų �� �ִ�.
    �� �� (x1, y1), (x2, y2) ������ �Ÿ��� ��Ÿ��� ������ �̿��� sqrt((x2 - x1)^2 + (y2 - y1)^2)�� ���Ѵ�.
    const ����ü �����͸� �Լ� �Ű������� ����ϸ�, �Լ� �ȿ��� ����ü ������ �������� ������ �����Ѵ�.

    �޸� ����:
    LINE ����ü�� POINT ����ü �� ��(start, end)�� ���ӵ� �޸𸮿� �����Ѵ�.
    get_length �Լ��� �����ͷ� ���޹��� LINE ����ü���� ��ǥ�� �о�� ���̸� ����Ѵ�.
*/

#include <stdio.h>
#include <math.h> // sqrt �Լ� ���

typedef struct point {
    int x; // x ��ǥ
    int y; // y ��ǥ
} POINT;

typedef struct line {
    POINT start; // ������
    POINT end; // ����
} LINE;

double get_length(const LINE* ln); // ���� ���� ��� �Լ� ����

int main(void)
{
    LINE ln1 = { {10, 20}, {30, 40} }; // ������ (10,20), ���� (30,40)
    printf("������ ������ : (%d, %d)\n", ln1.start.x, ln1.start.y);
    printf("������ ���� : (%d, %d)\n", ln1.end.x, ln1.end.y);

    printf("������ ���� : %f\n", get_length(&ln1));

    return 0;
}

double get_length(const LINE* ln)
{
    int dx = ln->end.x - ln->start.x; // x ��ǥ ����
    int dy = ln->end.y - ln->start.y; // y ��ǥ ����

    return sqrt(dx * dx + dy * dy); // ��Ÿ���
}