/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 9-10 : count_space 함수의 정의
    날짜 : 2025.09.29
*/

/*
    관련 개념 :
    const char*는 문자열 내용을 변경하지 못하게 보호하는 역할을 한다.
    isspace 함수는 공백, 탭, 개행 등 공백 문자를 판별한다.
    포인터를 한 칸씩 이동시키며 문자열 전체를 순회할 수 있다.

    메모리 동작 :
    str 배열은 스택 영역에 고정 크기로 할당된다.
    count_space 함수의 매개변수 s는 str 배열의 시작 주소를 받아 문자열을 읽는다.
    const 제약으로 인해 함수 내부에서는 문자열 내용을 수정할 수 없다.

    이 방식을 쓰는 이유 :
    문자열을 읽기만 하는 함수에서 const를 사용하면 안정성이 높아진다.
    isspace와 포인터 연산을 이용하면 간결하게 문자열을 탐색할 수 있다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isspace 함수 사용

int count_space(const char* s); // 공백 문자 개수를 세는 함수 원형 선언

/*
    기능명: main. 프로그램 시작점
    내용: 문자열을 출력하고 count_space 함수를 호출하여 문자열 내 공백 문자의 개수를 출력한다.
    입력: 없음
    출력: 문자열과 공백 문자의 개수
    오류: 없음
*/
int main(void)
{
    char str[64] = "this program\ttests const pointer to string\n";

    puts(str); // 문자열 출력
    printf("공백 문자의 개수: %d\n", count_space(str)); // 공백 문자 개수 출력

    return 0;
}

/*
    기능명: count_space. 문자열 내 공백 문자 개수 세기
    내용: const char*로 전달된 문자열을 읽으며, isspace로 공백 문자를 판별하여 개수를 센다.
    입력: const char* s (문자열 주소)
    출력: 없음 (반환값으로 공백 문자의 개수 반환)
    오류: 없음
*/
int count_space(const char* s)
{
    int count = 0; // 공백 개수 저장용 변수

    while (s[0] != '\0') { // 문자열 끝('\0')까지 반복
        if (isspace(s[0])) // 공백 문자인 경우
            count++; // 개수 증가
        s++; // 다음 문자로 이동
    }

    return count; // 공백 문자 개수 반환
}
