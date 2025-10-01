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

void print_point(Point *pt); // 구조체를 매개변수로 받는 함수 원형

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
        print_point(&arr[i]); // 구조체 값 전달
        printf(" ");
    }
    printf("\n");

    return 0;
}

void print_point(Point *pt)
{
    printf("(%d, %d)", pt->x, pt->y); // 구조체 멤버 출력
}
