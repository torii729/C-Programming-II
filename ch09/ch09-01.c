/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch09 PPT ���� ���� : ��ū �и� ����(strtok_s �Լ�)
	��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    // ���� ���� ���ڿ��� �غ��Ѵ�
    // '|'�� �������� �߶� ����
    char str[] = "ǳ�浿, 29, û�ֽ� ������ | date";
    char* token;
    char* context = NULL; // strtok_s���� ���� ���¸� �����ϴ� context ������

    // ���� ���ڿ� ���
    printf("���� ���ڿ�: %s\n", str);
    printf("��ū��:\n");

    /*
        ù ��° ��ū�� �����Ѵ�
        strtok_s�� ���� ���ڿ�, ������ ���ڿ�, context �����͸� ���ڷ� �޴´�
        ���� ���ڿ��� ���� �����ϸ� ������ ��ġ�� '\0'�� �ִ´�
    */
    token = strtok_s(str, "|,", &context);

    // ��� ��ū ���
    while (token != NULL) 
    {
        // �߷� ���� ��ū �ϳ� ���
        printf("    ��ū: %s\n", token);

        // ���� ��ū ����
        // ù ��° ȣ�� ���Ŀ��� str ��� NULL�� �־�� �Ѵ�
        /*
            ù ��° ȣ�⿡�� str�� �Ѽ��߰�, context�� ������ �о����� ������ �߱� ������
            �Ź� ó������ �߶󳻼� �����ϰ� ù ��ū�� ������ ���� �����ϱ� ���� NULL �����͸� �ѱ��
        */
        token = strtok_s(NULL, "|,", &context);
    }

    return 0;
}
