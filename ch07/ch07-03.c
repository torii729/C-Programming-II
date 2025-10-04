/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� Ǯ��

    �迭 ���� �� �ּҰ� ã�� �Լ� :
    int findMinInt(int R[], int from, int to) : from���� to���� �ּҰ��� ���� �ε��� �ϳ��� ��ȯ

    �迭�� �� ���Ҹ� ��ȯ�ϱ� :
    void swapInt(int R[], int aindex, int bindex)

    �� �Լ��� �����ϰ�, �̸� �̿��� �������� �Լ��� ����
    Int selectionSortInt(int R[], int length) : ���� 0, ���� 0�� �ƴ� ��

    �׽�Ʈ �ڵ�
    �� �����ϴ��� �����ϴ� �Լ��� �ۼ��ϰ� main���� ȣ��
    Int test_selectionSortInt(void) : ���� 0, ���� 0�� �ƴ� ��
    ������ ���� �迭�� ������ �� �����ϰ�, ���� �迭�� ���ĵ� ����� ���

    ��¥ : 2025.09.15
*/

#include <stdio.h>

int findMinInt(int R[], int from, int to);
void swapInt(int R[], int aindex, int bindex);
int selectionSortInt(int R[], int length);
int test_selectionSortInt();

// ��ɸ�: main. �׽�Ʈ ����
// ����: ���� ���� �׽�Ʈ �Լ��� �����Ѵ�.
// �Է�: ����
// ���: ���� �迭�� ���ĵ� �迭�� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
    test_selectionSortInt();
    return 0;
}

// ��ɸ�: findMinInt. �ּҰ� �ε��� ã��
// ����: �迭 R���� from���� to���� ���� �� �ּҰ��� �ε����� ã�� ��ȯ�Ѵ�.
// �Է�: int R[] (���� �迭), int from (���� �ε���), int to (�� �ε���)
// ���: �ּҰ��� ���� �ε��� ��ȣ
// ����: from�̳� to�� �迭 ������ ����� �߸��� ���� ����
int findMinInt(int R[], int from, int to)
{
    int min_Index = from;
    int i = 0;

    for (i = from + 1; i <= to; i++)
    {
        if (R[i] < R[min_Index])
        {
            min_Index = i;
        }
    }
    return min_Index;
}

// ��ɸ�: swapInt. �迭�� �� ���� ��ȯ
// ����: �迭 R�� aindex ���ҿ� bindex ������ ���� ���� �ٲ۴�.
// �Է�: int R[] (���� �迭), int aindex (ù ��° �ε���), int bindex (�� ��° �ε���)
// ���: ����
// ����: �ε����� �迭 ������ ����� �߸��� ���� ����
void swapInt(int R[], int aindex, int bindex)
{
    int temp = R[aindex];
    R[aindex] = R[bindex];
    R[bindex] = temp;
}

// ��ɸ�: selectionSortInt. ���� ����
// ����: �迭 R�� ������������ �����Ѵ�. �ּҰ��� ���ʴ�� �����Ͽ� ������ ������.
// �Է�: int R[] (���� �迭), int length (�迭 ����)
// ���: ���������� �����ϸ� 0 ��ȯ, ���� �� 0�� �ƴ� �� ��ȯ
// ����: length�� �����̰ų� �迭 ũ�⸦ �ʰ��� ��� �߸��� ���� ����
int selectionSortInt(int R[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = findMinInt(R, i, length - 1);

        if (minIndex != i)
        {
            swapInt(R, i, minIndex);
        }
    }
    return 0;
}

// ��ɸ�: test_selectionSortInt. ���� ���� �׽�Ʈ
// ����: ������ ���� �迭�� �����Ͽ� ���� ���� �Լ��� �����Ѵ�.
// �Է�: ����
// ���: ���� �迭�� ���ĵ� �迭�� �ֿܼ� ����Ѵ�.
// ����: ����
int test_selectionSortInt()
{
    int arr[8] = { 64, 25, 12, 22, 11, 90, 55, 3 };
    int length = 8;

    printf("���� �迭 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = selectionSortInt(arr, length);

    printf("���ĵ� �迭 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
