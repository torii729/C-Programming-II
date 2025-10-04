/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 강의 실습 (ch11-01.c와 연동하여 extern 사용)
	날짜 : 2025.10.14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_id(void); // static 선언으로 정보 은닉
static int inc_id(int n);
int last_id = 1000;

// 기능명: get_id
// 내용: 1001번부터 차례로 유일한 번호를 증가하면서 반환하는 기능
// 입력: 없음
// 출력: 없음
// 반환값: 1001부터 시작해서 1씩 증가하는 유일한 값
// 오류: 없음
int get_id(void) // 이 함수가 static이면 ch11-01.c에서 접근 불가
{
	last_id = inc_id(last_id);

	return last_id;
}

// 기능명: inc_id
// 내용: 입력된 정수에 1을 더해서 반환
// 입력: 없음
// 출력: 없음
// 반환값: n + 1
// 오류: 없음
int inc_id(int n)
{
	return n + 1;
}
