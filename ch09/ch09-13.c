/*
    학번 : 202511204
    이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-11 : swap_string 함수의 정의 및 호출
    날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 128

int swap_string(char* lhs, char* rhs, int size); // 문자열 교환 함수 원형 선언

int main(void)
{
    char str1[SIZE] = ""; // 첫 번째 문자열 저장할 배열
    char str2[SIZE] = ""; // 두 번째 문자열 저장할 배열

    printf("문자열 2개? "); // 문자열 2개 입력 안내
    scanf("%s %s", str1, str2); // 문자열 2개 입력받음

    printf("str1=%s, str2=%s\n", str1, str2); // 입력된 문자열 출력
    swap_string(str1, str2, SIZE); // 두 문자열 교환
    printf("str1=%s, str2=%s\n", str1, str2); // 교환된 결과 출력

    return 0;
}

int swap_string(char* lhs, char* rhs, int size)
{
    int lhs_len = strlen(lhs); // lhs 문자열 길이
    int rhs_len = strlen(rhs); // rhs 문자열 길이
    char temp[SIZE] = ""; // 임시 저장 배열

    // 문자열이 size보다 크면 교환 불가 (오버플로 방지)
    if (lhs_len + 1 > size || rhs_len + 1 > size)
        return 0; // swap 실패

    strcpy(temp, lhs); // lhs → temp
    strcpy(lhs, rhs); // rhs → lhs
    strcpy(rhs, temp); // temp → rhs

    return 1; // swap 성공
}