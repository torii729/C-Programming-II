/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 03. �Է¹��� ���ڿ��� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ��ȯ�ϴ� ���α׷�
	��¥ : 2025.09.24
*/

// �Լ� ���� : �Է� �ϳ�, ��ȯ �ϳ�, ��� �ϳ�

void scan_char(char str[]);
void trans_char(char str[]);
void print_char(char str[]);

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[200] = { 0 };
	scan_char(str);
	trans_char(str);
	print_char(str);
	return 0;
}

void scan_char(char str[])
{
	printf("���ڿ�? ");
	fgets(str, 200, stdin);
	str[strcspn(str, "\n")] = '\0'; // asdf�� �Է��ϸ� asdf\n\0�� ����Ǳ� ������ \n�� �����Ѵ�
}

void trans_char(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
		else if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}
}

void print_char(char str[])
{
	printf("��ȯ �� : %s", str);
}
