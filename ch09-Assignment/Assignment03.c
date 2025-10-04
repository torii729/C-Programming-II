/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 03. 입력받은 문자열의 소문자는 대문자로, 대문자는 소문자로 변환하는 프로그램
	날짜 : 2025.09.24
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void scan_char(char str[]);
void trans_char(char str[]);
void print_char(char str[]);

/*
	기능명: main. 프로그램 시작점
	내용: 문자열을 입력받아 대소문자를 서로 변환한 후 결과를 출력한다.
	입력: 없음
	출력: 변환된 문자열을 콘솔에 출력한다.
	오류: 없음
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
	기능명: scan_char. 문자열 입력 함수
	내용: 사용자로부터 문자열을 입력받아 개행 문자를 제거하고 저장한다.
	입력: char str[] (입력받은 문자열을 저장할 배열)
	출력: 없음 (입력된 문자열이 str에 저장됨)
	오류: 없음
*/
void scan_char(char str[])
{
	printf("문자열? ");
	fgets(str, 200, stdin);
	str[strcspn(str, "\n")] = '\0'; // 입력 시 개행 문자 제거
}

/*
	기능명: trans_char. 대소문자 변환 함수
	내용: 문자열의 각 문자를 검사하여 소문자는 대문자로, 대문자는 소문자로 변환한다.
	입력: char str[] (변환할 문자열)
	출력: 없음 (변환된 문자열이 str에 반영됨)
	오류: 없음
*/
void trans_char(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i])) // 소문자면 대문자로
			str[i] = toupper(str[i]);
		else if (isupper(str[i])) // 대문자면 소문자로
			str[i] = tolower(str[i]);
	}
}

/*
	기능명: print_char. 문자열 출력 함수
	내용: 변환된 문자열을 콘솔에 출력한다.
	입력: char str[] (출력할 문자열)
	출력: 없음 (결과를 화면에 출력)
	오류: 없음
*/
void print_char(char str[])
{
	printf("변환 후 : %s", str);
}
