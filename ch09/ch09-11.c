/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch09 PPT ���� 9-9 : ���ڿ� �ٷ�� (���� ��ȯ, ���� �˻�)
    ��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // islower, toupper �Լ� ���

/*
    ��ɸ�: main. ���α׷� ������
    ����: ���ڿ� ������ ù ���ڿ� ������ �ܾ��� ù ���ڸ� �˻��Ͽ�,
          �ҹ����� ��� �빮�ڷ� ��ȯ�ϴ� ���α׷�.
    �Է�: ����
    ���: ��ȯ�� ���ڿ� ("Test String")
    ����: ����
*/
int main(void)
{
    char str[64] = ""; // ���ڿ� ����� �迭
    char* p = str; // p�� str �迭�� ���� �ּҸ� ����Ŵ

    strcpy(p, "test string"); // str �迭�� "test string" ����

    if (islower(p[0])) // ù ���ڰ� �ҹ������� �˻�
        p[0] = toupper(p[0]); // �ҹ��ڸ� �빮�ڷ� ��ȯ

    p = strrchr(p, ' '); // ������ ����(' ') ��ġ ã��

    if (islower(p[1])) // ���� ���� ���ڰ� �ҹ������� �˻�
        p[1] = toupper(p[1]); // �빮�ڷ� ��ȯ

    puts(str); // ��� ���ڿ� ���

    return 0; // ���α׷� ����
}
