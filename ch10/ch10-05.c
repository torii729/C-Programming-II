/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch10 PPT ���� 10-3 : ����ü ���� ���� �ʱ�ȭ�� ����
	��¥ : 2025.09.30
*/

/*
    ���� ����:
    ����ü ������ ���� Ÿ�Գ��� ��°�� ������ �� �ִ�.
    �ʱ�ȭ �ÿ��� �ٸ� ����ü ������ �ʱ�ȭ�� �����ϴ�.
    ���� �������� ����ü�� ��� ��� ���� �� ���� ����ȴ�.

    �޸� ����:
    struct contact ct, ct2, ct3�� ���� ���ÿ� ���������� ����ȴ�.
    ct3 = ct2ó�� �����ϸ� ��� ���� �״�� ����ǰ�, �޸𸮸� �������� �ʴ´�.
*/

#include <stdio.h>

struct contact
{
    char name[20]; // �̸�
    char phone[20]; // ��ȭ��ȣ
    int age; // ����
};

int main(void)
{
    struct contact ct = { "Alice", "010-1234-5678", 0 };
    struct contact ct2 = { "Bob", "010-9876-5432", 1 };
    struct contact ct3 = ct2; // ����ü ������ �ʱ�ȭ
    printf("ct2���� �ʱ�ȭ ���� ct3 = %s, %s, %d\n", ct3.name, ct3.phone, ct3.age);

    ct3 = ct; // ����ü ����
    printf("ct�� ���� ���� ct3 = %s, %s, %d\n", ct3.name, ct3.phone, ct3.age);

    return 0;
}
