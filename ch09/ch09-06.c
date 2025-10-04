/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-4 : 문자열 비교 (strcmp)
	날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 10

/*
	기능명: main. 프로그램 시작점
	내용: 문자열 비교 함수 strcmp의 동작을 실습한다.
		  두 문자열이 동일한지, 다른지를 비교하고 결과를 출력한다.
	입력: 문자열 1개 (비밀번호)
	출력: 문자열 비교 결과 및 로그인 성공/실패 메시지를 콘솔에 출력한다.
	오류: 없음
*/
int main(void)
{
	char s1[SIZE] = "apple"; // s1에 "apple" 저장
	char s2[SIZE] = "apple"; // s2에도 "apple" 저장
	char password[SIZE]; // 비밀번호 입력 받을 배열

	// if (s1 == s2)는 문자열 내용을 비교하지 않고 '주소'만 비교하므로 항상 false
	if (s1 == s2)
		printf("same address\n");

	// strcmp(s1, s2) == 0 → 두 문자열 내용이 같으면 0 반환
	if (strcmp(s1, s2) == 0)
		printf("same string\n");

	printf("패스워드? "); // 비밀번호 입력 요청
	scanf("%s", password); // 비밀번호 입력 받음

	// 입력된 password와 "abcd1234" 비교
	if (strcmp(password, "abcd1234") == 0)
		printf("login succeeded\n"); // 문자열 같으면 로그인 성공
	else
		printf("login failed\n"); // 다르면 로그인 실패

	return 0; // 프로그램 종료
}
