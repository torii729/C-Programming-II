/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 9-13 : 2차원 문자 배열의 정렬
    날짜 : 2025.09.29
*/

/*
    관련 개념 :
    2차원 문자 배열은 문자열 여러 개를 연속된 메모리 공간에 저장한다.
    문자열 비교는 strcmp 함수를 사용하며, 두 문자열을 사전식으로 비교한다.
    문자열 교환은 단순 대입이 불가능하므로 strcpy와 임시 배열을 이용한다.
    선택 정렬 알고리즘을 사용하여 오름차순으로 문자열을 정렬한다.

    메모리 동작 :
    books 배열은 스택 영역에 고정 크기로 할당된다.
    swap_string 함수 내부의 temp 배열도 스택에 할당되며 함수 종료 시 해제된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int swap_string(char* lhs, char* rhs, int size);

#define MAX 5
#define BUF_SZ 30

int main(void)
{
    char books[MAX][BUF_SZ] = {
        "Wonder",
        "Me before you",
        "The hunger games",
        "Twilight",
        "Harry potter",
    };
    int i, j;
    int index;

    puts("<< 정렬 전 >>"); // 정렬 전 책 제목 출력
    for (i = 0; i < MAX; i++)
        puts(books[i]);

    for (i = 0; i < MAX - 1; i++) // 선택 정렬 수행
    {
        index = i; // 현재 위치를 최소값 인덱스로 가정
        for (j = i + 1; j < MAX; j++)
        {
            if (strcmp(books[index], books[j]) > 0) // 더 작은 문자열 찾기
                index = j;
        }
        if (i != index) // 최소값 위치가 바뀌었으면 교환
        {
            swap_string(books[index], books[i], BUF_SZ);
        }
    }

    puts("<< 정렬 후 >>"); // 정렬 후 책 제목 출력
    for (i = 0; i < MAX; i++)
        puts(books[i]);

    return 0;
}

int swap_string(char* lhs, char* rhs, int size)
{
    int lhs_len = strlen(lhs); // lhs 문자열 길이
    int rhs_len = strlen(rhs); // rhs 문자열 길이
    char temp[BUF_SZ] = ""; // 임시 저장 배열

    if (lhs_len + 1 > size || rhs_len + 1 > size) // 크기 초과 검사
        return 0;

    strcpy(temp, lhs); // lhs를 temp로 복사
    strcpy(lhs, rhs); // rhs를 lhs로 복사
    strcpy(rhs, temp); // temp를 rhs로 복사
    return 1; // 교환 성공
}
