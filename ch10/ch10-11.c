/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-9 : 구조체를 값으로 전달하려는 경우
    날짜 : 2025.10.01
*/

/*
    관련 개념 :
    구조체 배열은 같은 "구조체 타입"의 여러 데이터를 연속된 메모리에 저장한다.
    구조체를 함수 인자로 전달할 수 있으며, 이때 값이 복사되어 전달된다.
    sizeof를 이용하면 배열 전체 크기를 원소 하나 크기로 나누어 배열 원소 개수를 구할 수 있다.

    메모리 동작 :
    arr 배열은 Point 구조체 5개를 연속해서 저장한다.
    print_point 함수 호출 시 arr[i]의 값이 복사되어 pt 매개변수에 전달된다.
*/

#include <stdio.h>

typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} Point;

void print_point(Point pt); // 구조체를 매개변수로 받는 함수 원형

// 기능명: main. 구조체 값 전달 예제
// 내용: Point 구조체 배열을 생성하고, 각 원소를 함수로 전달하여 출력한다.
// 입력: 없음
// 출력: 각 구조체의 좌표를 콘솔에 출력
// 오류: 없음

int main(void)
{
    Point arr[] = {
        {0, 0},
        {10, 10},
        {20, 20},
        {30, 30},
        {40, 40}
    };
    int sz = sizeof(arr) / sizeof(arr[0]); // 배열 원소 개수
    int i;

    for (i = 0; i < sz; i++)
    {
        print_point(arr[i]); // 구조체 값 전달
        printf(" ");
    }
    printf("\n");

    return 0;
}

// 기능명: print_point. 구조체 멤버 출력 함수
// 내용: 전달받은 Point 구조체의 x, y 좌표를 출력한다.
// 입력: Point pt (x, y 좌표를 가진 구조체)
// 출력: 구조체 멤버 값을 콘솔에 출력
// 오류: 없음

void print_point(Point pt)
{
    printf("(%d, %d)", pt.x, pt.y); // 구조체 멤버 출력
}
