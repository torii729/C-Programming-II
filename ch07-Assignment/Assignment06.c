/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 6. 크기가 10인 실수형 배열에 대해서 원소들을 역순으로 만드는 프로그램을 작성하시오.
		실수형 배열의 초기값은 마음대로 정하시오.
	날짜 : 2025.09.16
*/

#include <stdio.h>

void array();
void printArray(double arrayDouble[], int size);
void ArrayRe(double arrayDouble[], int size);

// 기능명: main. 프로그램 시작점
// 내용: array 함수를 호출하여 배열을 초기화하고,
//       역순 변환 및 출력 과정을 수행한다.
// 입력: 없음
// 출력: 원본 배열과 역순 배열을 콘솔에 출력한다.
// 오류: 없음
int main()
{
	array();
	return 0;
}

// 기능명: array. 배열 초기화 및 역순 처리
// 내용: 실수형 배열을 초기화하고, printArray로 원본 배열을 출력한 후
//       ArrayRe를 호출하여 배열을 역순으로 만든 뒤 다시 출력한다.
// 입력: 없음
// 출력: 원본 배열과 역순 배열을 콘솔에 출력한다.
// 오류: 없음
void array()
{
	double arrayDouble[10] = { 1.2, 3.1, 4.3, 4.5, 6.7, 2.3, 8.7, 9.5, 2.3, 5.8 };
	int size = sizeof(arrayDouble) / sizeof(arrayDouble[0]);

	printf("배열 : ");
	printArray(arrayDouble, size);

	ArrayRe(arrayDouble, size);

	printf("역순 : ");
	printArray(arrayDouble, size);
}

// 기능명: printArray. 배열 출력
// 내용: 전달받은 실수형 배열의 원소를 순서대로 출력한다.
// 입력: double arrayDouble[] (실수형 배열), int size (배열 크기)
// 출력: 배열의 모든 원소를 콘솔에 소수점 첫째 자리까지 출력한다.
// 오류: 없음
void printArray(double arrayDouble[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%.1lf ", arrayDouble[i]); // 소수점 첫째 자리까지 출력
	printf("\n");
}

// 기능명: ArrayRe. 배열 역순 변환
// 내용: 배열의 앞과 뒤 원소를 교환하여 전체 배열을 역순으로 만든다.
// 입력: double arrayDouble[] (실수형 배열), int size (배열 크기)
// 출력: 없음 (배열 자체가 수정됨)
// 오류: 없음
void ArrayRe(double arrayDouble[], int size)
{
	for (int a = 0; a < (size / 2); a++)
	{
		double base = arrayDouble[a];
		arrayDouble[a] = arrayDouble[size - 1 - a];
		arrayDouble[size - 1 - a] = base;
	}
}
