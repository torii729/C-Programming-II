/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-14 : print_array 함수의 정의 및 호출
    날짜 : 2025.09.15
*/

#include <stdio.h>
#define MAX 10

void print_array(int arr[], int size); // 배열의 원소를 출력하는 함수 원형

int main(void)
{
    int scores[] = { 99, 98, 67, 72, 90, 82 }; // 크기 6의 배열 초기화
    int size = sizeof(scores) / sizeof(scores[0]); // 배열 원소 개수 계산
    int arr[MAX] = { 0 }; // 크기 10 배열 초기화 (모두 0)

    print_array(scores, size); // 배열 scores 출력
    print_array(arr, MAX); // 배열 arr 출력

    return 0;
}

void print_array(int arr[], int size) // 배열과 크기를 전달받아 출력
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
