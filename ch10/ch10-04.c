/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-2 : 구조체 변수의 선언 및 사용
    날짜 : 2025.09.30
*/

/*
    관련 개념:
    구조체는 서로 다른 자료형을 하나로 묶어 다룰 수 있는 사용자 정의 자료형이다.
    구조체 변수는 선언과 동시에 초기화할 수 있으며, 점 연산자를 통해 멤버에 접근한다.
    strcpy 같은 함수를 사용해 문자열 멤버에 값을 대입할 수 있다.
    scanf를 이용하면 구조체 멤버에 직접 입력을 받을 수도 있다.

    메모리 동작:
    struct contact는 name과 phone을 char 배열로, ringtone을 int로 가진다.
    구조체 변수는 스택에 생성되며, 각 멤버는 구조체 내부에서 연속된 공간에 배치된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct contact
{
    char name[20]; // 이름
    char phone[20]; // 전화번호
    int ringtone; // 벨소리
};

// 기능명: main. 구조체 변수 선언 및 사용 예제
// 내용: 구조체 contact를 선언, 초기화, 입력 및 출력 과정을 통해 구조체 사용법을 실습한다.
// 입력: 사용자로부터 이름, 전화번호, 벨소리 번호를 입력받는다.
// 출력: 각 구조체 변수의 멤버 값을 콘솔에 출력한다.
// 오류: 없음

int main(void)
{
    struct contact ct = { "홍길동", "010-1234-5678", 1 }; // 선언과 동시에 초기화
    struct contact ct1 = { 0 }, ct2 = { 0 }; // 모두 0으로 초기화

    ct.ringtone = 5; // 멤버 값 변경
    strcpy(ct.phone, "010-1234-1234"); // 문자열 복사
    printf("이름 : %s\n", ct.name);
    printf("전화번호 : %s\n", ct.phone);
    printf("벨소리 : %d\n", ct.ringtone);

    strcpy(ct1.name, "김철수");
    strcpy(ct1.phone, "010-5678-5678");
    ct1.ringtone = 1;
    printf("이름 : %s\n", ct1.name);
    printf("전화번호 : %s\n", ct1.phone);
    printf("벨소리 : %d\n", ct1.ringtone);

    printf("이름 입력 : ");
    scanf("%s", ct2.name);
    printf("전화번호 입력 : ");
    scanf("%s", ct2.phone);
    printf("벨소리 입력(0~9) : ");
    scanf("%d", &ct2.ringtone);

    printf("이름 : %s\n", ct2.name);
    printf("전화번호 : %s\n", ct2.phone);
    printf("벨소리 : %d\n", ct2.ringtone);

    return 0;
}
