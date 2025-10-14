/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch11-07.c와 연동하여 ch11 예제 11-4 : 다른 소스 파일에 정의된 함수의 호출
	날짜 : 2025.10.15
*/

// 기능명: get_gcd
// 내용: 유클리드 알고리즘 사용하여 두 정수 x와 y의 최대공약수를 계산하여 반환
// 입력: 두 정수 x, y
// 출력: 없음
// 반환값: x와 y의 최대공약수
// 오류: x 또는 y가 0일 경우 최대공약수를 계산하지 않음
int get_gcd(int x, int y)
{
	int r;
	while (y != 0)
	{
		r = x % y;
		x = y;
		y = r;
	}

	return x;
}

// 기능명: get_factorial
// 내용: 입력된 정수 n의 팩토리얼(n!) 값을 반복문을 통해 계산하여 반환
// 입력: 정수 n (0 이상)
// 출력: 없음
// 반환값: n! (팩토리얼 값)
// 오류: n이 음수일 경우 팩토리얼을 계산하지 않음
extern int get_factorial(int n)
{
	int i;
	int result = 1;

	for (i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}