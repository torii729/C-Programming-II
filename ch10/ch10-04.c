/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch10 PPT ���� 10-2 : ����ü ������ ���� �� ���
    ��¥ : 2025.09.30
*/

/*
    ���� ����:
    ����ü�� ���� �ٸ� �ڷ����� �ϳ��� ���� �ٷ� �� �ִ� ����� ���� �ڷ����̴�.
    ����ü ������ ����� ���ÿ� �ʱ�ȭ�� �� ������, �� �����ڸ� ���� ����� �����Ѵ�.
    strcpy ���� �Լ��� ����� ���ڿ� ����� ���� ������ �� �ִ�.
    scanf�� �̿��ϸ� ����ü ����� ���� �Է��� ���� ���� �ִ�.

    �޸� ����:
    struct contact�� name�� phone�� char �迭��, ringtone�� int�� ������.
    ����ü ������ ���ÿ� �����Ǹ�, �� ����� ����ü ���ο��� ���ӵ� ������ ��ġ�ȴ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct contact
{
    char name[20]; // �̸�
    char phone[20]; // ��ȭ��ȣ
    int ringtone; // ���Ҹ�
};

// ��ɸ�: main. ����ü ���� ���� �� ��� ����
// ����: ����ü contact�� ����, �ʱ�ȭ, �Է� �� ��� ������ ���� ����ü ������ �ǽ��Ѵ�.
// �Է�: ����ڷκ��� �̸�, ��ȭ��ȣ, ���Ҹ� ��ȣ�� �Է¹޴´�.
// ���: �� ����ü ������ ��� ���� �ֿܼ� ����Ѵ�.
// ����: ����

int main(void)
{
    struct contact ct = { "ȫ�浿", "010-1234-5678", 1 }; // ����� ���ÿ� �ʱ�ȭ
    struct contact ct1 = { 0 }, ct2 = { 0 }; // ��� 0���� �ʱ�ȭ

    ct.ringtone = 5; // ��� �� ����
    strcpy(ct.phone, "010-1234-1234"); // ���ڿ� ����
    printf("�̸� : %s\n", ct.name);
    printf("��ȭ��ȣ : %s\n", ct.phone);
    printf("���Ҹ� : %d\n", ct.ringtone);

    strcpy(ct1.name, "��ö��");
    strcpy(ct1.phone, "010-5678-5678");
    ct1.ringtone = 1;
    printf("�̸� : %s\n", ct1.name);
    printf("��ȭ��ȣ : %s\n", ct1.phone);
    printf("���Ҹ� : %d\n", ct1.ringtone);

    printf("�̸� �Է� : ");
    scanf("%s", ct2.name);
    printf("��ȭ��ȣ �Է� : ");
    scanf("%s", ct2.phone);
    printf("���Ҹ� �Է�(0~9) : ");
    scanf("%d", &ct2.ringtone);

    printf("�̸� : %s\n", ct2.name);
    printf("��ȭ��ȣ : %s\n", ct2.phone);
    printf("���Ҹ� : %d\n", ct2.ringtone);

    return 0;
}
