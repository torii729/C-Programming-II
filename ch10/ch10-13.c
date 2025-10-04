/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-11 : 구조체형의 출력 매개변수를 가진 함수의 정의
    날짜 : 2025.10.01
*/

/*
    관련 개념 :
    srand는 난수 발생기의 초기값을 설정하며, time(NULL)을 이용해 실행할 때마다 다른 난수를 생성한다.
    rand는 난수를 반환하며, % 연산을 통해 원하는 범위의 값을 얻을 수 있다.
    구조체 포인터를 사용하면 함수에서 직접 구조체 멤버 값을 수정할 수 있다.
    const 포인터를 사용하면 함수 내에서 구조체 데이터를 변경할 수 없음을 보장한다.

    메모리 동작 :
    arr 배열은 Point 구조체 5개를 연속으로 저장한다.
    set_point 함수는 구조체 포인터를 받아 원소의 멤버를 직접 수정한다.
    print_point 함수는 const 포인터를 통해 멤버를 읽기 전용으로 참조한다.

    srand, rand는 stdlib.h와 time.h에 선언되어 있다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} Point;

void print_point(const Point* pt);
void set_point(Point* pt, int x, int y);

// 기능명: main. 구조체 포인터를 이용한 값 설정 및 출력 예제
// 내용: Point 구조체 배열의 각 원소를 난수 좌표로 초기화하고, const 포인터를 통해 출력한다.
// 입력: 없음
// 출력: 난수로 설정된 Point 구조체 배열의 좌표 출력
// 오류: 없음
int main(void)
{
    Point arr[5] = { 0 }; // 구조체 배열 초기화
    int sz = sizeof(arr) / sizeof(arr[0]); // 배열 크기 계산
    int i;

    srand((unsigned int)time(NULL)); // 난수 발생기 초기화
    for (i = 0; i < sz; i++) {
        int x = rand() % 100; // 0~99 범위 난수
        int y = rand() % 100; // 0~99 범위 난수
        set_point(&arr[i], x, y); // 난수 좌표로 구조체 값 설정
    }

    for (i = 0; i < sz; i++)
    {
        print_point(&arr[i]); // 구조체 출력
        printf(" ");
    }
    printf("\n");

    return 0;
}

// 기능명: print_point. 구조체 출력 함수
// 내용: 전달받은 Point 구조체 포인터의 좌표를 출력한다. (읽기 전용)
// 입력: const Point* pt (좌표를 가진 구조체 주소)
// 출력: 구조체 좌표 출력
// 오류: 없음
void print_point(const Point* pt)
{
    printf("(%d, %d)", pt->x, pt->y); // 구조체 멤버 출력
}

// 기능명: set_point. 구조체 값 설정 함수
// 내용: 전달받은 Point 구조체 포인터의 x, y 값을 설정한다.
// 입력: Point* pt (구조체 주소), int x, int y (좌표값)
// 출력: 없음
// 오류: 없음
void set_point(Point* pt, int x, int y)
{
    pt->x = x; // x 값 설정
    pt->y = y; // y 값 설정
}
