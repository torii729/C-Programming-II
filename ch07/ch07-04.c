/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 문제 풀이

    1. 앞에서 구현한 selectionSortInt 함수를 실수에 적용할 수 있도록
    selecttionSortFloat함수로 구현하시오.

    2. 표준 라이브러리의 qsort 함수를 이용하여 실수 배열에 대한 정렬을 하도록 하시오.

    3. 앞에서 구현한 selectionSortInt 함수를 qsort 처럼 임의의 배열에 대해 정렬할 수
    있도록 변경하시오.

    4. 표준 라이브러리의 qsort 함수를 이용하여 연락처 구조체 타입에 대한 정렬 하는
    예시코드를 작성하시오.

    날짜 : 2025.09.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int selecttionSortFloat(float R[], int n);
int qsortfloat(const void* a, const void* b);
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*));
int contactUp(const void* a, const void* b);

// 기능명: main. 테스트 실행
// 내용: 각 문제에서 작성한 함수들의 동작을 확인한다.
// 입력: 없음
// 출력: 없음 (필요 시 각 함수 내에서 결과 출력)
// 오류: 없음
int main(void)
{
    return 0;
}

// 기능명: selecttionSortFloat. 실수 배열 선택 정렬
// 내용: 실수 배열 R을 오름차순으로 선택 정렬한다.
// 입력: float R[] (실수 배열), int n (배열 크기)
// 출력: 정상 실행 시 0 반환
// 오류: 배열 크기가 음수이거나 잘못된 포인터 입력 시 잘못된 동작 가능
int selecttionSortFloat(float R[], int n)
{
    int i = 0;
    int j = 0;
    int m = 0;

    for (i = 0; i < n - 1; i++)
    {
        m = i;

        for (j = i + 1; j < n; j++)
        {
            if (R[j] < R[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            float t = R[i];
            R[i] = R[m];
            R[m] = t;
        }
    }
    return 0;
}

// 기능명: qsortfloat. qsort용 실수 비교 함수
// 내용: qsort에서 사용되는 비교 함수로, 두 실수의 크기를 비교한다.
// 입력: const void* a, const void* b (비교할 두 실수의 주소)
// 출력: 음수(앞이 작을 때), 0(같을 때), 양수(앞이 클 때)
// 오류: 입력 포인터가 NULL이면 잘못된 동작 가능
int qsortfloat(const void* a, const void* b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// 기능명: selectionSortInt. 임의 배열 선택 정렬
// 내용: qsort처럼 작동하는 일반화된 선택 정렬 함수. 
//       cmp 비교 함수가 있으면 그 규칙을 사용해 정렬하고, 없으면 int 기준으로 정렬한다.
// 입력: void* base (배열 시작 주소), int n (요소 개수), int sz (요소 크기),
//       int (*cmp)(void*, void*) (비교 함수 포인터)
// 출력: 정상 실행 시 0 반환
// 오류: 배열 크기 또는 크기 인자 오류 시 비정상 동작 가능
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*))
{
    char* a = (char*)base;

    for (int i = 0; i < n - 1; i++)
    {
        int m = i;

        for (int j = i + 1; j < n; j++)
        {
            void* pj = a + j * sz; // j번째 원소 주소
            void* pm = a + m * sz; // 현재 최소값 주소

            int c = 0;

            if (cmp)
            {
                c = cmp(pj, pm);
            }
            else
            {
                int x = *(int*)pj;
                int y = *(int*)pm;

                if (x < y) c = -1;
                else if (x > y) c = 1;
                else c = 0;
            }

            if (c < 0) m = j;
        }

        if (m != i)
        {
            for (int k = 0; k < sz; k++)
            {
                char* p = a + i * sz + k;
                char* q = a + m * sz + k;
                char t = *p; *p = *q; *q = t;
            }
        }
    }
    return 0;
}

// 기능명: contactUp. qsort용 구조체 비교 함수
// 내용: Contact 구조체 배열을 이름(name) 기준으로 오름차순 정렬하기 위한 비교 함수.
// 입력: const void* a, const void* b (비교할 두 구조체 주소)
// 출력: strcmp 결과값 (음수/0/양수) - 문자열 사전순 기준
// 오류: 입력 포인터가 NULL이면 잘못된 동작 가능
int contactUp(const void* a, const void* b)
{
    const Contact* x = (const Contact*)a;
    const Contact* y = (const Contact*)b;

    return strcmp(x->name, y->name);
}
