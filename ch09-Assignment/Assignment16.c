/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 16. 사용자로부터 아이디와 패스워드를 입력받아 로그인 과정 처리.
        5명의 아이디와 패스워드가 이미 등록되어 있을 때 로그인 기능 구현
        아이디가 존재하지 않거나 해당하는 패스워드가 일치하지 않으면 에러 메시지 출력 후 다시 입력받게 한다.
        3번의 재시도 후에도 입력하지 못하면 로그인 실패 에러 메시지를 출력한다.
        아이디 문자열 배열과 패스워드 문자열은 마음대로 정한다.
    날짜 : 2025.09.28
*/

#include <stdio.h>
#include <string.h>

// 함수 선언
int login(const char* id, const char* pw);
void process_login(void);

// 메인 함수
int main(void)
{
    process_login(); // 로그인 과정 실행
    return 0;
}

// 로그인 검증 
int login(const char* id, const char* pw)
{
    char ids[5][20] = { "seoyon", "torii", "gimin", "kook", "jimin" };
    char pws[5][20] = { "1234", "2345", "3456", "4567", "5678" };

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(id, ids[i]) == 0) // 아이디 맞음
        {
            if (strcmp(pw, pws[i]) == 0) // 비번도 맞음
            {
                return 1; // 성공

            }
            else
            {
                return -1; // 비번 틀림
            }
        }
    }
    return 0; // 아이디 없음
}

// 로그인 과정 처리
void process_login(void)
{
    char id[20] = { 0 };
    char pw[20] = { 0 };
    int result = 0;
    int tries = 0;

    while (tries < 3)
    {
        printf("ID : ");
        scanf_s("%s", id, 20);
        printf("PW : ");
        scanf_s("%s", pw, 20);

        result = login(id, pw);

        if (result == 1)
        {
            printf("로그인 성공!\n");
            return;
        }
        else if (result == -1)
        {
            printf("패스워드가 틀렸습니다.\n");
        }
        else
        {
            printf("해당 id가 없습니다.\n");
        }

        tries++;
    }
    printf("로그인 실패!\n");
}
