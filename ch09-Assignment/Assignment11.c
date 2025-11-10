/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 11. 영어 단어 끝말잇기 게임
    날짜 : 2025.11.23
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void test(void);
int is_chain_ok(const char* prev, const char* curr);
void to_lower_str(char* s);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 끝말잇기 게임을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    test();
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 단어를 반복 입력받고 끝말잇기 규칙을 검사한다.
          길이가 3 미만이면 다시 입력하게 하고
          규칙 위반 시 연속 성공 횟수를 출력하고 종료한다.
    입력: word? 프롬프트로 단어를 반복 입력받는다.
    출력: 실패 메시지와 연속 성공 횟수 출력.
    오류: 입력 실패 시 종료한다.
*/
void test(void)
{
    char prev[101] = "";
    char curr[101];
    int count;
    int ok;

    count = 0;

    while (1)
    {
        printf("word? ");
        ok = scanf_s("%100s", curr, (unsigned)_countof(curr));
        if (ok != 1)
        {
            return;
        }

        if ((int)strlen(curr) < 3)
        {
            printf("too short, try again\n");
            continue;
        }

        to_lower_str(curr);

        if (count == 0)
        {
            strcpy_s(prev, sizeof(prev), curr);
            count++;
            continue;
        }

        if (is_chain_ok(prev, curr))
        {
            strcpy_s(prev, sizeof(prev), curr);
            count++;
        }
        else
        {
            printf("WRONG WORD!!! YOU FAILED!!!\n");
            printf("count: %d\n", count);
            break;
        }
    }
}

/*
    기능명: is_chain_ok. 끝말잇기 규칙 검사
    내용: curr의 첫 글자가 prev의 마지막 글자와 같은지 검사한다.
    입력: 이전 단어, 현재 단어.
    출력: 규칙이 맞으면 1, 아니면 0.
    오류: 없음
*/
int is_chain_ok(const char* prev, const char* curr)
{
    char last;
    char first;

    last = prev[strlen(prev) - 1];
    first = curr[0];

    if (last == first)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
    기능명: to_lower_str. 소문자 변환
    내용: 문자열의 알파벳을 모두 소문자로 바꾼다.
    입력: 변환할 문자열.
    출력: 없음
    오류: 없음
*/
void to_lower_str(char* s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = (char)tolower((unsigned char)s[i]);
    }
}
