/*
    학번 : 202511204
    이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-10 : count_space 함수의 정의
	날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isspace 함수 사용

int count_space(const char* s); // 공백 문자 개수를 세는 함수 원형 선언

int main(void)
{
    char str[64] = "this program\ttests const pointer to string\n";
    // 문자열 (탭, 개행 포함)

    puts(str); // 문자열 출력
    printf("공백 문자의 개수: %d\n", count_space(str));
    // count_space 함수 호출 → 공백 문자 개수 출력

    return 0;
}

int count_space(const char* s) // s는 입력 문자열 (const 포인터 → 값 변경 불가)
{
    int count = 0; // 공백 개수 저장용 변수

    while (s[0] != '\0') { // 문자열 끝('\0')까지 반복
        if (isspace(s[0])) // 현재 문자가 공백/탭/개행인지 검사
            count++; // 공백 문자면 count 증가
        s++; // 다음 문자로 이동
    }

    /*
        s[0] = 'A';는 const 포인터이므로 문자열 수정 불가 (컴파일 에러)
        strcpy(s, "xyz");는 매개변수 타입이 const char*라서 strcpy 불가능
    */

    return count; // 공백 문자 개수 반환
}
