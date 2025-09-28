/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : 7. ��ȭ��ȣ ���ڿ��� �ùٸ� ������ ��ȭ��ȣ���� �˻��ϴ� check_phone_str �Լ��� �ۼ�
            ��ȭ��ȣ�� "01012345678" �������� �Է¹޴´�. ������ "010"�� �����ϴٰ� �����Ѵ�.
    ��¥ : 2025.09.28
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// �Լ� ����
int check_phone_str(const char* str);
void input_phone(char* phone);
void print_result(const char* phone);

// ���� �Լ�
int main(void)
{
    char phone[50];

    while (1)
    {
        input_phone(phone); // ��ȭ��ȣ �Է� ����
        if (strcmp(phone, ".") == 0) // �Է��ϸ� ����
        {
            break;


        }

        print_result(phone); // �˻� ��� ���
    }

    return 0;
}

// ��ȭ��ȣ ���� �˻�
int check_phone_str(const char* str)
{
    int len = strlen(str);

    if (len != 11) // ���̴� 11�ڸ����� ��
    {
        return 0;
    }

    if ((str[0] != '0') || (str[1] != '1') || (str[2] != '0')) // ���� 010�� �ƴϸ�,
    {
        return 0;
    }

    for (int i = 0; i < len; i++) // �������� ���� ����
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1; // ���� �����ϸ� ��ȿ
}

// ��ȭ��ȣ �Է� �ޱ�
void input_phone(char* phone)
{
    printf("��ȭ��ȣ(. �Է� �� ����)? ");
    gets(phone);
    phone[strcspn(phone, "\n")] = '\0'; // asdf�� �Է��ϸ� asdf\n\0�� ����Ǳ� ������ \n�� �����Ѵ�
}

// �˻� ��� ���
void print_result(const char* phone)
{
    if (check_phone_str(phone))
    {
        printf("%s�� ��ȿ�� ��ȭ��ȣ�Դϴ�.\n", phone);
    }
    else
    {
        printf("�߸� �Է��߽��ϴ�. 01012345678 �������� �Է��ϼ���.\n");
    }
}