/*
    �й� : 202511204
    �̸� : �����
	���α׷� �� : ch09 PPT ���� 9-10 : count_space �Լ��� ����
	��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isspace �Լ� ���

int count_space(const char* s); // ���� ���� ������ ���� �Լ� ���� ����

int main(void)
{
    char str[64] = "this program\ttests const pointer to string\n";
    // ���ڿ� (��, ���� ����)

    puts(str); // ���ڿ� ���
    printf("���� ������ ����: %d\n", count_space(str));
    // count_space �Լ� ȣ�� �� ���� ���� ���� ���

    return 0;
}

int count_space(const char* s) // s�� �Է� ���ڿ� (const ������ �� �� ���� �Ұ�)
{
    int count = 0; // ���� ���� ����� ����

    while (s[0] != '\0') { // ���ڿ� ��('\0')���� �ݺ�
        if (isspace(s[0])) // ���� ���ڰ� ����/��/�������� �˻�
            count++; // ���� ���ڸ� count ����
        s++; // ���� ���ڷ� �̵�
    }

    /*
        s[0] = 'A';�� const �������̹Ƿ� ���ڿ� ���� �Ұ� (������ ����)
        strcpy(s, "xyz");�� �Ű����� Ÿ���� const char*�� strcpy �Ұ���
    */

    return count; // ���� ���� ���� ��ȯ
}
