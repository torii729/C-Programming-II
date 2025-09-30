/*
    학번 : 202511204
    이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-7 : 문자열 토큰 분리 (strtok)
    날짜 : 2025.09.29
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char phone[] = "02-123-4567"; // 전화번호 문자열
    char* p = NULL; // 토큰을 가리킬 포인터

    p = strtok(phone, "-"); // 첫 번째 토큰 추출 ("02")
    printf("area code: %s\n", p); // 지역번호 출력

    p = strtok(NULL, "-"); // 다음 토큰 추출 ("123")
    printf("prefix: %s\n", p); // 국번 출력

    p = strtok(NULL, "-"); // 마지막 토큰 추출 ("4567")
    printf("line number: %s\n", p); // 가입자 번호 출력

    return 0;
}
