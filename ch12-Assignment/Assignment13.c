/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 13. 정수의 개수 N을 입력받아 int가 N개 들어갈 수 있는 동적 메모리를 할당받는다. 
        이 배열에 임의의 정수를 N개 생성해서 채운 다음 텍스트 파일과 2진 파일로 각각 저장하는 프로그램을 작성하시오. 
        2진 파일로 저장할 때는 N을 먼저 저장하고, 배열의 내용을 저장하시오. 
        저장된 파일을 문서 편집기에서 열어서 내용을 확인해보고 파일의 크기도 비교해본다.
    날짜 : 2025.11.9
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void test(void);
void fill_random_ints(int* arr, int n);
int  save_as_text(const char* filename, const int* arr, int n);
int  save_as_binary(const char* filename, const int* arr, int n);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 정수 배열을 파일로 저장하는 기능을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{

    test();
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 정수의 개수와 파일 기본 이름을 입력받아
          임의의 정수 배열을 생성하고, 텍스트 파일과 2진 파일로 저장한다.
    입력: 콘솔에서 정수 N과 파일 기본 이름 문자열을 입력받는다.
    출력: 파일 생성 성공 여부를 콘솔에 출력한다.
    오류: 잘못된 N 입력, 메모리 할당 실패, 파일 생성 실패 시 오류 메시지를 출력한다.
*/
void test(void)
{
    int n;
    int* arr = NULL;
    char base[100];
    char txtname[120];
    char datname[120];
    int ok_text, ok_bin;

    printf("정수의 개수? ");
    if (scanf_s("%d", &n) != 1 || n <= 0)
    {
        printf("정수의 개수가 올바르지 않습니다.\n");
        return;
    }

    printf("파일명? ");
    if (scanf_s("%s", base, sizeof(base)) != 1)
    {
        printf("파일명을 읽을 수 없습니다.\n");
        return;
    }

    arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        return;
    }

    fill_random_ints(arr, n);

    strcpy(txtname, base);
    strcat(txtname, ".txt");

    strcpy(datname, base);
    strcat(datname, ".dat");

    ok_text = save_as_text(txtname, arr, n);
    ok_bin = save_as_binary(datname, arr, n);

    if (ok_text && ok_bin)
    {
        printf("%s와 %s를 생성했습니다.\n", txtname, datname);
    }
    else
    {
        printf("파일을 제대로 생성하지 못했습니다.\n");
    }

    free(arr);
}

/*
    기능명: fill_random_ints. 임의의 정수 채우기
    내용: 난수를 이용해 정수 배열에 임의의 값을 채운다.
    입력: int 배열 포인터, 배열 크기 n.
    출력: 배열 각 요소가 0 이상 999 이하의 임의의 정수로 채워진다.
    오류: 없음
*/
void fill_random_ints(int* arr, int n)
{
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
}

/*
    기능명: save_as_text. 텍스트 파일로 저장
    내용: 정수 배열의 내용을 사람이 읽을 수 있는 텍스트 형식으로 파일에 저장한다.
    입력: 파일 이름 문자열, int 배열 포인터, 배열 크기 n.
    출력: 저장 성공 시 1, 실패 시 0을 반환한다.
    오류: 파일을 열지 못하면 0을 반환하고 오류 메시지를 출력한다.
*/
int save_as_text(const char* filename, const int* arr, int n)
{
    FILE* fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("텍스트 파일을 열 수 없습니다.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
    return 1;
}

/*
    기능명: save_as_binary. 2진 파일로 저장
    내용: 정수 개수 N과 정수 배열 내용을 2진 형식으로 파일에 저장한다.
    입력: 파일 이름 문자열, int 배열 포인터, 배열 크기 n.
    출력: 저장 성공 시 1, 실패 시 0을 반환한다.
    오류: 파일을 열지 못하면 0을 반환하고 오류 메시지를 출력한다.
*/
int save_as_binary(const char* filename, const int* arr, int n)
{
    FILE* fp;

    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("2진 파일을 열 수 없습니다.\n");
        return 0;
    }
    fwrite(&n, sizeof(int), 1, fp);


    fwrite(arr, sizeof(int), n, fp);

    fclose(fp);
    return 1;
}