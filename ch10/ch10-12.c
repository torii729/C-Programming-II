/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-10 : 구조체를 포인터로 전달하려는 경우
    날짜 : 2025.10.01
*/

/*
    관련 개념 :
    일반적인 포인터 사용법처럼 주소 연산자를 통하여 매개변수를 전달한 뒤
    -> 연산자를 이용하여 구조체 멤버에 접근한다.
    구조체를 복사하는 대신 주소만 전달하는 방법이다.
    이렇게 되면 pass by value 방식이 아닌 pass by reference 방식을 흉내낼 수 있다.
*/

#include <stdio.h>

typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} Point;

void print_point(Point* pt);

// 기능명: main. 구조체 포인터 전달 예제
// 내용: Point 구조체 배열의 각 원소 주소를 함수에 전달하여 출력한다.
// 입력: 없음
// 출력: 구조체 멤버(x, y 좌표)를 콘솔에 출력
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
        print_point(&arr[i]); // 구조체 포인터 전달
        printf(" ");
    }
    printf("\n");

    return 0;
}

// 기능명: print_point. 구조체 포인터 출력 함수
// 내용: 전달받은 Point 구조체 포인터를 통해 x, y 좌표를 출력한다.
// 입력: Point* pt (구조체의 주소)
// 출력: 구조체 멤버를 콘솔에 출력
// 오류: 없음
void print_point(Point* pt)
{
    printf("(%d, %d)", pt->x, pt->y); // 구조체 멤버 출력
}
