/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 공부 : 문자열의 앞 뒤 공백문자 제거 (trim)
    날짜 : 2025.09.29
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// isspace() : 매개변수로 들어온 값이 공백인지 확인하고, 공백이면 0이 아닌 수를 반환, 그렇지 않으면 0을 반환
// \0, \n, \t, \v, \f, \r를 공백이라 판단함

// 문자열 앞쪽 공백 제거 (Left Trim)
char* ltrim(char* str) 
{
    if (str == NULL) return NULL;

    // 앞쪽 공백 문자를 건너뛴다
    while (*str && isspace(*str))
    {
        str++;
    }
    return str;
}

// 문자열 뒤쪽 공백 제거 (Right Trim)
char* rtrim(char* str) 
{
    if (str == NULL) return NULL;

    int len = strlen(str);
    if (len == 0) return str;

    // 뒤에서부터 공백 문자를 NULL로 변경
    char* end = str + len - 1;
    while (end >= str && isspace(*end)) 
    {
        *end = '\0';// 공백 대신 문자열 끝 표시
        end--;
    }
    return str;
}

// 문자열 앞뒤 공백 제거 (Trim)
char* trim(char* str) 
{
    if (str == NULL) return NULL;

    // 먼저 오른쪽 trim을 하고, 그 다음 왼쪽 trim을 한다
    rtrim(str);
    return ltrim(str);
}

int main() 
{
    char temp1[] = "   hello world   ";
    char temp2[] = "\t\n  C Programming  \r\n ";

    // 앞뒤 공백이 제거되는지 확인 출력
    printf("1: '%s'\n", ltrim(temp1)); // 앞 공백 제거
    printf("2: '%s'\n", rtrim(temp1)); // 뒤 공백 제거
    printf("3: '%s'\n", trim(temp2)); // 앞뒤 공백 제거
}
