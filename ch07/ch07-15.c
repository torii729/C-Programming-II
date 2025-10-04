/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-12 : 2차원 배열의 사용
    날짜 : 2025.09.15
*/

/*
    관련 개념:
    2차원 배열은 행(Row)과 열(Col)로 구성된 표 형태의 메모리 공간이다.
    배열 원소는 data[i][j] 형태로 접근하며, 이중 for문으로 전체를 다룰 수 있다.
    sizeof 연산을 통해 전체 배열 크기, 한 행의 크기, 한 원소의 크기를 확인할 수 있다.

    메모리 동작:
    int data[ROW][COL]은 연속된 메모리 공간에 ROW * COL 개의 int를 저장한다.
    data는 배열 전체의 시작 주소, data[0]은 첫 번째 행의 시작 주소, data[0][0]은 첫 번째 원소이다.
*/

#include <stdio.h>

#define ROW 3
#define COL 2

// 기능명: main. 2차원 배열 선언 및 출력
// 내용: 2차원 배열을 선언하고, 이중 for문을 통해 값을 순서대로 저장한 뒤
//       각 원소를 출력하고 sizeof 연산자로 배열의 크기를 확인한다.
// 입력: 없음
// 출력: 2차원 배열의 모든 원소 및 배열 크기를 콘솔에 출력한다.
// 오류: 없음
int main(void)
{
    int data[ROW][COL]; // 2차원 배열 선언
    int i, j, k;

    for (i = 0, k = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            data[i][j] = ++k; // 배열의 원소에 1씩 증가하는 값 저장
        }
    }

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            printf("%3d ", data[i][j]); // 2차원 배열 원소 출력
        printf("\n");
    }

    printf("sizeof(data) = %d\n", sizeof(data)); // 배열 전체 크기
    printf("sizeof(data[0]) = %d\n", sizeof(data[0])); // 한 행의 크기
    printf("sizeof(data[0][0]) = %d\n", sizeof(data[0][0])); // 한 원소의 크기

    return 0;
}
