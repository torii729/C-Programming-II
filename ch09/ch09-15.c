/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 9-13 : 2차원 문자 배열의 정렬
    날짜 : 2025.09.29
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

    puts("<< 정렬 전 >>");
    for (i = 0; i < MAX; i++)
        puts(books[i]);

    for (i = 0; i < MAX - 1; i++)
    {
        index = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (strcmp(books[index], books[j]) > 0)
                index = j;
        }
        if (i != index)
        {
            swap_string(books[index], books[i], BUF_SZ);
        }
    }

    puts("<< 정렬 후 >>");
    for (i = 0; i < MAX; i++)
        puts(books[i]);

    return 0;
}

int swap_string(char* lhs, char* rhs, int size)
{
    int lhs_len = strlen(lhs);
    int rhs_len = strlen(rhs);
    char temp[BUF_SZ] = "";

    if (lhs_len + 1 > size || rhs_len + 1 > size)
        return 0;

    strcpy(temp, lhs);
    strcpy(lhs, rhs);
    strcpy(rhs, temp);
    return 1;
}
