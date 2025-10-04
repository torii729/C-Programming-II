/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 1. 등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다.
            크기가 10인 정수형 배열에 대하여 등차수열로 값을 채우려고 한다.
            첫 번째 항의 값과 공차(common difference)를 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오.
    날짜 : 2025.09.16
*/

#define ARR_SIZE 10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fillCD(int arr[], int size, int start, int diff);
int Assign01();
void printArray(int arr[], int size);

// 기능명: main. 등차수열 프로그램 실행
// 내용: Assign01 함수를 호출하여 등차수열을 계산하고 결과를 출력한다.
// 입력: 없음
// 출력: 등차수열의 모든 항을 콘솔에 출력한다.
// 오류: 없음
int main()
{
    return Assign01();
}

// 기능명: Assign01. 입력 및 함수 호출
// 내용: 사용자로부터 첫째 항(start)과 공차(diff)를 입력받아,
//       fillCD로 배열을 채운 뒤 printArray로 출력한다.
// 입력: 사용자로부터 두 정수를 입력받는다.
// 출력: 계산된 등차수열을 콘솔에 출력한다.
// 오류: 없음
int Assign01()
{
    int result[10] = { 0 };
    int start = 0;
    int diff = 0;

    printf("초기값 등차 입력하세요: ");
    scanf("%d %d", &start, &diff);

    fillCD(result, ARR_SIZE, start, diff);
    printArray(result, ARR_SIZE);

    return 0;
}

// 기능명: fillCD. 등차수열 계산
// 내용: 첫째 항(start)과 공차(diff)를 이용해 배열을 등차수열로 채운다.
// 입력: int arr[] (배열), int size (배열 크기), int start (첫째 항), int diff (공차)
// 출력: 없음
// 오류: 없음
void fillCD(int arr[], int size, int start, int diff)
{
    int i;
    arr[0] = start;

    for (i = 1; i < size; i++)
        arr[i] = arr[i - 1] + diff;
}

// 기능명: printArray. 배열 출력
// 내용: 전달받은 배열의 모든 원소를 공백으로 구분하여 출력한다.
// 입력: int arr[] (정수 배열), int size (배열 크기)
// 출력: 배열의 모든 원소를 콘솔에 출력한다.
// 오류: 없음
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
