/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 공부 : 토큰 분리 예제(strtok_s 함수)
	날짜 : 2025.09.29
*/

/*
    관련 개념 :
    strtok_s 함수는 문자열을 지정된 구분자로 분리하며, thread-safe하게 동작하기 위해 context 포인터를 사용한다.
    구분자가 발견되면 해당 위치에 '\0'을 삽입하여 원본 문자열을 직접 수정한다.
    첫 번째 호출 이후에는 NULL을 전달하여 context 포인터가 이어서 문자열을 잘라내도록 해야 한다.

    메모리 동작 :
    str 배열은 스택에 저장되며, strtok_s 호출 시 내부적으로 '\0'으로 수정된다.
    context 포인터는 strtok_s가 현재 어디까지 읽었는지 상태를 저장한다.
    token 포인터는 잘려 나온 각 토큰의 시작 주소를 가리킨다.

    이 방식을 쓰는 이유 :
    단순 strtok은 thread-safe하지 않지만 strtok_s는 context 포인터를 별도로 관리하므로 안전하다.
    문자열을 구분자로 나누어 처리하는 실습에서 strtok_s를 사용하면 문자열 분리 과정을 명확하게 학습할 수 있다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "풍길동, 29, 청주시 서원구 | date"; // 분리할 원본 문자열
    char* token; // 잘라낸 토큰을 가리킬 포인터
    char* context = NULL; // strtok_s의 내부 상태를 저장할 포인터

    printf("원본 문자열: %s\n", str); // 원본 문자열 출력
    printf("토큰들:\n");

    token = strtok_s(str, "|,", &context); // 첫 번째 토큰 추출

    while (token != NULL)
    {
        printf("    토큰: %s\n", token); // 잘려 나온 토큰 출력
        token = strtok_s(NULL, "|,", &context); // 다음 토큰 추출
    }

    return 0;
}
