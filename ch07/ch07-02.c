/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� Ǯ��

    ����ü Ÿ���� �ϳ� ���Ƿ� ���� : ��) ����ó(�̸�, ��ȭ��ȣ, �޸�)
    typedef struct _contact { char name[64]; char phone1[24] } Contact;

    ����ü �迭�� ���� ���� �� �Լ��� �����ϰ�
    void printArrayContact(Contact R[], int size)
    void copyArrayContact(Contact from[], Contact to[], int size)

    Test �Լ��� �ۼ��ϰ� main ���� ȣ���Ͽ� ������ ���ÿ�
    Int test_printArrayContact()
    Int Test_copyArrayContact()

    ��¥ : 2025.09.15
*/

#include <stdio.h>
#include <string.h>
#include "struct.h"

void copyArrayContact(Contact from[], Contact to[], int size);
void printArrayContact(Contact R[], int size);
int test_copyArrayContact();
int test_printArrayContact();

// ��ɸ�: main. �׽�Ʈ ����
// ����: ����ü �迭 ��� �� ���� �׽�Ʈ �Լ��� �����Ѵ�.
// �Է�: ����
// ���: �� �׽�Ʈ ����� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
    test_printArrayContact();
    test_copyArrayContact();
    return 0;
}

// ��ɸ�: copyArrayContact. ����ü �迭 ����
// ����: from �迭�� �� ����ü ���Ҹ� to �迭�� ������� �����Ѵ�.
// �Է�: Contact from[], Contact to[], int size
// ���: ����
// ����: size�� �����̰ų� �迭 ũ�⺸�� ũ�� �߸��� ���� �߻� ����
void copyArrayContact(Contact from[], Contact to[], int size)
{
    for (int i = 0; i < size; i++)
    {
        to[i] = from[i];
    }
}

// ��ɸ�: printArrayContact. ����ü �迭 ���
// ����: R �迭�� �� ����ü ������ �̸��� ��ȭ��ȣ�� ������� ����Ѵ�.
// �Է�: Contact R[], int size
// ���: �� ����ü�� �̸��� ��ȭ��ȣ�� �ֿܼ� ����Ѵ�.
// ����: ����
void printArrayContact(Contact R[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("�̸� : %s, ��ȭ��ȣ : %s\n", R[i].name, R[i].phone1);
    }
    printf("\n");
}

// ��ɸ�: test_copyArrayContact. ����ü �迭 ���� �׽�Ʈ
// ����: ����ü �迭�� �ٸ� �迭�� �����ϰ�, ������ ���纻�� ���� ����Ѵ�.
// �Է�: ����
// ���: ���� �迭�� ����� �迭�� ������ �ֿܼ� ����Ѵ�.
// ����: ����
int test_copyArrayContact()
{
    Contact arr[2] = {
        {"�̼�", "010-1234-5678"},
        {"����", "010-9876-5432"}
    };

    Contact null[2] = { 0 };

    copyArrayContact(arr, null, 2);

    printf("���� �迭 : \n");
    printArrayContact(arr, 2);

    printf("����� �迭 : \n");
    printArrayContact(null, 2);

    return 0;
}

// ��ɸ�: test_printArrayContact. ����ü �迭 ��� �׽�Ʈ
// ����: ����ü �迭�� �����ϰ� printArrayContact �Լ��� ����Ѵ�.
// �Է�: ����
// ���: ����ü �迭�� �̸��� ��ȭ��ȣ�� �ֿܼ� ����Ѵ�.
// ����: ����
int test_printArrayContact()
{
    Contact arr[3] = {
        {"�α�", "010-1111-2222"},
        {"ö��", "010-3333-4444"},
        {"���", "010-5555-6666"}
    };

    printf("��� : \n");
    printArrayContact(arr, 3);

    return 0;
}
