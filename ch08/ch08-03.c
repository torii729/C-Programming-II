/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch08 PPT 문제 풀이
    
    예제 8-13 의 데이터 타입들을 int 에서 double 로 변형해서 코딩하고 테스트하기
    void * swap(double * a, double * b)
    단, 포인터가 NULL인지 테스트할 것
    반환 값: a 또는 b 포인터가 NULL이면 NULL, 그렇지 않으면 a 값을 반환

    날짜 : 2025.09.18
*/

#include <stdio.h>

void* swap(double* a, double* b);

// 기능명: main. swap 함수 호출
// 내용: 두 실수 a, b를 선언하고 swap 함수를 호출하여 값이 교환됨을 확인한다.
// 입력: 없음
// 출력: swap 전과 후의 a, b 값
// 오류: 없음
int main(void)
{
    double x = 3.3, y = 7.7;

    printf("전 : x = %.1f, y = %.1f\n", x, y);

    // 정상 교환
    if (swap(&x, &y) == NULL)
        printf("스왑 실패\n");
    else
        printf("후 :  x = %.1f, y = %.1f\n", x, y);

    // NULL 테스트
    if (swap(NULL, &y) == NULL)
        printf("스왑 실패\n");

    return 0;
}

// 기능명: swap. 두 실수 값 교환
// 내용: 두 실수의 주소를 받아(포인터) 값을 서로 교환한다.
// 입력: 없음
// 출력: 없음 (원본 값이 직접 변경됨)
// 오류: 전달된 포인터가 NULL일 경우 동작 보장되지 않음
void* swap(double* a, double* b)
{
    if (a == NULL || b == NULL)  // NULL 포인터 체크
        return NULL;

    double temp = *a;
    *a = *b;
    *b = temp;

    return a;   // 문제 조건: a 반환
}