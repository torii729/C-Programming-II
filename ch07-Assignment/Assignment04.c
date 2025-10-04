/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 4. 특정 값으로 초기화된 정수형 배열에 대하여 배열의 원소 중 최댓값을 가진 원소와
		최솟값을 가진 원소를 찾아서 인덱스와 값을 함께 출력하는 프로그램을 작성하시오.
		배열의 초기값은 마음대로 정하시오.
	날짜 : 2025.09.16
*/

/*
	핵심 문제:
	최댓값과 최솟값을 어떻게 알아낼 것인가?
	인덱스 출력하는 방법은 무엇인가?
*/

#include <stdio.h>

void array();
void maxArray(int arrayInt[], int size);
void minArray(int arrayInt[], int size);
void printArray(int arrayInt[], int size);

// 기능명: main. 프로그램 시작점
// 내용: array 함수를 호출하여 배열을 초기화하고, 최댓값과 최솟값을 계산한다.
// 입력: 없음
// 출력: 배열, 최댓값, 최솟값을 콘솔에 출력한다.
// 오류: 없음
int main()
{
	array();
	return 0;
}

// 기능명: array. 배열 초기화 및 처리
// 내용: 정수 배열을 선언하고 초기화한 뒤, printArray, maxArray, minArray 함수를 호출한다.
// 입력: 없음
// 출력: 배열 내용, 최댓값, 최솟값을 콘솔에 출력한다.
// 오류: 없음
void array()
{
	int arrayInt[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
	int size = sizeof(arrayInt) / sizeof(arrayInt[0]);

	printArray(arrayInt, size);
	maxArray(arrayInt, size);
	minArray(arrayInt, size);
}

// 기능명: printArray. 배열 출력
// 내용: 전달받은 배열의 모든 원소를 순서대로 출력한다.
// 입력: int arrayInt[] (정수 배열), int size (배열 크기)
// 출력: 배열의 모든 원소를 콘솔에 출력한다.
// 오류: 없음
void printArray(int arrayInt[], int size)
{
	printf("배열 : ");
	for (int n = 0; n < size; n++)
	{
		printf("%d ", arrayInt[n]);
	}
	printf("\n");
}

// 기능명: maxArray. 배열의 최댓값 탐색
// 내용: 배열 내 최댓값과 그 인덱스를 찾아 출력한다.
// 입력: int arrayInt[] (정수 배열), int size (배열 크기)
// 출력: 최댓값과 해당 인덱스를 콘솔에 출력한다.
// 오류: 없음
void maxArray(int arrayInt[], int size)
{
	int max = arrayInt[0];
	int maxIndex = 0;

	for (int i = 1; i < size; i++)
	{
		if (arrayInt[i] > max)
		{
			max = arrayInt[i];
			maxIndex = i; // 최댓값 발생 시 현재 인덱스를 저장
		}
	}

	printf("최댓값 : 인덱스 = %d, 값 = %d\n", maxIndex, max);
}

// 기능명: minArray. 배열의 최솟값 탐색
// 내용: 배열 내 최솟값과 그 인덱스를 찾아 출력한다.
// 입력: int arrayInt[] (정수 배열), int size (배열 크기)
// 출력: 최솟값과 해당 인덱스를 콘솔에 출력한다.
// 오류: 없음
void minArray(int arrayInt[], int size)
{
	int min = arrayInt[0];
	int minIndex = 0;

	for (int j = 1; j < size; j++)
	{
		if (arrayInt[j] < min)
		{
			min = arrayInt[j];
			minIndex = j;
		}
	}

	printf("최솟값 : 인덱스 = %d, 값 = %d", minIndex, min);
}
