/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch11-08.c와 연동하여 ch11 예제 11-4 : 다른 소스 파일에 정의된 함수의 호출
	날짜 : 2025.10.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_gcd(int x, int y);
extern int get_factorial(int n);

// 기능명: main
// 내용: get_gcd 함수를 호출하여 두 수의 최대공약수를 계산하고, get_factorial 함수를 호출하여 팩토리얼 값을 출력
// 입력: 없음
// 출력: 두 수의 최대공약수와 팩토리얼 값
// 오류: 없음
int main(void)
{
	int i;
	srand((unsigned int)time(NULL));

	// 0~9 사이의 임의의 정수 5개를 생성하여 팩토리얼 출력
	for (i = 0; i < 5; i++)
	{
		int num = rand() % 10;
		printf("%2d! = %7d\n", num, get_factorial(num));
	}

	// 0~99 사이의 임의의 정수 5쌍을 생성하여 최대공약수 출력
	for (i = 0; i < 5; i++)
	{
		int a = rand() % 100;
		int b = rand() % 100;
		printf("%2d와 %2d의 gcd = %2d\n", a, b, get_gcd(a, b));
	}

	return 0;
}