/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : 14. ���� ��� ���α׷����� ��� ��Ͽ� �ִ� ����� ������ ������ �ڼ��� ���� ����� �ִ�.
        �� ���� ���ó�� ũ�Ⱑ 10�� ������ �迭�� ���Ҹ� ������ ������ �ڼ��� ���α׷��� �ۼ��Ͻÿ�.
        ũ�Ⱑ 10�� ������ �迭�� 0~99������ ������ ������ ä���� �׽�Ʈ�Ѵ�.
    ��¥ : 2025.09.16
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int arr[], int size);
void printArray(int arr[], int size);
void shuffleArray(int arr[], int size);

// ��ɸ�: main. ���α׷��� ������
// ����: �迭�� �����ϰ� ������ �ʱ�ȭ�� ��, ���� ������ ����� ����Ѵ�.
// �Է�: ����
// ���: ���� ������ �迭 ���¸� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
    int arr[10] = { 0 };
    srand(time(NULL)); // ���� �ø��� �ٸ� ������ �߻���Ű�� ���� �õ� ����

    initArray(arr, 10);
    printf("���� �� ��� : ");
    printArray(arr, 10);

    shuffleArray(arr, 10);
    printf("���� �� ��� : ");
    printArray(arr, 10);

    return 0;
}

// ��ɸ�: initArray. �迭 �ʱ�ȭ
// ����: �迭�� �� ���Ҹ� 0~99 ������ ������ ä���.
// �Է�: int arr[] (�迭), int size (�迭 ũ��)
// ���: ���� (�迭 ���� ���� �����)
// ����: ����
void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

// ��ɸ�: printArray. �迭 ���
// ����: �迭�� ���Ҹ� ������� �� �ٿ� ����Ѵ�.
// �Է�: int arr[] (�迭), int size (�迭 ũ��)
// ���: �迭�� ���� �ֿܼ� ����Ѵ�.
// ����: ����
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ��ɸ�: shuffleArray. �迭 ���� ����
// ����: ���� �ε����� �̿��Ͽ� �迭�� ���Ҹ� �������� ��ȯ�Ѵ�.
// �Է�: int arr[] (�迭), int size (�迭 ũ��)
// ���: ���� (�迭 ���� ������ �����)
// ����: ����
void shuffleArray(int arr[], int size)
{
    for (int i = 0; i < 100; i++)
    {
        int a = rand() % size;
        int b = rand() % size;

        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
