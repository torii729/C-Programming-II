/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 01. �� ���� ���ڿ��� �Է¹޾Ƽ� ���� ������ ������ ���� ���α׷�
	��¥ : 2025.09.24
*/

#include <stdio.h>
#include <string.h>

void scan_char(char str[]);
int count_char(char str[]);
void print_char(int cnt);

/*
	��ɸ�: main. ���α׷� ������
	����: ���ڿ��� �Է¹޾� ���� ������ ������ ���� ����Ѵ�.
	�Է�: ����
	���: ���ڿ� �Է� �� ���� ���� ������ �ֿܼ� ����Ѵ�.
	����: ����
*/
int main(void)
{
	char str[200];

	scan_char(str); // ���ڿ� �Է�
	int cnt = count_char(str); // ���� ���� ���
	print_char(cnt); // ��� ���

	return 0;
}

/*
	��ɸ�: scan_char. ���ڿ� �Է� �Լ�
	����: ǥ�� �Է����κ��� ���ڿ� �� ���� �Է¹޾� ���� ���� ���� �� �����Ѵ�.
	�Է�: char str[] (�Է¹��� ���ڿ��� ������ �迭)
	���: ���� (�Էµ� ���ڿ��� str�� �����)
	����: ����
*/
void scan_char(char str[])
{
	printf("�Է� : ");
	fgets(str, 200, stdin); // ���ڿ� �Է� (���� ����)
	str[strcspn(str, "\n")] = '\0'; // ���� ���� ����
}

/*
	��ɸ�: count_char. ���� ���� ���� ����
	����: ���ڿ� ������ ����, ��, ���� �� ���� ������ ������ ����.
	�Է�: char str[] (��� ���ڿ�)
	���: int (���� ���� ����)
	����: ����
*/
int count_char(char str[])
{
	int count = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		char ch = str[i];
		if (ch == ' ' || ch == '\t' || ch == '\n' ||
			ch == '\f' || ch == '\r' || ch == '\v')
		{
			count++; // ���� ������ ��� ���� ����
		}
	}
	return count;
}

/*
	��ɸ�: print_char. ���� ���� ���� ���
	����: count_char �Լ��� ���� ���� ���� ������ �ֿܼ� ����Ѵ�.
	�Է�: int count (���� ���� ����)
	���: ���� (����� ȭ�鿡 ���)
	����: ����
*/
void print_char(int count)
{
	printf("���� ������ ���� : %d", count);
}
