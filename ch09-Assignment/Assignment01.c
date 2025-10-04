/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 01. 한 줄의 문자열을 입력받아서 공백 문자의 개수를 세는 프로그램
	날짜 : 2025.09.24
*/

#include <stdio.h>
#include <string.h>

void scan_char(char str[]);
int count_char(char str[]);
void print_char(int cnt);

/*
	기능명: main. 프로그램 시작점
	내용: 문자열을 입력받아 공백 문자의 개수를 세고 출력한다.
	입력: 없음
	출력: 문자열 입력 후 공백 문자 개수를 콘솔에 출력한다.
	오류: 없음
*/
int main(void)
{
	char str[200];

	scan_char(str); // 문자열 입력
	int cnt = count_char(str); // 공백 개수 계산
	print_char(cnt); // 결과 출력

	return 0;
}

/*
	기능명: scan_char. 문자열 입력 함수
	내용: 표준 입력으로부터 문자열 한 줄을 입력받아 개행 문자 제거 후 저장한다.
	입력: char str[] (입력받은 문자열을 저장할 배열)
	출력: 없음 (입력된 문자열이 str에 저장됨)
	오류: 없음
*/
void scan_char(char str[])
{
	printf("입력 : ");
	fgets(str, 200, stdin); // 문자열 입력 (공백 포함)
	str[strcspn(str, "\n")] = '\0'; // 개행 문자 제거
}

/*
	기능명: count_char. 공백 문자 개수 세기
	내용: 문자열 내에서 공백, 탭, 개행 등 공백 문자의 개수를 센다.
	입력: char str[] (대상 문자열)
	출력: int (공백 문자 개수)
	오류: 없음
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
			count++; // 공백 문자일 경우 개수 증가
		}
	}
	return count;
}

/*
	기능명: print_char. 공백 문자 개수 출력
	내용: count_char 함수로 계산된 공백 문자 개수를 콘솔에 출력한다.
	입력: int count (공백 문자 개수)
	출력: 없음 (결과를 화면에 출력)
	오류: 없음
*/
void print_char(int count)
{
	printf("공백 문자의 개수 : %d", count);
}
