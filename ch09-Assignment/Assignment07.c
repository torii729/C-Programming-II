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

int check_phone_str(const char* str);
void input_phone(char* phone);
void print_result(const char* phone);

/*
    ��ɸ�: main. ���α׷� ������
    ����: ����ڰ� �Է��� ��ȭ��ȣ�� �˻��ϰ�, ��ȿ�� ����� ����Ѵ�.
    �Է�: ���� (����� �Է����� ��ȭ��ȣ�� ����)
    ���: �˻� ����� �ֿܼ� ���
    ����: ����
*/
int main(void)
{
    char phone[50];

    while (1)
    {
        input_phone(phone); // ��ȭ��ȣ �Է� ����
        if (strcmp(phone, ".") == 0) // "." �Է� �� ����
        {
            break;
        }

        print_result(phone); // �˻� ��� ���
    }

    return 0;
}

/*
    ��ɸ�: check_phone_str. ��ȭ��ȣ ���� �˻�
    ����: ���ڿ��� 010���� �����ϰ� �� 11�ڸ� ���ڷ� �����Ǿ� �ִ��� �˻��Ѵ�.
    �Է�: const char* str (��ȭ��ȣ ���ڿ�)
    ���: ��ȿ�ϸ� 1, �߸��� �����̸� 0 ��ȯ
    ����: ����
*/
int check_phone_str(const char* str)
{
    int len = strlen(str);

    if (len != 11) // ���̰� 11�ڸ����� Ȯ��
    {
        return 0;
    }

    if ((str[0] != '0') || (str[1] != '1') || (str[2] != '0'))
    {
        return 0;
    }

    for (int i = 0; i < len; i++) // ��� ���ڰ� �������� Ȯ��
    {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1; // ��� ���� ��� �� ��ȿ�Ѵٴ� �ǹ�
}

/*
    ��ɸ�: input_phone. ��ȭ��ȣ �Է� �Լ�
    ����: ����ڷκ��� ��ȭ��ȣ�� �Է¹޴´�. '.' �Է� �� ���α׷� ����.
    �Է�: char* phone (�Է°� ����� �迭)
    ���: ���� (�Է� ����� phone�� �����)
    ����: ����
*/
void input_phone(char* phone)
{
    printf("��ȭ��ȣ(. �Է� �� ����)? ");
    gets(phone); // ���ڿ� �Է�
    phone[strcspn(phone, "\n")] = '\0'; // �Է� �� ���Ե� ���๮�� ����
}

/*
    ��ɸ�: print_result. �˻� ��� ��� �Լ�
    ����: ��ȭ��ȣ ��ȿ���� �˻��ϰ�, �� ����� �ֿܼ� ����Ѵ�.
    �Է�: const char* phone (�Էµ� ��ȭ��ȣ)
    ���: ��ȿ ���θ� ���
    ����: ����
*/
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
