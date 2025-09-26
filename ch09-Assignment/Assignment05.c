/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 5. 대소문자를 구분하지 않고 문자열을 비교하는 strcmp_ic 함수를 작성하시오.
        리턴값은 lhs가 rhs보다 크면 0보다 큰 값, 두 문자열이 같으면 0, lhs가 rhs보다 작으면 0보다 작은 값을 리턴한다.
    날짜 : 2025.09.28
*/

#include <stdio.h>
#include <ctype.h> // 대소문자 변환에 필요

// 함수 선언
int strcmp_ic(const char* lhs, const char* rhs);
void input_string(char* str1, char* str2);
void compare_and_print(const char* str1, const char* str2);

// 메인 함수
int main(void)
{
    char str1[100] = { 0 };
    char str2[100] = { 0 };

    input_string(str1, str2); // 문자열 입력 받음
    compare_and_print(str1, str2); // 비교하고 출력함

    return 0;
}

// 문자열 비교 (대소문자 구분 안 함)
int strcmp_ic(const char* lhs, const char* rhs)
{
    while ((*lhs != '\0') && (*rhs != '\0'))
    {
        char a = tolower(*lhs); // 소문자로 통일해서 비교
        char b = tolower(*rhs);

        if (a != b)
        {
            return a - b; // 다르면 차이값 반환
        }

        lhs++;
        rhs++;
    }
    return tolower(*lhs) - tolower(*rhs); // 끝까지 갔을 때 차이를 반환한다.
}

// 문자열 입력 받기
void input_string(char* str1, char* str2)
{
    printf("첫 번째 문자열 ? ");
    gets(str1);

    printf("두 번째 문자열 ? ");
    gets(str2);
}

// 비교 후 결과 출력
void compare_and_print(const char* str1, const char* str2)
{
    if (strcmp_ic(str1, str2) == 0)
    {
        printf("%s와 %s가 같습니다.\n", str1, str2);
    }
    else
    {
        printf("%s와 %s는 다릅니다.\n", str1, str2);
    }
}
