/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-4 : 문자열 비교 (strcmp)
	날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 10

int main(void)
{
    char s1[SIZE] = "apple"; // s1에 "apple" 저장
    char s2[SIZE] = "apple"; // s2에도 "apple" 저장
    char password[SIZE]; // 비밀번호 입력 받을 배열

    // if (s1 == s2) → 배열 이름은 주소이다.
    // 실제 문자열 내용을 비교하지 않고 '주소'만 비교하게 됨 (의도와 다르게)
    // 따라서 strcmp 사용해야 한다.
    if (s1 == s2)
        printf("same address\n");

    // strcmp(s1, s2) == 0, 두 문자열 내용이 같으면 0 반환
    if (strcmp(s1, s2) == 0)
        printf("same string\n");

    printf("패스워드? "); // 비밀번호 입력 요청
    scanf("%s", password); // 비밀번호 입력 받음

    // 입력된 password와 "abcd1234" 비교
    if (strcmp(password, "abcd1234") == 0)
        printf("login succeeded\n"); // 문자열 같으면 로그인 성공
    else
        printf("login failed\n"); // 다르면 로그인 실패

    return 0;
}
