/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-15 : copy_array 함수의 정의 및 호출
    날짜 : 2025.09.15
*/

#include <stdio.h>
#define SIZE 7

void copy_array(int source[], int target[], int size); // 함수 원형
void print_array(int arr[], int size); // 함수 원형

// 기능명: main. 배열 복사 및 출력
// 내용: 원본 배열 x를 선언하고, copy_array 함수를 이용해 배열 y로 복사한다.
//       print_array 함수를 호출해 두 배열의 내용을 출력한다.
// 입력: 없음
// 출력: 복사 전후의 배열 내용을 콘솔에 출력한다.
// 오류: 없음
int main(void)
{
    int x[SIZE] = { 10, 20, 30, 40, 50 }; // 원본 배열
    int y[SIZE] = { 0 }; // 대상 배열 (초기값 0)

    printf("x = ");
    print_array(x, SIZE); // 배열 x 출력
    copy_array(x, y, 5); // 배열 x의 앞 5개 원소를 y로 복사
    printf("y = ");
    print_array(y, SIZE); // 배열 y 출력

    return 0;
}

// 기능명: copy_array. 배열 복사 함수
// 내용: source 배열의 원소를 target 배열로 순서대로 복사한다.
// 입력: int source[] (원본 배열), int target[] (복사 대상 배열), int size (복사할 크기)
// 출력: 없음
// 오류: size가 배열 크기를 초과하면 잘못된 메모리 접근 가능
void copy_array(int source[], int target[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i]; // 원소 하나씩 복사
}

// 기능명: print_array. 배열 출력 함수
// 내용: 전달받은 배열의 모든 원소를 순서대로 출력한다.
// 입력: int arr[] (정수 배열), int size (배열 크기)
// 출력: 배열의 모든 원소를 콘솔에 출력한다.
// 오류: 없음
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
