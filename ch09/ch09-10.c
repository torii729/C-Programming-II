/*
    �й� : 202511204
    �̸� : �����
	���α׷� �� : ch09 PPT ���� 9-8 : ���ڿ� ����� (gets, puts, sprintf)
    ��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char in_str[128];  // �Է¹��� ���ڿ� ����� �迭
    char out_str[128]; // ��¿� ���ڿ� ���� �迭
    int hour = 12, min = 30, sec = 45; // �ð� ������ �ʱ�ȭ

    printf("���ڿ�? ");
    gets_s(in_str, sizeof(in_str)); // ���ڿ� �Է� (���� ���� ����, ���� ����)
    puts(in_str); // �Է¹��� ���ڿ��� ȭ�鿡 ���

    sprintf(out_str, "%02d:%02d:%02d", hour, min, sec); // ����ȭ�� ���ڿ� ���� (��:��:��)
    puts(out_str); // ������ ���ڿ� ���

    return 0;
}
