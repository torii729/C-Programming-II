/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 1. 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램. 주소 구하기 연산자를 사용하지 마시오.
    날짜 : 2025.09.22
*/

#include <stdio.h>

void test(void);

// 기능명: main. 프로그램 시작점
// 내용: test 함수를 호출하여 배열 원소의 주소를 출력한다.
// 입력: 없음
// 출력: double 배열의 각 원소 주소를 콘솔에 출력한다.
// 오류: 없음
int main(void)
{
    test();
    return 0;
}

// 기능명: test. double 배열 주소 출력
// 내용: 크기가 3인 double형 배열을 선언하고, 주소 연산자 없이 각 원소의 주소를 출력한다.
// 입력: 없음
// 출력: 배열 각 원소의 주소를 콘솔에 출력한다.
// 오류: 없음
void test(void)
{
    double x[3] = { 1.1, 2.2, 3.3 };

    printf("x[0] 주소: %p\n", (void*)(x + 0));
    printf("x[1] 주소: %p\n", (void*)(x + 1));
    printf("x[2] 주소: %p\n", (void*)(x + 2));

    // double형은 8바이트이므로 주소 간격이 sizeof(double)만큼 증가한다.
}
