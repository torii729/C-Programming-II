/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 4. 아이디와 패스워드가 저장된 텍스트 파일을 크기가 10인 LOGIN 구조체 배열로 읽어 온 다음,
        입력 받은 아이디와 패스워드가 일치하면 "로그인 성공" 아니면 "로그인 실패"라고 출력하는 프로그램을 작성하시오.
    날짜 : 2025.11.9
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LOGIN 10
#define MAX_LEN 20

typedef struct LOGIN
{
    char id[MAX_LEN];
    char password[MAX_LEN];
} LOGIN;

void test(void);
void load_logins_from_file(const char* filename, LOGIN logins[], int* pCount);
int find_login_index(const LOGIN logins[], int count, const char* id);
int check_password(const LOGIN* login, const char* password);


/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 로그인 기능을 실행한다.
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
    내용: 텍스트 파일에서 로그인 정보를 읽어 온 뒤,
          사용자에게 ID와 Password를 입력받아 로그인 결과를 출력한다.
    입력: 콘솔에서 ID와 Password 문자열을 입력받는다.
    출력: 로그인 성공 여부를 콘솔에 출력한다.
    오류: 파일 읽기 실패나 입력 실패 시 오류 메시지를 출력한다.
*/
void test(void)
{
    LOGIN logins[MAX_LOGIN];
    int count = 0;
    char id[MAX_LEN];
    char password[MAX_LEN];
    int index;

    load_logins_from_file("password.txt", logins, &count);

    if (count == 0)
    {
        printf("로그인 정보를 읽지 못했습니다.\n");
        return;
    }

    printf("ID? ");
    if (scanf_s("%s", id, (unsigned int)sizeof(id)) != 1)
    {
        printf("ID를 읽을 수 없습니다.\n");
        return;
    }

    index = find_login_index(logins, count, id);

    if (index == -1)
    {
        printf("아이디를 찾을 수 없습니다.\n");
        return;
    }

    printf("Password? ");
    if (scanf_s("%s", password, (unsigned int)sizeof(password)) != 1)
    {
        printf("Password를 읽을 수 없습니다.\n");
        return;
    }

    if (check_password(&logins[index], password))
    {
        printf("로그인 성공\n");
    }
    else
    {
        printf("로그인 실패\n");
    }
}

/*
    기능명: load_logins_from_file. 로그인 정보 읽기
    내용: 지정한 텍스트 파일을 열어 아이디와 패스워드를
          LOGIN 구조체 배열에 최대 10개까지 저장한다.
    입력: 파일 이름 문자열, LOGIN 배열, 실제로 읽은 개수를 돌려줄 정수 포인터.
    출력: 배열에 로그인 정보가 채워지고, 읽은 개수가 pCount에 저장된다.
    오류: 파일을 열 수 없으면 개수를 0으로 설정하고 오류 메시지를 출력한다.
*/
void load_logins_from_file(const char* filename, LOGIN logins[], int* pCount)
{
    FILE* fp;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        *pCount = 0;
        return;
    }

    // 아이디와 패스워드를 한 줄씩 읽어서 배열에 저장
    while (i < MAX_LOGIN &&
        fscanf_s(fp, "%s %s", logins[i].id, sizeof(logins[i].id),
            logins[i].password, sizeof(logins[i].password)) == 2)
    {
        i++;
    }

    *pCount = i;
    fclose(fp);
}

/*
    기능명: find_login_index. 아이디 검색
    내용: LOGIN 구조체 배열에서 주어진 아이디와 일치하는 요소의 인덱스를 찾는다.
    입력: LOGIN 배열, 배열에 저장된 개수, 찾고자 하는 아이디 문자열.
    출력: 찾은 경우 해당 인덱스(0 이상), 찾지 못한 경우 -1을 반환한다.
    오류: 없음
*/
int find_login_index(const LOGIN logins[], int count, const char* id)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (strcmp(logins[i].id, id) == 0)
        {
            return i;
        }
    }
    return -1;
}

/*
    기능명: check_password. 패스워드 비교
    내용: 하나의 LOGIN 구조체에 저장된 패스워드와 입력된 패스워드가 같은지 비교한다.
    입력: LOGIN 구조체 포인터, 입력된 패스워드 문자열.
    출력: 같으면 1, 다르면 0을 반환한다.
    오류: 없음
*/
int check_password(const LOGIN* login, const char* password)
{
    if (strcmp(login->password, password) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


