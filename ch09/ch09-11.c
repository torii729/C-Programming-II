/*
    학번 : 202511204
    이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-9 : 문자열 다루기 (문자 변환, 문자 검사)
    날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // islower, toupper

int main(void)
{
    char str[64] = ""; // 문자열 저장할 배열
    char* p = str; // p는 str 배열의 시작 주소를 가리킴

    strcpy(p, "test string"); // p가 가리키는 str 배열에 "test string" 복사

    if (islower(p[0])) // str[0] (첫 글자)이 소문자인지 검사
        p[0] = toupper(p[0]); // 소문자라면 대문자로 변환

    p = strrchr(p, ' '); // 문자열에서 마지막 ' ' (공백) 위치를 찾음
    // p는 그 공백 문자를 가리키게 됨

    // 공백 다음 문자가 소문자라면 대문자로 변환
    if (islower(p[1]))
        p[1] = toupper(p[1]);

    puts(str); // 최종 문자열 출력

    return 0;
}
