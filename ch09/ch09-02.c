/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 공부 : 문자열의 앞 뒤 공백문자 제거 (trim)
    날짜 : 2025.09.29
*/

/*
    관련 개념 :
    isspace 함수는 문자가 공백, 개행, 탭, 수직 탭 등을 판별한다.
    문자열의 공백 제거에는 포인터 연산과 반복문을 활용할 수 있다.
    왼쪽 공백 제거는 시작 포인터를 옮기면 되고, 오른쪽 공백 제거는 문자열 끝을 '\0'으로 바꾸면 된다.

    메모리 동작 :
    문자열은 배열로 스택에 저장된다.
    ltrim은 포인터를 옮겨서 시작 위치를 바꾸지만 원본 배열의 내용은 수정하지 않는다.
    rtrim은 문자열 끝 부분을 '\0'으로 덮어써서 실제 배열 내용을 수정한다.
    trim은 rtrim과 ltrim을 차례로 호출하여 양쪽 공백을 제거한다.

    이 방식을 쓰는 이유 :
    입력된 문자열을 전처리할 때 불필요한 앞뒤 공백을 제거하는 것은 매우 흔한 작업이다.
    공백 제거를 함수로 만들어 두면 코드 재사용성과 가독성이 높아진다.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* ltrim(char* str)
{
    if (str == NULL) return NULL;

    while (*str && isspace(*str)) // 앞쪽 공백 문자 건너뜀
        str++;

    return str;
}

char* rtrim(char* str)
{
    if (str == NULL) return NULL;

    int len = strlen(str); // 문자열 길이 계산
    if (len == 0) return str;

    char* end = str + len - 1; // 문자열 마지막 문자 위치
    while (end >= str && isspace(*end))
    {
        *end = '\0'; // 공백 문자를 문자열 끝으로 바꿈
        end--;
    }
    return str;
}

char* trim(char* str)
{
    if (str == NULL) return NULL;

    rtrim(str); // 먼저 오른쪽 공백 제거
    return ltrim(str); // 이어서 왼쪽 공백 제거
}

int main()
{
    char temp1[] = "   hello world   ";
    char temp2[] = "\t\n  C Programming  \r\n ";

    printf("1: '%s'\n", ltrim(temp1)); // 앞 공백 제거
    printf("2: '%s'\n", rtrim(temp1)); // 뒤 공백 제거
    printf("3: '%s'\n", trim(temp2)); // 앞뒤 공백 제거

    return 0;
}
