/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� 7-11 : ���� ����
    ��¥ : 2025.09.15
*/

/*
    ���� ����:
    ���� ������ �迭���� ���� ����(�Ǵ� ū,) ���� �����Ͽ�
    ���ʺ��� ���ʴ�� ��ȯ�ϴ� ������� �����Ѵ�.
    ��ü�� �� Ȯ������ �ʰ�, ��ȯ Ƚ���� ���� �� �ִٴ� Ư¡�� �ִ�.

    �޸� ����:
    �迭 data�� ���ӵ� �޸� ������ ����ȴ�.
    index�� ���� �������� ���� ���� ���� ���� ��ġ�� ����ϰ�,
    temp�� �̿��� �� ���� ���� ��ȯ�Ѵ�.
*/

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int data[SIZE] = { 7, 3, 9, 5, 1 }; // ������ �迭
    int i, j;
    int index, temp;

    for (i = 0; i < SIZE - 1; i++) {
        index = i; // ���� ���� ������ ��ġ�� index�� ����
        for (j = i + 1; j < SIZE; j++) {
            if (data[index] > data[j]) // �� ���� �� ã���� index ����
                index = j;
        }
        if (i != index) { // ���� ��ġ�� index �ٸ��� ��ȯ
            temp = data[i];
            data[i] = data[index];
            data[index] = temp;
        }
    }

    printf("���� ��: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", data[i]); // ���ĵ� �迭 ���
    printf("\n");

    return 0;
}

