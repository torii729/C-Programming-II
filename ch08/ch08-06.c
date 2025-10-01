/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch08 PPT ���� 8-1 : �������� ����Ʈ ũ�� ���ϱ�
    ��¥ : 2025.09.18
*/

/*
    ���� ���� :
    �����ʹ� ������ �ּ�(�޸� ��ġ)�� �����ϴ� �ڷ����̴�.
    �������� ũ��� ����Ű�� ��������(int, double, char ��)�� ������� �����ϴ�.
    32��Ʈ �ý��ۿ����� 4����Ʈ, 64��Ʈ �ý��ۿ����� 8����Ʈ�� �ȴ�.

    �޸� ���� :
    int *pi �� int�� ������ �ּҸ� ����
    double *pd �� double�� ������ �ּҸ� ����
    char *pc �� char�� ������ �ּҸ� ����
*/

#include <stdio.h>

// ��ɸ�: main. ���α׷� ������
// ����: ������ ������ �⺻ �ڷ����� ũ�⸦ ����Ѵ�.
// �Է�: ����
// ���: ������ ũ�� �� �ڷ��� ũ�� (���� ��)
// ����: ����
int main(void)
{
    int* pi; // int�� ������
    double* pd; // double�� ������
    char* pc; // char�� ������

    printf("sizeof(pi) = %zd\n", sizeof(pi)); // int�� ������ ũ��
    printf("sizeof(pd) = %zd\n", sizeof(pd)); // double�� ������ ũ��
    printf("sizeof(pc) = %zd\n", sizeof(pc)); // char�� ������ ũ��

    printf("sizeof(int) = %zd\n", sizeof(int)); // int�� ���� ũ��
    printf("sizeof(double) = %zd\n", sizeof(double)); // double�� ���� ũ��
    printf("sizeof(char*) = %zd\n", sizeof(char*)); // char* Ÿ�� ũ��

    return 0;
}