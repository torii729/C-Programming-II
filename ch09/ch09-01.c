/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 공부 : 토큰 분리 예제(strtok_s 함수)
	날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    // 가장 먼저 문자열을 준비한다
    // '|'를 기준으로 잘라낼 것임
    char str[] = "풍길동, 29, 청주시 서원구 | date";
    char* token;
    char* context = NULL; // strtok_s에서 내부 상태를 저장하는 context 포인터

    // 원본 문자열 출력
    printf("원본 문자열: %s\n", str);
    printf("토큰들:\n");

    /*
        첫 번째 토큰을 추출한다
        strtok_s는 원본 문자열, 구분자 문자열, context 포인터를 인자로 받는다
        원본 문자열을 직접 수정하며 구분자 위치에 '\0'을 넣는다
    */
    token = strtok_s(str, "|,", &context);

    // 모든 토큰 출력
    while (token != NULL) 
    {
        // 잘려 나온 토큰 하나 출력
        printf("    토큰: %s\n", token);

        // 다음 토큰 추출
        // 첫 번째 호출 이후에는 str 대신 NULL을 넣어야 한다
        /*
            첫 번째 호출에서 str을 훼손했고, context가 어디까지 읽었는지 저장을 했기 때문에
            매번 처음부터 잘라내서 무한하게 첫 토큰만 나오는 것을 방지하기 위해 NULL 포인터를 넘긴다
        */
        token = strtok_s(NULL, "|,", &context);
    }

    return 0;
}
