/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch10 PPT 예제 10-3 : 구조체 변수 간의 초기화와 대입
	날짜 : 2025.09.30
*/

/*
    관련 개념:
    구조체 변수는 같은 타입끼리 통째로 복사할 수 있다.
    초기화 시에도 다른 구조체 변수로 초기화가 가능하다.
    대입 연산으로 구조체의 모든 멤버 값이 한 번에 복사된다.

    메모리 동작:
    struct contact ct, ct2, ct3는 각각 스택에 독립적으로 저장된다.
    ct3 = ct2처럼 대입하면 멤버 값이 그대로 복사되고, 메모리를 공유하지 않는다.
*/

#include <stdio.h>

struct contact
{
    char name[20]; // 이름
    char phone[20]; // 전화번호
    int age; // 나이
};

int main(void)
{
    struct contact ct = { "Alice", "010-1234-5678", 0 };
    struct contact ct2 = { "Bob", "010-9876-5432", 1 };
    struct contact ct3 = ct2; // 구조체 변수로 초기화
    printf("ct2으로 초기화 후의 ct3 = %s, %s, %d\n", ct3.name, ct3.phone, ct3.age);

    ct3 = ct; // 구조체 대입
    printf("ct로 대입 후의 ct3 = %s, %s, %d\n", ct3.name, ct3.phone, ct3.age);

    return 0;
}
