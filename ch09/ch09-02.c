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

/*
    기능명: ltrim. 문자열의 왼쪽 공백 제거
    내용: 문자열의 시작부터 공백 문자가 아닌 첫 문자가 나올 때까지 포인터를 이동시켜 반환한다.
    입력: char* str (입력 문자열)
    출력: 공백이 제거된 문자열의 시작 주소
    오류: NULL 입력 시 NULL 반환
*/
char* ltrim(char* str)
{
    if (str == NULL) return NULL;

    while (*str && isspace(*str)) // 앞쪽 공백 문자 건너뜀
        str++;

    return str;
}

/*
    기능명: rtrim. 문자열의 오른쪽 공백 제거
    내용: 문자열의 끝에서부터 공백 문자를 찾아 '\0'으로 대체해 문자열을 잘라낸다.
    입력: char* str (입력 문자열)
    출력: 오른쪽 공백이 제거된 원본 문자열 주소
    오류: NULL 또는 빈 문자열 입력 시 원본 그대로 반환
*/
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

/*
    기능명: trim. 문자열 양쪽 공백 제거
    내용: rtrim을 먼저 호출해 오른쪽 공백을 제거한 뒤, ltrim을 호출하여 왼쪽 공백을 제거한다.
    입력: char* str (입력 문자열)
    출력: 양쪽 공백이 제거된 문자열의 시작 주소
    오류: NULL 입력 시 NULL 반환
*/
char* trim(char* str)
{
    if (str == NULL) return NULL;

    rtrim(str); // 오른쪽 공백 제거
    return ltrim(str); // 왼쪽 공백 제거
}

/*
    기능명: main. 프로그램 시작점
    내용: 문자열의 앞, 뒤, 양쪽 공백 제거 함수를 테스트한다.
    입력: 없음
    출력: 공백 제거 결과를 콘솔에 출력한다.
    오류: 없음
*/
int main()
{
    char temp1[] = "   hello world   ";
    char temp2[] = "\t\n  C Programming  \r\n ";

    printf("1: '%s'\n", ltrim(temp1)); // 앞 공백 제거
    printf("2: '%s'\n", rtrim(temp1)); // 뒤 공백 제거
    printf("3: '%s'\n", trim(temp2)); // 앞뒤 공백 제거

    return 0;
}
