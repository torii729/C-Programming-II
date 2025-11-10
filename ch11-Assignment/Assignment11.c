/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 11. join_string 동적 메모리 문자열 연결
    날짜 : 2025.11.23
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(void);
char* join_string(const char* s1, const char* s2);
void trim_newline(char* s);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 문자열 연결 프로그램을 실행한다.
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
    내용: 두 문자열을 입력받아 join_string으로 합친 결과를 출력한다.
    입력: 첫 번째 문자열, 두 번째 문자열.
    출력: 합쳐진 문자열 출력.
    오류: 메모리 할당 실패 시 종료한다.
*/
void test(void)
{
    char s1[200];
    char s2[200];
    char* joined;

    printf("첫 번째 문자열? ");
    fgets(s1, sizeof(s1), stdin);
    trim_newline(s1);

    printf("두 번째 문자열? ");
    fgets(s2, sizeof(s2), stdin);
    trim_newline(s2);

    joined = join_string(s1, s2);
    if (joined == NULL)
    {
        return;
    }

    printf("%s\n", joined);
    free(joined);
}

/*
    기능명: join_string. 문자열 연결
    내용: 동적 메모리에 두 문자열의 복사본을 연결해 저장하고 그 주소를 반환한다.
    입력: 문자열 2개.
    출력: 연결된 새 문자열 주소.
    오류: 메모리 할당 실패 시 NULL 반환.
*/
char* join_string(const char* s1, const char* s2)
{
    char* p;
    size_t len1;
    size_t len2;

    len1 = strlen(s1);
    len2 = strlen(s2);

    p = (char*)malloc(len1 + len2 + 1);
    if (p == NULL)
    {
        return NULL;
    }

    strcpy_s(p, len1 + len2 + 1, s1);
    strcat_s(p, len1 + len2 + 1, s2);

    return p;
}

/*
    기능명: trim_newline. 개행 제거
    내용: fgets로 입력된 문자열 끝의 개행을 제거한다.
    입력: 문자열.
    출력: 없음
    오류: 없음
*/
void trim_newline(char* s)
{
    size_t n;

    n = strcspn(s, "\n");
    s[n] = '\0';
}
