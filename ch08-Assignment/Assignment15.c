/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 15. 7장의 선택 정렬 코드를 이용해서 정수형 배열을 정렬하는 sort_array 함수를 정의하시오.
        크기가 10인 int 배열에 0~99 사이의 임의의 정수를 채운 다음 sort_array 함수로 정렬한 결과를 출력하는 프로그램을 작성.
    날짜 : 2025.09.22
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    기능명: main. 프로그램 시작점
    내용: test 함수를 호출하여 난수를 생성하고 선택 정렬 결과를 출력한다.
    입력: 없음
    출력: 정렬 전/후 배열을 콘솔에 출력한다.
    오류: 없음
*/
int main(void)
{
    test();
    return 0;
}

/*
    기능명: sort_array. 선택 정렬 수행
    내용: 배열을 오름차순으로 정렬한다. i 위치를 고정하고, 그 뒤에서 가장 작은 값을 찾아 교환한다.
    입력: int a[] (정렬할 배열), int n (배열의 크기)
    출력: 없음 (배열이 정렬된 상태로 변경됨)
    오류: 없음
*/
void sort_array(int a[], int n)
{
    int i = 0;

    for (i = 0; i < n - 1; i++)
    {
        int m = i;
        int j = 0;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }

        if (m != i)
        {
            int tmp = a[i];
            a[i] = a[m];
            a[m] = tmp;
        }
    }
}

/*
    기능명: test. sort_array 함수 테스트
    내용: 크기 10의 정수 배열을 난수로 초기화한 뒤, sort_array를 호출하여 정렬 전후 상태를 출력한다.
    입력: 없음
    출력: 정렬 전과 정렬 후 배열을 콘솔에 출력한다.
    오류: 없음
*/
void test(void)
{
    int a[10] = { 0 };
    int n = 10;
    int i = 0;

    srand((unsigned)time(NULL)); // 실행할 때마다 다른 난수가 나오게 시드 설정 

    /* 0~99 범위의 난수로 배열 채우기 */
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    printf("정렬 전: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    sort_array(a, n);

    printf("정렬 후: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}
