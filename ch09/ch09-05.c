/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-3 : 문자열 복사 및 교환 (strcpy)
	날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 32

/*
	기능명: main. 프로그램 시작점
	내용: 문자열 두 개를 입력받아 strcpy 함수를 이용해 서로 교환하는 프로그램.
	입력: 문자열 2개 (공백으로 구분)
	출력: 교환 전과 후의 문자열을 콘솔에 출력.
	오류: 없음
*/
int main(void)
{
	char str1[SIZE] = ""; // 문자열 1, 널문자로 초기화
	char str2[SIZE] = ""; // 문자열 2, 널문자로 초기화
	char temp[SIZE]; // 문자열 교환 시 임시 저장 공간

	printf("2개의 문자열? "); // 문자열 두 개 입력 요청
	scanf("%s %s", str1, str2); // 공백 기준으로 문자열 두 개 입력받음
	printf("str1 = %s, str2 = %s\n", str1, str2); // 입력 확인 출력

	strcpy(temp, str1); // str1 → temp
	strcpy(str1, str2); // str2 → str1
	strcpy(str2, temp); // temp → str2 (결과적으로 교환됨)

	printf("str1 = %s, str2 = %s\n", str1, str2); // 교환 결과 출력

	return 0; // 프로그램 종료
}
