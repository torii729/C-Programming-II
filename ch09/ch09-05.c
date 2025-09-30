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

int main(void)
{
    char str1[SIZE] = ""; // 문자열 1, 널문자로 초기화
    char str2[SIZE] = ""; // 문자열 2, 널문자로 초기화
    char temp[SIZE]; // 문자열 교환할 때 임시 저장 공간

    printf("2개의 문자열? "); // 문자열 두 개 입력하라고 안내
    scanf("%s %s", str1, str2); // 공백으로 구분해서 문자열 두 개 입력받음
    printf("str1 = %s, str2 = %s\n", str1, str2);  // 입력된 문자열 확인 출력

    strcpy(temp, str1); // str1을 temp에 복사
    strcpy(str1, str2); // str2를 str1에 복사
    strcpy(str2, temp); // temp를 str2에 복사 (결국 str1, str2 swap됨)

    printf("str1 = %s, str2 = %s\n", str1, str2); // 교환된 문자열 출력

    return 0; // 프로그램 종료
}
