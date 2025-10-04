/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-1 : 문자열 초기화 및 출력
	날짜 : 2025.09.29
*/

#include <stdio.h>

/*
	기능명: main. 프로그램 시작점
	내용: 문자열 배열의 선언, 초기화, 그리고 출력 방식을 실습한다.
	입력: 없음
	출력: 각 문자열 배열의 내용 및 구조를 콘솔에 출력한다.
	오류: 없음
*/
int main(void)
{
	char str1[10] = { 'a', 'b', 'c' }; // 문자 배열 초기화, 나머지는 '\0' 자동 채움
	char str2[10] = "abc"; // 문자열 리터럴로 초기화 ('a','b','c','\0')
	char str3[] = "abc"; // 크기 자동 계산, 길이는 4 ('a','b','c','\0')
	// char str4[10] = "very long string"; // 배열 크기 초과로 오류 발생

	int size = sizeof(str1) / sizeof(str1[0]); // str1 배열 크기 계산
	int i;

	printf("str1 = ");
	for (i = 0; i < size; i++)
	{
		printf("%c ", str1[i]); // 각 문자 출력 (널 포함)
	}
	printf("\n");

	printf("str2 = %s\n", str2); // 문자열 출력 (널문자 전까지)
	printf("str3 = ");
	printf(str3); // 동일한 효과: printf("%s", str3)
	printf("\n");

	// printf("str4 = %s\n", str4); // 오류 방지

	return 0;
}
