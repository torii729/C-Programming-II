/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-14 : 열거체와 열거 상수의 정의 및 사용
    날짜 : 2025.10.01
*/

/*
    관련 개념:
    enum은 서로 관련 있는 상수들을 모아 이름을 붙여주는 사용자 정의 자료형이다.
    내부적으로는 정수 값(0부터 시작)이 순서대로 할당된다.
    switch문에서는 enum 상수를 case로 사용할 수 있다.

    메모리 동작:
    열거형 변수는 int 크기의 공간을 차지하며, 선택된 상수 값(정수)이 저장된다.
*/

#include <stdio.h>

enum direction { NORTH, SOUTH, EAST, WEST }; // 열거형 정의

// 기능명: main. 열거체 사용 예제
// 내용: enum을 이용해 방향을 정의하고 switch문을 통해 해당 방향의 메시지를 출력한다.
// 입력: 없음
// 출력: 선택된 방향에 따른 메시지 출력
// 오류: 없음

int main(void)
{
    enum direction d1 = NORTH; // 열거형 변수 선언 및 초기화

    d1 = EAST; // 열거형 변수에 다른 상수 대입
    printf("d1 = %d\n", d1); // EAST는 2로 출력됨

    switch (d1) {
    case NORTH:
        printf("북쪽으로 이동합니다.\n");
        break;
    case SOUTH:
        printf("남쪽으로 이동합니다.\n");
        break;
    case EAST:
        printf("동쪽으로 이동합니다.\n");
        break;
    case WEST:
        printf("서쪽으로 이동합니다.\n");
        break;
    }

    return 0;
}
