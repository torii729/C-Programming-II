/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch11 예제 11-5 : 재귀 함수의 정의 및 호출
	날짜 : 2025.10.15
*/

#include <stdio.h>

int get_factorial(int n);

// 기능명: main
// 내용: 사용자로부터 정수를 입력받아 get_factorial 함수를 호출하여 팩토리얼 값을 출력
// 입력: 없음
// 출력: 입력된 정수의 팩토리얼 값
// 오류: 음수가 입력되면 팩토리얼을 계산하지 않음
int main(void)
{
	int i;
	
	for (i = 0; i <= 10; i++)
	{
		printf("%2d! = %7d\n", i, get_factorial(i));
	}

	return 0;
}

// 기능명: get_factorial
// 내용: 재귀 호출을 통해 입력된 정수 n의 팩토리얼(n!) 값을 계산하여 반환
// 입력: 정수 n (0 이상)
// 출력: 없음
// 반환값: n! (팩토리얼 값)
// 오류: n이 음수일 경우 팩토리얼을 계산하지 않음
int get_factorial(int n)
{
	if (n <= 1)
		return 1;
	
	return n * get_factorial(n - 1);
}