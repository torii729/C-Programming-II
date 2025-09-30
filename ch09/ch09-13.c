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

int main(void)
{
    char str1[SIZE] = ""; // ù ��° ���ڿ� ������ �迭
    char str2[SIZE] = ""; // �� ��° ���ڿ� ������ �迭

    printf("���ڿ� 2��? "); // ���ڿ� 2�� �Է� �ȳ�
    scanf("%s %s", str1, str2); // ���ڿ� 2�� �Է¹���

    printf("str1=%s, str2=%s\n", str1, str2); // �Էµ� ���ڿ� ���
    swap_string(str1, str2, SIZE); // �� ���ڿ� ��ȯ
    printf("str1=%s, str2=%s\n", str1, str2); // ��ȯ�� ��� ���

    return 0;
}

int swap_string(char* lhs, char* rhs, int size)
{
    int lhs_len = strlen(lhs); // lhs ���ڿ� ����
    int rhs_len = strlen(rhs); // rhs ���ڿ� ����
    char temp[SIZE] = ""; // �ӽ� ���� �迭

    if (lhs_len + 1 > size || rhs_len + 1 > size) // ���ڿ��� size���� ũ�� ��ȯ �Ұ�
        return 0; // swap ����

    strcpy(temp, lhs); // lhs�� temp�� ����
    strcpy(lhs, rhs); // rhs�� lhs�� ����
    strcpy(rhs, temp); // temp�� rhs�� ����

    return 1; // swap ����
}
