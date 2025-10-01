/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch08 PPT ���� 8-15 : �迭�� �Է� �Ű������� ����ϴ� �Լ�
    ��¥ : 2025.09.18
*/

/*
    ���� ����:
    �迭�� �Լ��� �Ű������� ������ �� �ڵ����� �����ͷ� ��ȯ�ȴ�.
    ���� �迭 ��ü�� �Լ��� �Ѱ� ó���� �� �ִ�.
    const Ű���带 ����ϸ� ���� �迭�� �������� ���ϰ� ��ȣ�� �� �ִ�.

    �޸� ����:
    copy_array �Լ��� source �迭���� target �迭�� ���Ҹ� �����Ѵ�.
    print_array �Լ��� �迭�� ���Ҹ� ������� ����Ѵ�.
*/

#include <stdio.h>
#define SIZE 10

// ��ɸ�: main. �迭 ���� �� ��� �׽�Ʈ
// ����: x �迭�� y �迭�� �����ϰ� �� �迭�� ���� ����Ѵ�.
// �Է�: ����
// ���: �� �迭�� ����
// ����: ����
int main(void)
{
    int x[SIZE] = { 10, 20, 30, 40, 50 }; // �ʱ� ������
    int y[SIZE] = { 0 }; // 0���� �ʱ�ȭ�� �迭

    printf("x = ");
    print_array(x, SIZE); // ���� �迭 ���

    copy_array(x, y, SIZE); // x�� ������ y�� ����

    printf("y = ");
    print_array(y, SIZE); // ����� �迭 ���

    return 0; // ���� ����
}

// ��ɸ�: copy_array. �迭 ����
// ����: source �迭�� ���Ҹ� target �迭�� �����Ѵ�.
// �Է�: const int source[], int target[], int size
// ���: ����
// ����: size�� �߸��Ǹ� ���� ���� �߻� ����
void copy_array(const int source[], int target[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i]; // �� ���� ����
}

// ��ɸ�: print_array. �迭 ���
// ����: arr �迭�� ���Ҹ� ������� ����Ѵ�.
// �Է�: const int arr[], int size
// ���: ���� (�迭 ���Ҹ� �ֿܼ� ���)
// ����: ����
void print_array(const int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]); // ���� ���
    printf("\n");
}
