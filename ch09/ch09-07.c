/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-5 : 문자열 연결 (strcat)
	날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
	기능명: main. 프로그램 시작점
	내용: 단어를 반복 입력받아 하나의 문장으로 연결하는 프로그램이다.
		  strcat 함수를 사용해 sentence 뒤에 단어를 이어 붙이고,
		  "."이 입력될 때까지 반복한다.
	입력: 문자열 여러 개 (공백 없이)
	출력: 입력된 단어들을 연결한 문장
	오류: 없음
*/
int main(void)
{
	char sentence[100] = ""; // 완성될 문장을 저장할 배열 (빈 문자열로 초기화)
	char word[20]; // 입력받은 단어를 저장할 배열

	do {
		printf("단어? "); // 단어 입력 요청
		scanf("%s", word); // 단어 입력받음

		strcat(sentence, word); // sentence 끝에 단어 연결
		strcat(sentence, " "); // 단어 뒤에 공백 추가

	} while (strcmp(word, ".") != 0); // 입력이 "."이 아닐 때 반복

	printf("%s\n", sentence); // 완성된 문장 출력

	return 0; // 프로그램 종료
}
