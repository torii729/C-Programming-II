/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch11 예제 11-2 : static 지역 변수
	날짜 : 2025.10.15
*/

#include <stdio.h>

// 기능명: test_static
// 내용: 지역 변수와 static 지역 변수의 차이를 보여준다.
// 입력: 없음
// 출력: 지역 변수와 static 지역 변수의 현재 값
// 오류: 없음
void test_static(void)
{
	int local = 0; // 함수가 호출될 때마다 생성
	static int s_local = 0; // 프로그램 시작 시 생성

	printf("local = %d, ", local++);
	printf("s_local = %d\n", s_local++);
}

// 기능명: main
// 내용: test_static 함수를 여러 번 호출하여 지역 변수와 static 지역 변수의 값을 관찰
// 입력: 없음
// 출력: 각 호출 시점의 지역 변수와 static 지역 변수 값
// 오류: 없음
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		test_static();
	}

	return 0;
}
