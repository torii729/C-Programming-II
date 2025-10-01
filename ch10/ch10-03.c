/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch10 PPT 예제 10-1 : 구조체의 정의
	날짜 : 2025.09.30
*/

/*
   관련 개념:
   구조체는 서로 다른 자료형을 하나의 사용자 정의 자료형으로 묶는다.
   typedef를 사용하면 struct 키워드를 생략하고 새로운 타입 이름으로 사용할 수 있다.
   sizeof 연산자는 구조체 전체가 차지하는 바이트 크기를 알려준다.

   메모리 동작:
   구조체는 멤버들을 순서대로 메모리에 배치한다.
   구조체는 선언 당시 "메모리를 할당하지 않고", 변수를 선언할 때 메모리가 할당된다.
   따라서 구체적인 값을 넣지 않는다.
*/

#include <stdio.h>

typedef struct contact
{
    char name[20]; // 이름 문자열
    char phone[20]; // 전화번호 문자열
    int ringtone; // 벨소리 번호
} contact;

int main(void)
{
    printf("contact 구조체의 크기 = %d\n", sizeof(contact)); // 구조체 크기 출력
    return 0;
}

void test()
{
    struct contact c1; // 구조체 변수 선언, 이런 식으로 여러 함수에서 구조체를 사용할 수 있다.
}
