/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch09 PPT ���� 9-8 : ���ڿ� ����� (gets, puts, sprintf)
    ��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    ��ɸ�: main. ���α׷� ������
    ����: gets_s, puts, sprintf �Լ��� �̿��� ���ڿ��� �Է¹ް� ����ϸ�,
          ����ȭ�� ���ڿ��� �����ϴ� ����� �ǽ��Ѵ�.
    �Է�: ���ڿ� 1�� (���� ���� ����)
    ���: �Է¹��� ���ڿ� �� �ð� ������ ���ڿ�
    ����: ����
*/
int main(void)
{
    char in_str[128];  // �Է¹��� ���ڿ� ����
    char out_str[128]; // ��¿� ���ڿ� ����
    int hour = 12, min = 30, sec = 45; // �ð� ������ �ʱ�ȭ

    printf("���ڿ�? ");
    gets_s(in_str, sizeof(in_str)); // ���ڿ� �Է�
    puts(in_str); // �Է¹��� ���ڿ� ���

    sprintf(out_str, "%02d:%02d:%02d", hour, min, sec); // ����ȭ�� ���ڿ� ����
    puts(out_str); // ������ ���ڿ� ���

    return 0; // ���α׷� ����
}
