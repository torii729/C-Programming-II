/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 12. 선택받은 문자열에 대하여 이동할 글자 수를 입력받아 왼쪽 또는 오른쪽으로 회전한 결과를 출력
        예시 -> abcdef를 오른쪽으로 2글자 회전하면 efabcd (글자 수가 음수면 왼쪽, 양수면 오른쪽, 이동할 글자수 0 입력 시 종료)
    날짜 : 2025.09.28
*/

#include <stdio.h>
#include <string.h>

// 함수 선언
void reverse(char* str, int start, int end);
void rotate(char* str, int k);
void input_string(char* str);
void process_rotation(char* str);

// 메인 함수
int main(void)
{
    char str[100];

    input_string(str); // 문자열 입력 받음
    process_rotation(str);  // 회전 처리 시작

    return 0;
}

// 문자열 일부 뒤집기
void reverse(char* str, int start, int end)
{
    while (start < end)
    {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        start++;
        end--;
    }
}

// 문자열 회전
void rotate(char* str, int k)
{
    int len = strlen(str);
    if (len == 0) return;

    k = (k % len + len) % len; // 음수도 처리

    reverse(str, 0, len - 1);
    reverse(str, 0, k - 1);
    reverse(str, k, len - 1);
}

// 문자열 입력 받기
void input_string(char* str)
{
    printf("문자열? ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // 개행 제거
}

// 회전 실행 및 출력
void process_rotation(char* str)
{
    int k;
    while (1)
    {
        printf("이동할 글자수? ");
        scanf_s("%d", &k);

        if (k == 0) break;

        rotate(str, k);
        printf("%s\n", str);
    }
}
