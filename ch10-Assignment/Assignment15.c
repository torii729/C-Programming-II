/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 15. POINT 구조체 배열을 x좌표 기준 선택 정렬
    날짜 : 2025.11.23
*/

#include <stdio.h>

typedef struct
{
    int x;
    int y;
} POINT;

void test(void);
void swap_point(POINT* a, POINT* b);
void selection_sort_by_x(POINT arr[], int n);
void print_points(const POINT arr[], int n);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 구조체 배열 정렬 프로그램을 실행한다.
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
    내용: 크기 10의 POINT 배열을 초기화하고 x좌표 기준으로 정렬한다.
    입력: 없음
    출력: 정렬 전후 좌표 출력.
    오류: 없음
*/
void test(void)
{
    POINT arr[10] =
    {
        { 7, 4 }, { 12, 93 }, { 22, 31 }, { 1, 20 }, { 34, 53 },
        { 41, 2 }, { 32, 9 }, { 21, 31 }, { 8, 2 }, { 3, 5 }
    };

    printf("<정렬 전>\n");
    print_points(arr, 10);

    selection_sort_by_x(arr, 10);

    printf("<정렬 후>\n");
    print_points(arr, 10);
}

/*
    기능명: swap_point. POINT 교환
    내용: 두 POINT 값을 서로 바꾼다.
    입력: POINT 포인터 2개.
    출력: 없음
    오류: 없음
*/
void swap_point(POINT* a, POINT* b)
{
    POINT temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
    기능명: selection_sort_by_x. 선택 정렬
    내용: x좌표 오름차순으로 POINT 배열을 선택 정렬한다.
    입력: POINT 배열, 크기 n.
    출력: 없음
    오류: 없음
*/
void selection_sort_by_x(POINT arr[], int n)
{
    int i;
    int j;
    int min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j].x < arr[min_idx].x)
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap_point(&arr[i], &arr[min_idx]);
        }
    }
}

/*
    기능명: print_points. 좌표 출력
    내용: POINT 배열을 (x, y) 형태로 출력한다.
    입력: POINT 배열, 크기 n.
    출력: 좌표 출력.
    오류: 없음
*/
void print_points(const POINT arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("(%d, %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}
