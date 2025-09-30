/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-2 : 문자열 길이 구하기 (strlen, sizeof)
	날짜 : 2025.09.29
*/

#include <stdio.h> // 표준 입출력 함수 사용
#include <string.h> // 문자열 처리 함수 사용 (strlen 등)

int main(void)
{
    char s1[] = "hello"; // s1 배열에 "hello" 저장됨 ('h','e','l','l','o','\0')
    char s2[] = ""; // s2는 빈 문자열 (첫 글자가 널문자 '\0')
    int len = 0; // 문자열 길이 저장용 변수

    // strlen은 문자열의 길이를 구함 (널문자 제외)
    printf("s1의 길이: %d\n", strlen(s1)); // "hello" → 5
    printf("s2의 길이: %d\n", strlen(s2)); // "" → 0
    printf("\"bye bye\"의 길이: %d\n", strlen("bye bye")); // "bye bye" → 7

    // sizeof는 배열의 전체 크기(바이트 단위)를 반환함
    // s1은 char[6]이므로 (hello + '\0') → 6바이트
    printf("s1의 크기 : %d\n", sizeof(s1));

    // 문자열 길이를 다시 계산한다.
    len = strlen(s1);  // 현재 "hello"라서 len = 5

    if (len > 0)
    {
        s1[len - 1] = '\0'; // 마지막 글자('o') 자리에 '\0' 넣음 → 문자열 끝을 당겨옴
        // 따라서 "hell" 이 됨
    }

    // 변경된 문자열 출력
    printf("s1 = %s\n", s1); // "hell" 출력

    return 0;
}
