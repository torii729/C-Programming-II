/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch08 PPT 예제 8-1 : 포인터의 바이트 크기 구하기
    날짜 : 2025.09.18
*/

/*
    관련 개념 :
    포인터는 변수의 주소(메모리 위치)를 저장하는 자료형이다.
    포인터의 크기는 가리키는 데이터형(int, double, char 등)과 상관없이 동일하다.
    32비트 시스템에서는 4바이트, 64비트 시스템에서는 8바이트가 된다.

    메모리 동작 :
    int *pi → int형 변수의 주소를 저장
    double *pd → double형 변수의 주소를 저장
    char *pc → char형 변수의 주소를 저장
*/

#include <stdio.h>

// 기능명: main. 프로그램 시작점
// 내용: 포인터 변수와 기본 자료형의 크기를 출력한다.
// 입력: 없음
// 출력: 포인터 크기 및 자료형 크기 (정수 값)
// 오류: 없음
int main(void)
{
    int* pi; // int형 포인터
    double* pd; // double형 포인터
    char* pc; // char형 포인터

    printf("sizeof(pi) = %zd\n", sizeof(pi)); // int형 포인터 크기
    printf("sizeof(pd) = %zd\n", sizeof(pd)); // double형 포인터 크기
    printf("sizeof(pc) = %zd\n", sizeof(pc)); // char형 포인터 크기

    printf("sizeof(int) = %zd\n", sizeof(int)); // int형 변수 크기
    printf("sizeof(double) = %zd\n", sizeof(double)); // double형 변수 크기
    printf("sizeof(char*) = %zd\n", sizeof(char*)); // char* 타입 크기

    return 0;
}