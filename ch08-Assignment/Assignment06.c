/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 6. 정수형 배열에 대하여 배열의 원소 중 최댓값과 최솟값을 찾는 get_min_max 함수를 정의하시오.
        크기가 10인 int 배열에 대해서 원하는 값으로 초기값을 채운 다음 get_min_max 함수로 최댓값과 최솟값을 찾아서 출력하시오.
    날짜 : 2025.09.22
*/

#include <stdio.h>

void test(void);
void get_min_max(int a[], int n, int* pmax, int* pmin);

// 기능명: main. 프로그램 시작점
// 내용: test 함수를 호출하여 배열의 최댓값과 최솟값을 출력한다.
// 입력: 없음
// 출력: 배열과 최댓값, 최솟값을 콘솔에 출력한다.
// 오류: 없음
int main(void)
{
    test();
    return 0;
}

/*
    기능명: get_min_max. 배열 내 최댓값 및 최솟값 계산
    내용: 정수형 배열을 순회하며 최댓값과 최솟값을 찾아 외부 변수(pmax, pmin)에 저장한다.
    입력: int a[] (배열), int n (크기), int* pmax (최댓값 저장 주소), int* pmin (최솟값 저장 주소)
    출력: 없음 (결과는 포인터를 통해 반환됨)
    오류: 배열 크기가 0 이하인 경우 함수 즉시 종료
*/
void get_min_max(int a[], int n, int* pmax, int* pmin)
{
    int i = 0;

    if (n <= 0)
    {
        return;
    }

    *pmax = a[0];
    *pmin = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > *pmax)
        {
            *pmax = a[i];
        }
        if (a[i] < *pmin)
        {
            *pmin = a[i];
        }
    }
}

/*
    기능명: test. get_min_max 함수 테스트
    내용: 크기가 10인 정수 배열을 초기화하고, get_min_max 함수를 호출하여 최댓값과 최솟값을 출력한다.
    입력: 없음
    출력: 배열 전체, 최댓값, 최솟값을 콘솔에 출력한다.
    오류: 없음
*/
void test(void)
{
    int a[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int n = 10;
    int maxv = 0;
    int minv = 0;
    int i = 0;

    printf("배열: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    get_min_max(a, n, &maxv, &minv);

    printf("최댓값: %d\n", maxv);
    printf("최솟값: %d\n", minv);
}
