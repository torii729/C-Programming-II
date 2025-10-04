/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 5. 대소문자를 구분하지 않고 문자열을 비교하는 strcmp_ic 함수를 작성하시오.
        리턴값은 lhs가 rhs보다 크면 0보다 큰 값, 두 문자열이 같으면 0, lhs가 rhs보다 작으면 0보다 작은 값을 리턴한다.
    날짜 : 2025.09.28
*/

#include <stdio.h>
#include <ctype.h> // 대소문자 변환에 필요

int strcmp_ic(const char* lhs, const char* rhs);
void input_string(char* str1, char* str2);
void compare_and_print(const char* str1, const char* str2);

/*
    기능명: main. 프로그램 시작점
    내용: 두 문자열을 입력받아 대소문자를 구분하지 않고 비교한 뒤 결과를 출력한다.
    입력: 없음
    출력: 두 문자열이 같거나 다른지 여부를 콘솔에 출력한다.
    오류: 없음
*/
int main(void)
{
    char str1[100] = { 0 };
    char str2[100] = { 0 };

    input_string(str1, str2);
    compare_and_print(str1, str2);

    return 0;
}

/*
    기능명: strcmp_ic. 대소문자 구분 없는 문자열 비교 함수
    내용: 두 문자열을 소문자로 변환하여 한 글자씩 비교한다.
    입력: const char* lhs (비교할 문자열 1), const char* rhs (비교할 문자열 2)
    출력: 같으면 0, lhs > rhs면 양수, lhs < rhs면 음수
    오류: 없음
*/
int strcmp_ic(const char* lhs, const char* rhs)
{
    while ((*lhs != '\0') && (*rhs != '\0'))
    {
        char a = tolower(*lhs); // 소문자로 통일해서 비교
        char b = tolower(*rhs);

        if (a != b)
            return a - b; // 다르면 차이값 반환

        lhs++;
        rhs++;
    }
    return tolower(*lhs) - tolower(*rhs); // 문자열 길이가 다른 경우 차이 반환
}

/*
    기능명: input_string. 문자열 입력 함수
    내용: 사용자에게 두 개의 문자열을 입력받아 각각 저장한다.
    입력: char* str1, char* str2 (입력받은 문자열 저장용 배열)
    출력: 없음 (입력 결과가 str1, str2에 저장됨)
    오류: 없음
*/
void input_string(char* str1, char* str2)
{
    printf("첫 번째 문자열 ? ");
    gets(str1);

    printf("두 번째 문자열 ? ");
    gets(str2);
}

/*
    기능명: compare_and_print. 비교 및 결과 출력 함수
    내용: strcmp_ic를 이용해 두 문자열을 비교하고 결과를 출력한다.
    입력: const char* str1, const char* str2
    출력: 비교 결과를 콘솔에 출력한다.
    오류: 없음
*/
void compare_and_print(const char* str1, const char* str2)
{
    if (strcmp_ic(str1, str2) == 0)
        printf("%s와 %s가 같습니다.\n", str1, str2);
    else
        printf("%s와 %s는 다릅니다.\n", str1, str2);
}
