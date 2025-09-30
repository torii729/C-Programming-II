/*
    학번 : 202511204
    이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-8 : 문자열 입출력 (gets, puts, sprintf)
    날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char in_str[128];  // 입력받을 문자열 저장용 배열
    char out_str[128]; // 출력용 문자열 저장 배열
    int hour = 12, min = 30, sec = 45; // 시간 데이터 초기화

    printf("문자열? ");
    gets_s(in_str, sizeof(in_str)); // 문자열 입력 (공백 포함 가능, 안전 버전)
    puts(in_str); // 입력받은 문자열을 화면에 출력

    sprintf(out_str, "%02d:%02d:%02d", hour, min, sec); // 형식화된 문자열 생성 (시:분:초)
    puts(out_str); // 생성된 문자열 출력

    return 0;
}
