/*
    �й� : 202511204
    �̸� : �����
	���α׷� �� : ch09 PPT ���� 9-9 : ���ڿ� �ٷ�� (���� ��ȯ, ���� �˻�)
    ��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // islower, toupper

int main(void)
{
    char str[64] = ""; // ���ڿ� ������ �迭
    char* p = str; // p�� str �迭�� ���� �ּҸ� ����Ŵ

    strcpy(p, "test string"); // p�� ����Ű�� str �迭�� "test string" ����

    if (islower(p[0])) // str[0] (ù ����)�� �ҹ������� �˻�
        p[0] = toupper(p[0]); // �ҹ��ڶ�� �빮�ڷ� ��ȯ

    p = strrchr(p, ' '); // ���ڿ����� ������ ' ' (����) ��ġ�� ã��
    // p�� �� ���� ���ڸ� ����Ű�� ��

    // ���� ���� ���ڰ� �ҹ��ڶ�� �빮�ڷ� ��ȯ
    if (islower(p[1]))
        p[1] = toupper(p[1]);

    puts(str); // ���� ���ڿ� ���

    return 0;
}
