/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� 7-15 : copy_array �Լ��� ���� �� ȣ��
    ��¥ : 2025.09.15
*/

#include <stdio.h>
#define SIZE 7

void copy_array(int source[], int target[], int size); // �Լ� ����
void print_array(int arr[], int size); // �Լ� ����

// ��ɸ�: main. �迭 ���� �� ���
// ����: ���� �迭 x�� �����ϰ�, copy_array �Լ��� �̿��� �迭 y�� �����Ѵ�.
//       print_array �Լ��� ȣ���� �� �迭�� ������ ����Ѵ�.
// �Է�: ����
// ���: ���� ������ �迭 ������ �ֿܼ� ����Ѵ�.
// ����: ����
int main(void)
{
    int x[SIZE] = { 10, 20, 30, 40, 50 }; // ���� �迭
    int y[SIZE] = { 0 }; // ��� �迭 (�ʱⰪ 0)

    printf("x = ");
    print_array(x, SIZE); // �迭 x ���
    copy_array(x, y, 5); // �迭 x�� �� 5�� ���Ҹ� y�� ����
    printf("y = ");
    print_array(y, SIZE); // �迭 y ���

    return 0;
}

// ��ɸ�: copy_array. �迭 ���� �Լ�
// ����: source �迭�� ���Ҹ� target �迭�� ������� �����Ѵ�.
// �Է�: int source[] (���� �迭), int target[] (���� ��� �迭), int size (������ ũ��)
// ���: ����
// ����: size�� �迭 ũ�⸦ �ʰ��ϸ� �߸��� �޸� ���� ����
void copy_array(int source[], int target[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i]; // ���� �ϳ��� ����
}

// ��ɸ�: print_array. �迭 ��� �Լ�
// ����: ���޹��� �迭�� ��� ���Ҹ� ������� ����Ѵ�.
// �Է�: int arr[] (���� �迭), int size (�迭 ũ��)
// ���: �迭�� ��� ���Ҹ� �ֿܼ� ����Ѵ�.
// ����: ����
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
