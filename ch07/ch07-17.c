/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� 7-14 : print_array �Լ��� ���� �� ȣ��
    ��¥ : 2025.09.15
*/

#include <stdio.h>
#define MAX 10

void print_array(int arr[], int size); // �Լ� ���� ����

// ��ɸ�: main. �迭 ��� �Լ� ȣ��
// ����: �� ���� �迭(scores, arr)�� ���� �� �ʱ�ȭ�ϰ�,
//       print_array �Լ��� ȣ���Ͽ� �� �迭�� ������ ����Ѵ�.
// �Է�: ����
// ���: �� �迭�� ��� ���Ҹ� �ֿܼ� ����Ѵ�.
// ����: ����
int main(void)
{
    int scores[] = { 99, 98, 67, 72, 90, 82 }; // ũ�� 6�� �迭 �ʱ�ȭ
    int size = sizeof(scores) / sizeof(scores[0]); // �迭 ���� ���� ���
    int arr[MAX] = { 0 }; // ũ�� 10 �迭 �ʱ�ȭ (��� 0)

    print_array(scores, size); // �迭 scores ���
    print_array(arr, MAX); // �迭 arr ���

    return 0;
}

// ��ɸ�: print_array. �迭 ��� ������
// ����: �迭�� �� ũ�⸦ ���޹޾� ��� ���Ҹ� ������� ����Ѵ�.
// �Է�: int arr[] (���� �迭), int size (�迭 ũ��)
// ���: �迭�� ��� ���Ҹ� �ֿܼ� ����Ѵ�.
// ����: ����
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]); // �迭 ���� ���
    printf("\n");
}
