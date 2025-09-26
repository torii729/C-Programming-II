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

// 함수 선언
int check_phone_str(const char* str);
void input_phone(char* phone);
void print_result(const char* phone);

// 메인 함수
int main(void)
{
    char phone[50];

    while (1)
    {
        input_phone(phone); // 전화번호 입력 받음
        if (strcmp(phone, ".") == 0) // 입력하면 종료
        {
            break;


        }

        print_result(phone); // 검사 결과 출력
    }

    return 0;
}

// 전화번호 형식 검사
int check_phone_str(const char* str)
{
    int len = strlen(str);

    if (len != 11) // 길이는 11자리여야 함
    {
        return 0;
    }

    if ((str[0] != '0') || (str[1] != '1') || (str[2] != '0')) // 앞이 010이 아니면,
    {
        return 0;
    }

    for (int i = 0; i < len; i++) // 나머지는 전부 숫자
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1; // 조건 만족하면 유효
}

// 전화번호 입력 받기
void input_phone(char* phone)
{
    printf("전화번호(. 입력 시 종료)? ");
    gets(phone);
    phone[strcspn(phone, "\n")] = '\0'; // asdf을 입력하면 asdf\n\0로 저장되기 때문에 \n을 빼야한다
}

// 검사 결과 출력
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