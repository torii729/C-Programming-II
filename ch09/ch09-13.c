/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch09 PPT ���� 9-11 : swap_string �Լ��� ���� �� ȣ��
    ��¥ : 2025.09.29
*/

/*
    ���� ���� :
    ���ڿ��� �迭�̹Ƿ� �ܼ� �������� ��ȯ�� �� ���� strcpy�� �̿��� �����ؾ� �Ѵ�.
    ���ڿ� ���̴� strlen���� Ȯ���� �� ������, �� ���ڸ� �����ϱ� ������ +1�� ����ؾ� �Ѵ�.
    ������ �Ű������� ���ڿ� �迭�� ���� �ּҸ� ���޹޾� �Լ� ������ ���� ������ ������ �� �ִ�.

    �޸� ���� :
    str1, str2 �迭�� main �Լ��� ���� ������ ���� ũ��� �Ҵ�ȴ�.
    swap_string �Լ� ���ο��� temp �迭�� ���ÿ� �����Ǿ� �ӽ� ���� �뵵�� ���ȴ�.
    strcpy�� �ҽ� ���ڿ��� ������ ��� �迭�� �����ϸ� �� ���ڱ��� �Բ� �����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 128

int swap_string(char* lhs, char* rhs, int size); // ���ڿ� ��ȯ �Լ� ���� ����

/*
    ��ɸ�: main. ���α׷� ������
    ����: ����ڷκ��� ���ڿ� 2���� �Է¹ް� swap_string �Լ��� ȣ���Ͽ� ���� ��ȯ�Ѵ�.
    �Է�: ���� (����� �Է�)
    ���: ��ȯ ���� ���ڿ�
    ����: ����
*/
int main(void)
{
    char str1[SIZE] = ""; // ù ��° ���ڿ� ����
    char str2[SIZE] = ""; // �� ��° ���ڿ� ����

    printf("���ڿ� 2��? ");
    scanf("%s %s", str1, str2); // ���ڿ� �Է�

    printf("str1=%s, str2=%s\n", str1, str2);
    swap_string(str1, str2, SIZE); // ���ڿ� ��ȯ
    printf("str1=%s, str2=%s\n", str1, str2);

    return 0;
}

/*
    ��ɸ�: swap_string. ���ڿ� ��ȯ
    ����: �� ���ڿ��� ������ ���� ��ȯ�Ѵ�. ���ڿ� ���̰� size�� �ʰ��ϸ� ��ȯ���� �ʴ´�.
    �Է�: char* lhs (ù ��° ���ڿ� �ּ�), char* rhs (�� ��° ���ڿ� �ּ�), int size (���� ũ��)
    ���: ���� (��ȯ������ ����/���� ���� ��ȯ)
    ����: ���ڿ� ũ�Ⱑ size�� �ʰ��� ��� ��ȯ ���� (0 ��ȯ)
*/
int swap_string(char* lhs, char* rhs, int size)
{
    int lhs_len = strlen(lhs); // lhs ����
    int rhs_len = strlen(rhs); // rhs ����
    char temp[SIZE] = ""; // �ӽ� ���� ����

    if (lhs_len + 1 > size || rhs_len + 1 > size) // ���ڿ��� ũ��
        return 0; // ����

    strcpy(temp, lhs); // lhs �� temp
    strcpy(lhs, rhs); // rhs �� lhs
    strcpy(rhs, temp); // temp �� rhs

    return 1; // ����
}
