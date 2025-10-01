/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-11 : 선택 정렬
    날짜 : 2025.09.15
*/

/*
    관련 개념:
    선택 정렬은 배열에서 가장 작은(또는 큰,) 값을 선택하여
    앞쪽부터 차례대로 교환하는 방식으로 동작한다.
    전체를 다 확인하지 않고, 교환 횟수를 줄일 수 있다는 특징이 있다.

    메모리 동작:
    배열 data는 연속된 메모리 공간에 저장된다.
    index는 현재 구간에서 가장 작은 값을 가진 위치를 기억하고,
    temp를 이용해 두 값을 서로 교환한다.
*/

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int data[SIZE] = { 7, 3, 9, 5, 1 }; // 정렬할 배열
    int i, j;
    int index, temp;

    for (i = 0; i < SIZE - 1; i++) {
        index = i; // 가장 작은 원소의 위치를 index에 저장
        for (j = i + 1; j < SIZE; j++) {
            if (data[index] > data[j]) // 더 작은 값 찾으면 index 갱신
                index = j;
        }
        if (i != index) { // 현재 위치와 index 다르면 교환
            temp = data[i];
            data[i] = data[index];
            data[index] = temp;
        }
    }

    printf("정렬 후: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", data[i]); // 정렬된 배열 출력
    printf("\n");

    return 0;
}

