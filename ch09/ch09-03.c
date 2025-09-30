/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-1 : 문자열 초기화 및 출력
	날짜 : 2025.09.29
*/

#include <stdio.h>

int main(void)
{
	char str1[10] = { 'a', 'b', 'c' }; // 배열에 'a','b','c' 문자 저장, 나머지는 '\0'으로 채워짐
	char str2[10] = "abc"; // 문자열 "abc" 저장됨 ('a','b','c','\0', 나머지는 '\0')
	char str3[] = "abc"; // 크기를 자동 계산, 길이 4 ('a','b','c','\0')
	// char str4[10] = "very long string"; // 문자열이 너무 길어서 배열 크기 초과 → 오류남

	int size = sizeof(str1) / sizeof(str1[0]); // 배열 str1의 원소 개수(=10) 구함
	int i;

	printf("str1 = "); // str1 내용 출력
	for (i = 0; i < size; i++)
	{
		printf("%c ", str1[i]); // str1의 각 요소를 문자로 출력 (빈칸 포함)
	}
	printf("\n");

	printf("str2 = %s\n", str2); // 문자열 출력 (널문자 만날 때까지)
	printf("str3 = "); // str3 출력 안내
	printf(str3); // 문자열 그대로 출력 (printf("%s", str3)와 동일)
	printf("\n");

	// printf("str4 = %s\n", str4); // 오류 나는 코드라서 주석 처리됨

	return 0; // 프로그램 종료
}
