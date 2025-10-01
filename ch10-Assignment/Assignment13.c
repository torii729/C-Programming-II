/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 13. 직사각형 정보를 나타내는 RECT 구조체 정의.
        직사각형의 점의 좌표는 POINT 구조체를 이용한다. 직사각형의 정보를 출력하는 print_rect 함수를 정의하고,
        RECT 구조체 변수를 선언해서 직사각형 정보를 입력받고 출력하는 프로그램 작성.
	날짜 : 2025.10.01
*/

/*
    메모리 동작:
    RECT 구조체 r은 내부에 POINT 구조체 lb와 rt를 가진다.
    scanf_s 함수로 입력받은 값이 r.lb.x, r.lb.y, r.rt.x, r.rt.y에 각각 저장된다.
*/

#include <stdio.h>

typedef struct {
    int x, y; // 좌표
} POINT;

typedef struct {
    POINT lb; // 좌하단 점
    POINT rt; // 우상단 점
} RECT;

void run_rect();

// 기능명: main. 프로그램 실행 시작
// 내용: run_rect 함수를 호출하여 직사각형 좌표를 입력받고 출력한다.
// 입력: 없음
// 출력: 없음
// 오류: 없음
int main()
{
    run_rect();
    return 0; // 정상 종료
}

// 기능명: run_rect. 직사각형 좌표 입력 및 출력
// 내용: 사용자로부터 직사각형의 좌하단점과 우상단점을 입력받아 출력한다.
// 입력: 표준 입력(x, y 좌표 두 쌍)
// 출력: 직사각형 좌표 정보
// 오류: 잘못된 입력 시 동작이 보장되지 않음
void run_rect()
{
    RECT r;

    printf("직사각형의 좌하단점(x,y)? ");
    scanf_s("%d %d", &r.lb.x, &r.lb.y);
    printf("직사각형의 우상단점(x,y)? ");
    scanf_s("%d %d", &r.rt.x, &r.rt.y);

    printf("[RECT 좌하단점:(%d, %d) 우상단점:(%d, %d)]\n", r.lb.x, r.lb.y, r.rt.x, r.rt.y);
}
