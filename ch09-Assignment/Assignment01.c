/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 01. �� ���� ���ڿ��� �Է¹޾Ƽ� ���� ������ ������ ���� ���α׷�
	��¥ : 2025.09.24
*/

// �Է¹޴°� �ϳ�, ���°� �ϳ�, ����ϴ°� �ϳ�

#include <stdio.h>
#include <string.h>

void scan_char(char str[]);
int count_char(char str[]);
void print_char(int cnt);


int main(void)
{
	char str[200];

	scan_char(str);
	int cnt = count_char(str);
	print_char(cnt);
	return 0;
}

void scan_char(char str[])
{
	printf("�Է� : ");
	fgets(str, 200, stdin);
	str[strcspn(str, "\n")] = '\0';
}

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
			count++;
		}
	}
	return count;
}

void print_char(int count)
{
	printf("���� ������ ���� : %d", count);
}