/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 9-9 : 문자열 다루기 (문자 변환, 문자 검사)
    날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // islower, toupper 함수 사용

/*
    기능명: main. 프로그램 시작점
    내용: 문자열 내에서 첫 글자와 마지막 단어의 첫 글자를 검사하여,
          소문자일 경우 대문자로 변환하는 프로그램.
    입력: 없음
    출력: 변환된 문자열 ("Test String")
    오류: 없음
*/
int main(void)
{
    char str[64] = ""; // 문자열 저장용 배열
    char* p = str; // p는 str 배열의 시작 주소를 가리킴

    strcpy(p, "test string"); // str 배열에 "test string" 복사

    if (islower(p[0])) // 첫 글자가 소문자인지 검사
        p[0] = toupper(p[0]); // 소문자면 대문자로 변환

    p = strrchr(p, ' '); // 마지막 공백(' ') 위치 찾기

    if (islower(p[1])) // 공백 다음 문자가 소문자인지 검사
        p[1] = toupper(p[1]); // 대문자로 변환

    puts(str); // 결과 문자열 출력

    return 0; // 프로그램 종료
}
