/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 03. �Է¹��� ���ڿ��� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ��ȯ�ϴ� ���α׷�
	��¥ : 2025.09.24
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void scan_char(char str[]);
void trans_char(char str[]);
void print_char(char str[]);

/*
	��ɸ�: main. ���α׷� ������
	����: ���ڿ��� �Է¹޾� ��ҹ��ڸ� ���� ��ȯ�� �� ����� ����Ѵ�.
	�Է�: ����
	���: ��ȯ�� ���ڿ��� �ֿܼ� ����Ѵ�.
	����: ����
*/
int main(void)
{
	char str[200] = { 0 };
	scan_char(str);
	trans_char(str);
	print_char(str);
	return 0;
}

/*
	��ɸ�: scan_char. ���ڿ� �Է� �Լ�
	����: ����ڷκ��� ���ڿ��� �Է¹޾� ���� ���ڸ� �����ϰ� �����Ѵ�.
	�Է�: char str[] (�Է¹��� ���ڿ��� ������ �迭)
	���: ���� (�Էµ� ���ڿ��� str�� �����)
	����: ����
*/
void scan_char(char str[])
{
	printf("���ڿ�? ");
	fgets(str, 200, stdin);
	str[strcspn(str, "\n")] = '\0'; // �Է� �� ���� ���� ����
}

/*
	��ɸ�: trans_char. ��ҹ��� ��ȯ �Լ�
	����: ���ڿ��� �� ���ڸ� �˻��Ͽ� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ��ȯ�Ѵ�.
	�Է�: char str[] (��ȯ�� ���ڿ�)
	���: ���� (��ȯ�� ���ڿ��� str�� �ݿ���)
	����: ����
*/
void trans_char(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i])) // �ҹ��ڸ� �빮�ڷ�
			str[i] = toupper(str[i]);
		else if (isupper(str[i])) // �빮�ڸ� �ҹ��ڷ�
			str[i] = tolower(str[i]);
	}
}

/*
	��ɸ�: print_char. ���ڿ� ��� �Լ�
	����: ��ȯ�� ���ڿ��� �ֿܼ� ����Ѵ�.
	�Է�: char str[] (����� ���ڿ�)
	���: ���� (����� ȭ�鿡 ���)
	����: ����
*/
void print_char(char str[])
{
	printf("��ȯ �� : %s", str);
}
