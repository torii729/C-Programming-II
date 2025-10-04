/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 강의 실습 (ch11-02.c와 연동하여 extern 사용)
	날짜 : 2025.10.14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

// 기능명: main
// 내용: get_id 함수를 통해 3명의 회원 id를 출력하고 마지막 id를 출력
// 입력: 없음
// 출력: 3명의 회원 id와 마지막 id
// 오류: 없음
int main(int argc, char* argv[])
{
	printf("너무 졸려요\n");
	printf("회원1의 id = %d\n", get_id());
	printf("회원2의 id = %d\n", get_id());
	printf("회원3의 id = %d\n", get_id());

	printf("마지막 id = %d\n", last_id);
	return 0;
}