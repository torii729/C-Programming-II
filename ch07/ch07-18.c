/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-15 : copy_array 함수의 정의 및 호출
    날짜 : 2025.09.15
*/

#include <stdio.h>
#define SIZE 7

void copy_array(int source[], int target[], int size); // 배열 복사 함수 원형
void print_array(int arr[], int size); // 배열 출력 함수 원형

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

void copy_array(int source[], int target[], int size) // 배열 복사 함수
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i]; // 원소 하나씩 복사
}

void print_array(int arr[], int size) // 배열 출력 함수
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
