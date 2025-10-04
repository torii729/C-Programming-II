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

/*
    기능명: main. 프로그램 시작점
    내용: 2차원 문자 배열에 저장된 책 제목들을 출력하고,
          각 제목의 첫 글자가 소문자일 경우 대문자로 변환한다.
    입력: 없음
    출력: 변환 전후의 책 제목 목록을 콘솔에 출력한다.
    오류: 없음
*/
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

    // 변환 전 책 제목 출력
    for (i = 0; i < 5; i++)
        printf("책 제목: %s\n", books[i]);

    // 각 책 제목의 첫 글자가 소문자라면 대문자로 변환
    for (i = 0; i < 5; i++)
    {
        if (islower(books[i][0]))  // 첫 글자가 소문자인지 검사
            books[i][0] = toupper(books[i][0]);  // 대문자로 변환
    }

    puts("<< 변경 후 >>"); // 변환 후 출력 구분선

    // 변환 완료된 책 제목 출력
    for (i = 0; i < 5; i++)
        printf("책 제목: %s\n", books[i]);

    return 0;
}
