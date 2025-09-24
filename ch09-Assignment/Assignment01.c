/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 01. 한 줄의 문자열을 입력받아서 공백 문자의 개수를 세는 프로그램
	날짜 : 2025.09.24
*/

// 입력받는거 하나, 세는거 하나, 출력하는거 하나

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
	printf("입력 : ");
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
	printf("공백 문자의 개수 : %d", count);
}