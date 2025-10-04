/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-14 : print_array 함수의 정의 및 호출
    날짜 : 2025.09.15
*/

#include <stdio.h>
#define MAX 10

void print_array(int arr[], int size); // 함수 원형 선언

// 기능명: main. 배열 출력 함수 호출
// 내용: 두 개의 배열(scores, arr)을 선언 및 초기화하고,
//       print_array 함수를 호출하여 각 배열의 내용을 출력한다.
// 입력: 없음
// 출력: 두 배열의 모든 원소를 콘솔에 출력한다.
// 오류: 없음
int main(void)
{
    int scores[] = { 99, 98, 67, 72, 90, 82 }; // 크기 6의 배열 초기화
    int size = sizeof(scores) / sizeof(scores[0]); // 배열 원소 개수 계산
    int arr[MAX] = { 0 }; // 크기 10 배열 초기화 (모두 0)

    print_array(scores, size); // 배열 scores 출력
    print_array(arr, MAX); // 배열 arr 출력

    return 0;
}

// 기능명: print_array. 배열 출력 구현부
// 내용: 배열과 그 크기를 전달받아 모든 원소를 순서대로 출력한다.
// 입력: int arr[] (정수 배열), int size (배열 크기)
// 출력: 배열의 모든 원소를 콘솔에 출력한다.
// 오류: 없음
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]); // 배열 원소 출력
    printf("\n");
}
