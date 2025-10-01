/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� 7-15 : copy_array �Լ��� ���� �� ȣ��
    ��¥ : 2025.09.15
*/

#include <stdio.h>
#define SIZE 7

void copy_array(int source[], int target[], int size); // �迭 ���� �Լ� ����
void print_array(int arr[], int size); // �迭 ��� �Լ� ����

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

void copy_array(int source[], int target[], int size) // �迭 ���� �Լ�
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i]; // ���� �ϳ��� ����
}

void print_array(int arr[], int size) // �迭 ��� �Լ�
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
