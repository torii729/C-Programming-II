/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-5 : 문자열 연결 (strcat)
	날짜 : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char sentence[100] = ""; // 완성될 문장을 저장할 배열 (처음은 빈 문자열)
    char word[20]; // 입력받은 단어를 저장할 배열

    do {
        printf("단어? "); // 단어 입력 요청
        scanf("%s", word); // 단어 입력받음

        strcat(sentence, word); // sentence 끝에 입력된 단어 추가
        strcat(sentence, " "); // 단어 뒤에 공백 추가 (단어 구분용)

    } while (strcmp(word, ".") != 0); // 입력된 단어가 "."이 아닐 때 반복

    printf("%s\n", sentence); // 완성된 문장을 출력

    return 0;
}

