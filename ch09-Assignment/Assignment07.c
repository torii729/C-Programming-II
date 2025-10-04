/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 7. 전화번호 문자열이 올바른 형식의 전화번호인지 검사하는 check_phone_str 함수를 작성
            전화번호는 "01012345678" 형식으로 입력받는다. 국번은 "010"만 가능하다고 가정한다.
    날짜 : 2025.09.28
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_phone_str(const char* str);
void input_phone(char* phone);
void print_result(const char* phone);

/*
    기능명: main. 프로그램 시작점
    내용: 사용자가 입력한 전화번호를 검사하고, 유효성 결과를 출력한다.
    입력: 없음 (사용자 입력으로 전화번호를 받음)
    출력: 검사 결과를 콘솔에 출력
    오류: 없음
*/
int main(void)
{
    char phone[50];

    while (1)
    {
        input_phone(phone); // 전화번호 입력 받음
        if (strcmp(phone, ".") == 0) // "." 입력 시 종료
        {
            break;
        }

        print_result(phone); // 검사 결과 출력
    }

    return 0;
}

/*
    기능명: check_phone_str. 전화번호 형식 검사
    내용: 문자열이 010으로 시작하고 총 11자리 숫자로 구성되어 있는지 검사한다.
    입력: const char* str (전화번호 문자열)
    출력: 유효하면 1, 잘못된 형식이면 0 반환
    오류: 없음
*/
int check_phone_str(const char* str)
{
    int len = strlen(str);

    if (len != 11) // 길이가 11자리인지 확인
    {
        return 0;
    }

    if ((str[0] != '0') || (str[1] != '1') || (str[2] != '0'))
    {
        return 0;
    }

    for (int i = 0; i < len; i++) // 모든 문자가 숫자인지 확인
    {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1; // 모든 조건 통과 시 유효한다는 의미
}

/*
    기능명: input_phone. 전화번호 입력 함수
    내용: 사용자로부터 전화번호를 입력받는다. '.' 입력 시 프로그램 종료.
    입력: char* phone (입력값 저장용 배열)
    출력: 없음 (입력 결과가 phone에 저장됨)
    오류: 없음
*/
void input_phone(char* phone)
{
    printf("전화번호(. 입력 시 종료)? ");
    gets(phone); // 문자열 입력
    phone[strcspn(phone, "\n")] = '\0'; // 입력 시 포함된 개행문자 제거
}

/*
    기능명: print_result. 검사 결과 출력 함수
    내용: 전화번호 유효성을 검사하고, 그 결과를 콘솔에 출력한다.
    입력: const char* phone (입력된 전화번호)
    출력: 유효 여부를 출력
    오류: 없음
*/
void print_result(const char* phone)
{
    if (check_phone_str(phone))
    {
        printf("%s는 유효한 전화번호입니다.\n", phone);
    }
    else
    {
        printf("잘못 입력했습니다. 01012345678 형식으로 입력하세요.\n");
    }
}
