/*
    학번 : 202511204
    이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-12 : 2차원 문자 배열의 선언 및 초기화
    날짜 : 2025.09.29
*/

/*
    관련 개념 :
    2차원 문자 배열은 여러 개의 문자열을 연속된 메모리 공간에 저장할 수 있다.
    islower와 toupper 함수는 각각 문자가 소문자인지 확인하고 대문자로 변환한다.
    문자열은 문자 배열이므로 개별 문자에 직접 접근하여 수정할 수 있다.

    메모리 동작 :
    books 배열은 스택 영역에 고정 크기로 할당된다.
    각 행은 최대 29글자와 널 문자를 포함할 수 있는 문자열을 저장한다.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char books[5][30] = {
        "wonder",
        "me before you",
        "the hunger games",
        "twilight",
        "harry potter",
    };
    int i = 0;

    for (i = 0; i < 5; i++)
        printf("책 제목: %s\n", books[i]); // 원래 문자열 출력

    for (i = 0; i < 5; i++)
    {
        if (islower(books[i][0])) // 첫 글자가 소문자인지 검사
            books[i][0] = toupper(books[i][0]); // 소문자면 대문자로 변환
    }

    puts("<< 변경 후 >>"); // 변환 후 출력 구분선
    for (i = 0; i < 5; i++)
        printf("책 제목: %s\n", books[i]); // 변환된 문자열 출력

    return 0;
}
