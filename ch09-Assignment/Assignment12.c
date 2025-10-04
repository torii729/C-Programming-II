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

// 기능명: main. 문자열 회전 프로그램 실행
// 내용: 문자열을 입력받아 회전 기능을 수행하는 process_rotation 함수를 호출한다.
// 입력: 없음
// 출력: 회전된 문자열을 콘솔에 출력한다.
// 오류: 없음
int main(void)
{
    char str[100];

    input_string(str); // 문자열 입력 받음
    process_rotation(str); // 회전 처리 시작

    return 0;
}

// 기능명: input_string. 문자열 입력
// 내용: 사용자로부터 문자열을 입력받고 개행 문자를 제거한다.
// 입력: char* str (문자열 배열)
// 출력: 없음
// 오류: 없음
void input_string(char* str)
{
    printf("문자열? ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // 엔터 제거
}

// 기능명: process_rotation. 회전 실행 및 출력
// 내용: 이동할 글자 수를 입력받아 rotate 함수를 호출하고 결과를 출력한다.
// 입력: char* str (입력 문자열)
// 출력: 회전된 문자열을 콘솔에 출력한다.
// 오류: 없음
void process_rotation(char* str)
{
    int k = 0;
    while (1)
    {
        printf("이동할 글자수? ");
        scanf_s("%d", &k);

        if (k == 0)
        {
            break;
        }

        rotate(str, k);
        printf("%s\n", str);
    }
}

// 기능명: rotate. 문자열 회전
// 내용: 입력받은 k값을 이용해 문자열을 왼쪽 또는 오른쪽으로 회전시킨다.
// 입력: char* str (문자열), int k (이동할 글자 수)
// 출력: 없음
// 오류: 없음
void rotate(char* str, int k)
{
    int len = strlen(str);
    if (len == 0)
    {
        return;
    }

    /*
        k를 len으로 나눈 나머지를 구해야 한다
        len = 5라고 가정했을 때
        5번 돌리면 원상태와 똑같고
        6번 돌리면 1번 돌린 것과 같다
        즉 k를 len으로 나눈 나머지만큼만 하면 된다
        그리고 배열 범위를 벗어나는 것을 방지하기 위함도 있다

        음수를 양수로 바꿨다
        k = -2라고 가정했을 때
        오른쪽으로 3칸 돌리는 것과 왼쪽으로 2칸 돌리는 것이 결과가 같다
        오른쪽 회전만 처리하게 하려고 음수를 양수로 바꾸는 것
    */
    k = k % len; // 일단 나머지를 만듦

    if (k < 0)
    {
        k = k + len; // 음수면 양수로 바꿔줌
    }

    // 문자열의 처음부터 끝까지 전부 뒤집으라는 의미로 매개변수를 보낸다
    // len 그대로 넣으면 널문자까지 건드리므로 -1을 한다
    reverse(str, 0, len - 1);
    reverse(str, 0, k - 1);
    reverse(str, k, len - 1);
}

// 기능명: reverse. 문자열 뒤집기
// 내용: 지정된 구간의 문자를 서로 교환하여 역순으로 만든다.
// 입력: char* str (문자열), int start (시작 인덱스), int end (끝 인덱스)
// 출력: 없음
// 오류: 없음
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
