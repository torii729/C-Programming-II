/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch11-04.c와 연동하여 예제 11-1 : 전역 변수의 extern 선언
	날짜 : 2025.10.15
*/

#include <stdio.h>

void test_global(void); // ch11-04.c에 정의된 함수를 호출하려면 함수 선언이 필요하다.

extern int global; // ch11-04.c에 정의된 global 변수를 사용하기 위해 extern 선언한다.

// 기능명: main
// 내용: test_global 함수를 호출하여 global 변수 값을 변경하고 출력
// 입력: 없음
// 출력: 변경된 global 변수 값
// 오류: 없음
int main(void)
{
	test_global();
	printf("global = %d\n", global);

	return 0;
}