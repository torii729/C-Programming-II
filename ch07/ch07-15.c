/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� 7-12 : 2���� �迭�� ���
    ��¥ : 2025.09.15
*/

/*
    ���� ����:
    2���� �迭�� ��(Row)�� ��(Col)�� ������ ǥ ������ �޸� �����̴�.
    �迭 ���Ҵ� data[i][j] ���·� �����ϸ�, ���� for������ ��ü�� �ٷ� �� �ִ�.
    sizeof ������ ���� ��ü �迭 ũ��, �� ���� ũ��, �� ������ ũ�⸦ Ȯ���� �� �ִ�.

    �޸� ����:
    int data[ROW][COL]�� ���ӵ� �޸� ������ ROW * COL ���� int�� �����Ѵ�.
    data�� �迭 ��ü�� ���� �ּ�, data[0]�� ù ��° ���� ���� �ּ�, data[0][0]�� ù ��° �����̴�.
*/

// ���, ��(����), ��(����)

#include <stdio.h>

#define ROW 3
#define COL 2

int main(void)
{
    int data[ROW][COL]; // 2���� �迭 ����
    int i, j, k;

    for (i = 0, k = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            data[i][j] = ++k; // �迭�� ���ҿ� 1�� �����ϴ� �� ����
        }
    }

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            printf("%3d ", data[i][j]); // 2���� �迭 ���� ���
        printf("\n");
    }

    printf("sizeof(data) = %d\n", sizeof(data)); // �迭 ��ü ũ��
    printf("sizeof(data[0]) = %d\n", sizeof(data[0])); // �� ���� ũ��
    printf("sizeof(data[0][0]) = %d\n", sizeof(data[0][0])); // �� ������ ũ��

    return 0;
}
