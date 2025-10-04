/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 14. 음악 재생 프로그램에는 재생 목록에 있는 곡들을 임의의 순서로 뒤섞는 셔플 기능이 있다.
        이 셔플 기능처럼 크기가 10인 정수형 배열의 원소를 임의의 순서로 뒤섞는 프로그램을 작성하시오.
        크기가 10인 정수형 배열은 0~99사이의 임의의 정수로 채워서 테스트한다.
    날짜 : 2025.09.16
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int arr[], int size);
void printArray(int arr[], int size);
void shuffleArray(int arr[], int size);

// 기능명: main. 프로그램의 시작점
// 내용: 배열을 생성하고 난수로 초기화한 뒤, 셔플 전후의 결과를 출력한다.
// 입력: 없음
// 출력: 셔플 전후의 배열 상태를 콘솔에 출력한다.
// 오류: 없음
int main()
{
    int arr[10] = { 0 };
    srand(time(NULL)); // 실행 시마다 다른 난수를 발생시키기 위한 시드 설정

    initArray(arr, 10);
    printf("셔플 전 결과 : ");
    printArray(arr, 10);

    shuffleArray(arr, 10);
    printf("셔플 후 결과 : ");
    printArray(arr, 10);

    return 0;
}

// 기능명: initArray. 배열 초기화
// 내용: 배열의 각 원소를 0~99 범위의 난수로 채운다.
// 입력: int arr[] (배열), int size (배열 크기)
// 출력: 없음 (배열 내부 값이 변경됨)
// 오류: 없음
void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

// 기능명: printArray. 배열 출력
// 내용: 배열의 원소를 순서대로 한 줄에 출력한다.
// 입력: int arr[] (배열), int size (배열 크기)
// 출력: 배열의 값을 콘솔에 출력한다.
// 오류: 없음
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 기능명: shuffleArray. 배열 원소 섞기
// 내용: 난수 인덱스를 이용하여 배열의 원소를 무작위로 교환한다.
// 입력: int arr[] (배열), int size (배열 크기)
// 출력: 없음 (배열 내부 순서가 변경됨)
// 오류: 없음
void shuffleArray(int arr[], int size)
{
    for (int i = 0; i < 100; i++)
    {
        int a = rand() % size;
        int b = rand() % size;

        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
