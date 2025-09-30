/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch09 PPT ���� 9-13 : 2���� ���� �迭�� ����
    ��¥ : 2025.09.29
*/

/*
    ���� ���� :
    2���� ���� �迭�� ���ڿ� ���� ���� ���ӵ� �޸� ������ �����Ѵ�.
    ���ڿ� �񱳴� strcmp �Լ��� ����ϸ�, �� ���ڿ��� ���������� ���Ѵ�.
    ���ڿ� ��ȯ�� �ܼ� ������ �Ұ����ϹǷ� strcpy�� �ӽ� �迭�� �̿��Ѵ�.
    ���� ���� �˰����� ����Ͽ� ������������ ���ڿ��� �����Ѵ�.

    �޸� ���� :
    books �迭�� ���� ������ ���� ũ��� �Ҵ�ȴ�.
    swap_string �Լ� ������ temp �迭�� ���ÿ� �Ҵ�Ǹ� �Լ� ���� �� �����ȴ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int swap_string(char* lhs, char* rhs, int size);

#define MAX 5
#define BUF_SZ 30

int main(void)
{
    char books[MAX][BUF_SZ] = {
        "Wonder",
        "Me before you",
        "The hunger games",
        "Twilight",
        "Harry potter",
    };
    int i, j;
    int index;

    puts("<< ���� �� >>"); // ���� �� å ���� ���
    for (i = 0; i < MAX; i++)
        puts(books[i]);

    for (i = 0; i < MAX - 1; i++) // ���� ���� ����
    {
        index = i; // ���� ��ġ�� �ּҰ� �ε����� ����
        for (j = i + 1; j < MAX; j++)
        {
            if (strcmp(books[index], books[j]) > 0) // �� ���� ���ڿ� ã��
                index = j;
        }
        if (i != index) // �ּҰ� ��ġ�� �ٲ������ ��ȯ
        {
            swap_string(books[index], books[i], BUF_SZ);
        }
    }

    puts("<< ���� �� >>"); // ���� �� å ���� ���
    for (i = 0; i < MAX; i++)
        puts(books[i]);

    return 0;
}

int swap_string(char* lhs, char* rhs, int size)
{
    int lhs_len = strlen(lhs); // lhs ���ڿ� ����
    int rhs_len = strlen(rhs); // rhs ���ڿ� ����
    char temp[BUF_SZ] = ""; // �ӽ� ���� �迭

    if (lhs_len + 1 > size || rhs_len + 1 > size) // ũ�� �ʰ� �˻�
        return 0;

    strcpy(temp, lhs); // lhs�� temp�� ����
    strcpy(lhs, rhs); // rhs�� lhs�� ����
    strcpy(rhs, temp); // temp�� rhs�� ����
    return 1; // ��ȯ ����
}
