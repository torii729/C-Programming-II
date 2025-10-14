/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch10 PPT ���� 10-6 : ����ü �迭�� �˻�
    ��¥ : 2025.10.01
*/

/*
    ���� ����:
    ����ü �迭�� ���� ���� ����ü�� ���ӵ� �޸𸮿� �����Ѵ�.
    ���ڿ� �񱳴� strcmp �Լ��� ����ؾ� �ϸ�, ������ 0�� ��ȯ�Ѵ�.
    Ž���� �������� ���� ����� ������ ���� index�� ������ 0 �Ǵ� -1, 1 ���� �����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define STR_SIZE 20

typedef struct contact {
    char name[STR_SIZE]; // �̸�
    char phone[STR_SIZE]; // ��ȭ��ȣ
    int ringtone; // ���Ҹ� ��ȣ
} Contact;

// ��ɸ�: main. ����ü �迭 �˻� ����
// ����: ����ü �迭���� �̸��� �Է¹޾� �ش� ����ó ������ Ž���ϰ� ����Ѵ�.
// �Է�: ����ڷκ��� �˻��� �̸� �Է�
// ���: �̸��� �����ϸ� ��ȭ��ȣ ���, ������ �ȳ� �޽��� ���
// ����: ����

int main(void)
{
    Contact arr[] = {
        {"Alice", "010-1111-1111", 1},
        {"Bob", "010-2222-2222", 2},
        {"Charlie", "010-3333-3333", 3},
        {"David", "010-4444-4444", 4},
        {"Eve", "010-5555-5555", 5},
        {"Frank", "010-6666-6666", 6},
        {"Grace", "010-7777-7777", 7}
    };

    int size = sizeof(arr) / sizeof(arr[0]); // �迭 ���� ����
    int i;
    char name[STR_SIZE]; // �˻��� �̸�
    int index;

    printf("�̸�? ");
    scanf("%s", name); // �̸� �Է�

    index = -1; // �� ã�� ��� ���
    for (i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, name) == 0) // �̸� ��
        {
            index = i; // ã�� ��ġ ����
            break; // �� �̻� Ž������ ����
        }
    }

    if (index >= 0)
    {
        printf("%s�� ��ȭ��ȣ : %s\n", arr[index].name, arr[index].phone); // ã�� ��� ���
    }
    else
    {
        printf("ã�� �̸��� �����ϴ�.\n"); // �� ã�� ��� ���
    }

    return 0;
}
