/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch10 PPT 예제 10-13 : LINE 구조체의 정의 및 사용
	날짜 : 2025.10.01
*/

/*
    관련 개념:
    구조체 안에 다른 구조체를 멤버로 포함시킬 수 있다.
    두 점 (x1, y1), (x2, y2) 사이의 거리는 피타고라스 정리를 이용해 sqrt((x2 - x1)^2 + (y2 - y1)^2)로 구한다.
    const 구조체 포인터를 함수 매개변수로 사용하면, 함수 안에서 구조체 내용을 수정하지 않음을 보장한다.

    메모리 동작:
    LINE 구조체는 POINT 구조체 두 개(start, end)를 연속된 메모리에 저장한다.
    get_length 함수는 포인터로 전달받은 LINE 구조체에서 좌표를 읽어와 길이를 계산한다.
*/

#include <stdio.h>
#include <math.h> // sqrt 함수 사용

typedef struct point {
    int x; // x 좌표
    int y; // y 좌표
} POINT;

typedef struct line {
    POINT start; // 시작점
    POINT end; // 끝점
} LINE;

double get_length(const LINE* ln); // 선분 길이 계산 함수 원형

int main(void)
{
    LINE ln1 = { {10, 20}, {30, 40} }; // 시작점 (10,20), 끝점 (30,40)
    printf("직선의 시작점 : (%d, %d)\n", ln1.start.x, ln1.start.y);
    printf("직선의 끝점 : (%d, %d)\n", ln1.end.x, ln1.end.y);

    printf("직선의 길이 : %f\n", get_length(&ln1));

    return 0;
}

double get_length(const LINE* ln)
{
    int dx = ln->end.x - ln->start.x; // x 좌표 차이
    int dy = ln->end.y - ln->start.y; // y 좌표 차이

    return sqrt(dx * dx + dy * dy); // 피타고라스
}