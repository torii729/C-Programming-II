/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : 1. ���������� ���� �׿� �׻� ������ ��(����)�� ���Ͽ� ������ �����̴�.
            ũ�Ⱑ 10�� ������ �迭�� ���Ͽ� ���������� ���� ä����� �Ѵ�.
            ù ��° ���� ���� ����(common difference)�� �Է¹޾Ƽ� �迭�� ä��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
    ��¥ : 2025.09.16
*/

#define ARR_SIZE 10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fillCD(int arr[], int size, int start, int diff);
int Assign01();
void printArray(int arr[], int size);

// ��ɸ�: main. �������� ���α׷� ����
// ����: Assign01 �Լ��� ȣ���Ͽ� ���������� ����ϰ� ����� ����Ѵ�.
// �Է�: ����
// ���: ���������� ��� ���� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
    return Assign01();
}

// ��ɸ�: Assign01. �Է� �� �Լ� ȣ��
// ����: ����ڷκ��� ù° ��(start)�� ����(diff)�� �Է¹޾�,
//       fillCD�� �迭�� ä�� �� printArray�� ����Ѵ�.
// �Է�: ����ڷκ��� �� ������ �Է¹޴´�.
// ���: ���� ���������� �ֿܼ� ����Ѵ�.
// ����: ����
int Assign01()
{
    int result[10] = { 0 };
    int start = 0;
    int diff = 0;

    printf("�ʱⰪ ���� �Է��ϼ���: ");
    scanf("%d %d", &start, &diff);

    fillCD(result, ARR_SIZE, start, diff);
    printArray(result, ARR_SIZE);

    return 0;
}

// ��ɸ�: fillCD. �������� ���
// ����: ù° ��(start)�� ����(diff)�� �̿��� �迭�� ���������� ä���.
// �Է�: int arr[] (�迭), int size (�迭 ũ��), int start (ù° ��), int diff (����)
// ���: ����
// ����: ����
void fillCD(int arr[], int size, int start, int diff)
{
    int i;
    arr[0] = start;

    for (i = 1; i < size; i++)
        arr[i] = arr[i - 1] + diff;
}

// ��ɸ�: printArray. �迭 ���
// ����: ���޹��� �迭�� ��� ���Ҹ� �������� �����Ͽ� ����Ѵ�.
// �Է�: int arr[] (���� �迭), int size (�迭 ũ��)
// ���: �迭�� ��� ���Ҹ� �ֿܼ� ����Ѵ�.
// ����: ����
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
