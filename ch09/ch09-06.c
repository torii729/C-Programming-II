/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch09 PPT ���� 9-4 : ���ڿ� �� (strcmp)
	��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 10

/*
	��ɸ�: main. ���α׷� ������
	����: ���ڿ� �� �Լ� strcmp�� ������ �ǽ��Ѵ�.
		  �� ���ڿ��� ��������, �ٸ����� ���ϰ� ����� ����Ѵ�.
	�Է�: ���ڿ� 1�� (��й�ȣ)
	���: ���ڿ� �� ��� �� �α��� ����/���� �޽����� �ֿܼ� ����Ѵ�.
	����: ����
*/
int main(void)
{
	char s1[SIZE] = "apple"; // s1�� "apple" ����
	char s2[SIZE] = "apple"; // s2���� "apple" ����
	char password[SIZE]; // ��й�ȣ �Է� ���� �迭

	// if (s1 == s2)�� ���ڿ� ������ ������ �ʰ� '�ּ�'�� ���ϹǷ� �׻� false
	if (s1 == s2)
		printf("same address\n");

	// strcmp(s1, s2) == 0 �� �� ���ڿ� ������ ������ 0 ��ȯ
	if (strcmp(s1, s2) == 0)
		printf("same string\n");

	printf("�н�����? "); // ��й�ȣ �Է� ��û
	scanf("%s", password); // ��й�ȣ �Է� ����

	// �Էµ� password�� "abcd1234" ��
	if (strcmp(password, "abcd1234") == 0)
		printf("login succeeded\n"); // ���ڿ� ������ �α��� ����
	else
		printf("login failed\n"); // �ٸ��� �α��� ����

	return 0; // ���α׷� ����
}
