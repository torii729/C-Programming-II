/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 03. 입력받은 문자열의 소문자는 대문자로, 대문자는 소문자로 변환하는 프로그램
	날짜 : 2025.09.24
*/

// 함수 구상 : 입력 하나, 변환 하나, 출력 하나

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
	printf("문자열? ");
	fgets(str, 200, stdin);
	str[strcspn(str, "\n")] = '\0'; // asdf을 입력하면 asdf\n\0로 저장되기 때문에 \n을 빼야한다
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
	printf("변환 후 : %s", str);
}
