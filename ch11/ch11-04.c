/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch11-03.c와 연동하여 예제 11-1 : 전역 변수의 extern 선언
	날짜 : 2025.10.15
*/

#include <stdio.h>

int global = 123;

// 기능명: test_global
// 내용: global 변수를 1 증가시킨다.
// 입력: 없음
// 출력: 없음
// 오류: 없음
void test_global(void)
{
	global++;
}