/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch10 PPT 예제 10-12 : 비트필드의 정의 및 사용
	날짜 : 2025.10.01
*/

/*
    관련 개념:
    비트 필드는 구조체 멤버를 비트 단위로 나누어 저장한다.
    각 멤버의 크기를 제한할 수 있어 메모리를 절약할 수 있다.
    year를 7비트로 선언했기 때문에 0~127까지 표현 가능하며, 여기서는 0~99 범위를 사용한다.

    메모리 동작:
    day는 5비트, month는 4비트, year는 7비트로 하나의 unsigned int 내부에 저장된다.
    year는 0부터 시작하는 2자리 수(00~99)를 표현하므로, 실제 연도로 출력할 때는 2000을 더해 4자리 연도로 맞춘다.
*/

#include <stdio.h>

typedef struct date {
    unsigned int day : 5; // 1~31 (5비트)
    unsigned int month : 4; // 1~12 (4비트)
    unsigned int year : 7; // 0~99 (7비트, 2000년 기준)
} Date;

int main(void)
{
    Date dday;
    dday.day = 1; // 1일
    dday.month = 10; // 10월
    dday.year = 25; // 25

    printf("구조체 크기: %d\n", sizeof(Date)); // 비트 필드 구조체 크기 출력
    // dday.year + 2000은 2000 + 25 = 2025년 계산이다. 2025를 넣게 될 경우엔 오버플로우가 일어나리라 예측한다.
    printf("%d/%d/%d\n", dday.year + 2000, dday.month, dday.day); // 실제 연도 계산

    return 0;
}
