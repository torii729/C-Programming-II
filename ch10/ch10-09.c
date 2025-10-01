/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch10 PPT 예제 10-7 : 구조체 포인터
	날짜 : 2025.10.01
*/

/*
    관련 개념:
    구조체 포인터는 구조체 변수를 가리키는 포인터다.
    구조체 포인터로 멤버에 접근할 때는 -> 연산자를 사용한다.
    strcpy 같은 함수를 통해 문자열 멤버를 수정할 수 있다.

    메모리 동작:
    ct 구조체 변수는 스택에 저장된다.
    p 포인터는 ct의 시작 주소를 저장한다.
    p->멤버 접근은 (*p).멤버와 동일하게 동작한다.

	*p.name과 (*p).name은 다르다.
	p.name이 먼저 해석되기 때문에 오류가 발생한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct contact {
    char name[20]; // 이름
    char phone[20]; // 전화번호
    int ringtone; // 벨소리 번호
} Contact;

int main(void)
{
    Contact ct = { "홍길동", "010-1234-5678", 1 }; // 구조체 변수 초기화
    Contact* p = &ct; // 구조체 포인터 p가 ct를 가리킴

    p->ringtone = 5; // 포인터로 멤버 값 수정
    strcpy(p->phone, "010-9999-8888"); // 포인터로 문자열 멤버 수정

    printf("이름 : %s\n", p->name); // 포인터로 멤버 접근
    printf("전화 : %s\n", p->phone);
    printf("벨소리 : %d\n", p->ringtone);

    return 0;
}
