/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch09 PPT ���� 9-1 : ���ڿ� �ʱ�ȭ �� ���
	��¥ : 2025.09.29
*/

#include <stdio.h>

int main(void)
{
	char str1[10] = { 'a', 'b', 'c' }; // �迭�� 'a','b','c' ���� ����, �������� '\0'���� ä����
	char str2[10] = "abc"; // ���ڿ� "abc" ����� ('a','b','c','\0', �������� '\0')
	char str3[] = "abc"; // ũ�⸦ �ڵ� ���, ���� 4 ('a','b','c','\0')
	// char str4[10] = "very long string"; // ���ڿ��� �ʹ� �� �迭 ũ�� �ʰ� �� ������

	int size = sizeof(str1) / sizeof(str1[0]); // �迭 str1�� ���� ����(=10) ����
	int i;

	printf("str1 = "); // str1 ���� ���
	for (i = 0; i < size; i++)
	{
		printf("%c ", str1[i]); // str1�� �� ��Ҹ� ���ڷ� ��� (��ĭ ����)
	}
	printf("\n");

	printf("str2 = %s\n", str2); // ���ڿ� ��� (�ι��� ���� ������)
	printf("str3 = "); // str3 ��� �ȳ�
	printf(str3); // ���ڿ� �״�� ��� (printf("%s", str3)�� ����)
	printf("\n");

	// printf("str4 = %s\n", str4); // ���� ���� �ڵ�� �ּ� ó����

	return 0; // ���α׷� ����
}
