/*
    �й� : 202511204
    �̸� : �����
	���α׷� �� : ch09 PPT ���� 9-10 : count_space �Լ��� ����
	��¥ : 2025.09.29
*/

/*
    ���� ���� :
    const char*�� ���ڿ� ������ �������� ���ϰ� ��ȣ�ϴ� ������ �Ѵ�.
    isspace �Լ��� ����, ��, ���� �� ���� ���ڸ� �Ǻ��Ѵ�.
    �����͸� �� ĭ�� �̵���Ű�� ���ڿ� ��ü�� ��ȸ�� �� �ִ�.

    �޸� ���� :
    str �迭�� ���� ������ ���� ũ��� �Ҵ�ȴ�.
    count_space �Լ��� �Ű����� s�� str �迭�� ���� �ּҸ� �޾� ���ڿ��� �д´�.
    const �������� ���� �Լ� ���ο����� ���ڿ� ������ ������ �� ����.

    �� ����� ���� ���� :
    ���ڿ��� �б⸸ �ϴ� �Լ����� const�� ����ϸ� �������� ��������.
    isspace�� ������ ������ �̿��ϸ� �����ϰ� ���ڿ��� Ž���� �� �ִ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isspace �Լ� ���

int count_space(const char* s); // ���� ���� ������ ���� �Լ� ���� ����

int main(void)
{
    char str[64] = "this program\ttests const pointer to string\n";

    puts(str); // ���ڿ� ���
    printf("���� ������ ����: %d\n", count_space(str)); // ���� ���� ���� ���

    return 0;
}

int count_space(const char* s)
{
    int count = 0; // ���� ���� ����� ����

    while (s[0] != '\0') { // ���ڿ� ��('\0')���� �ݺ�
        if (isspace(s[0])) // ���� ���ڰ� ����, ��, �������� �˻�
            count++; // ���� ���ڸ� count ����
        s++; // ���� ���ڷ� �̵�
    }

    return count; // ���� ���� ���� ��ȯ
}
