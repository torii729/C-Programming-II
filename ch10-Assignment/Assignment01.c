/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 01. 아이디와 패스워드를 관리하기 위한 LOGIN 구조체를 정의하시오.
        아이디와 패스워드는 각각 최대 20글자까지 입력할 수 있다. LOGIN 구조체 변수를 선언한 다음
        아이디와 패스워드를 입력받아 저장하고 출력하는 프로그램을 작성하시오.
        패스워드를 출력할 때는 패스워드 글자 수만큼 *을 대신 출력한다.
	날짜 : 2025.10.01
*/

/*
    메모리 동작:
    LOGIN 구조체 변수는 id와 pw 배열을 내부에 가진다.
    scanf_s 함수는 입력을 배열에 저장하고, strlen은 문자열 길이를 계산한다.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 21 // 문자열 크기 상수 정의

typedef struct
{
    char id[SIZE]; // 사용자 ID
    char pw[SIZE]; // 사용자 PW
} LOGIN;

// 기능명: main. 프로그램 실행 시작
// 내용: run_login 함수를 호출하여 로그인 절차를 수행한다.
// 입력: 없음
// 출력: 없음
// 오류: 없음

int main()
{
    run_login(); // 로그인 실행
    return 0; // 정상 종료
}

// 기능명: run_login. 로그인 절차 실행
// 내용: ID와 PW를 입력받아 출력하되, PW는 '*' 문자로 마스킹 처리한다.
// 입력: 없음 (표준 입력으로 ID와 PW 입력)
// 출력: 입력받은 ID와 '*'로 마스킹된 PW
// 오류: 문자열 크기를 초과 입력하면 잘못된 동작 발생 가능

void run_login()
{
    LOGIN my = { 0 }; // 구조체 변수 초기화

    printf("ID 입력: ");
    scanf_s("%s", my.id, sizeof(my.id)); // ID 입력

    printf("PW 입력: ");
    scanf_s("%s", my.pw, sizeof(my.pw)); // PW 입력

    printf("ID : %s\n", my.id); // ID 출력
    printf("PW : ");
    for (int i = 0; i < strlen(my.pw); i++)
    {
        printf("*"); // PW 길이만큼 '*' 출력
    }
    printf("\n");
}
