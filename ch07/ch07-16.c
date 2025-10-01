/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-13 : 2차원 배열의 초기화
    날짜 : 2025.09.15
*/

/*
    관련 개념:
    2차원 배열은 행(Row)과 열(Col) 구조로 데이터를 저장한다.
    배열은 중괄호 {}로 행 단위 초기화가 가능하다.

    메모리 동작:
    int data[ROW][COL] = {{...}, {...}, {...}};
    메모리에는 연속적으로 3행 * 2열의 int 값이 차례로 저장된다.
    data[i][j]를 이용해 각 행과 열의 원소에 접근할 수 있다.
*/

#include <stdio.h>

#define ROW 3
#define COL 2

int main(void)
{
    int data[ROW][COL] = {
        {10, 20},
        {30, 40},
        {50, 60},
    };
    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            printf("%3d ", data[i][j]); // 각 원소 출력
        printf("\n");
    }

    return 0;
}
