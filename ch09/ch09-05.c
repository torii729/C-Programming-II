/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch09 PPT ���� 9-3 : ���ڿ� ���� �� ��ȯ (strcpy)
	��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 32

/*
	��ɸ�: main. ���α׷� ������
	����: ���ڿ� �� ���� �Է¹޾� strcpy �Լ��� �̿��� ���� ��ȯ�ϴ� ���α׷�.
	�Է�: ���ڿ� 2�� (�������� ����)
	���: ��ȯ ���� ���� ���ڿ��� �ֿܼ� ���.
	����: ����
*/
int main(void)
{
	char str1[SIZE] = ""; // ���ڿ� 1, �ι��ڷ� �ʱ�ȭ
	char str2[SIZE] = ""; // ���ڿ� 2, �ι��ڷ� �ʱ�ȭ
	char temp[SIZE]; // ���ڿ� ��ȯ �� �ӽ� ���� ����

	printf("2���� ���ڿ�? "); // ���ڿ� �� �� �Է� ��û
	scanf("%s %s", str1, str2); // ���� �������� ���ڿ� �� �� �Է¹���
	printf("str1 = %s, str2 = %s\n", str1, str2); // �Է� Ȯ�� ���

	strcpy(temp, str1); // str1 �� temp
	strcpy(str1, str2); // str2 �� str1
	strcpy(str2, temp); // temp �� str2 (��������� ��ȯ��)

	printf("str1 = %s, str2 = %s\n", str1, str2); // ��ȯ ��� ���

	return 0; // ���α׷� ����
}
