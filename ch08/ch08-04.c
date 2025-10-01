/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch08 PPT 문제 풀이

    예제 8-14 의 데이터 타입들을 int 에서 double 로 변형해서 코딩하고 테스트하기

    날짜 : 2025.09.18
*/

#include <stdio.h>

void get_sum_product(double x, double y, double* sum, double* product);

// 기능명: main. 합과 곱 계산 요청
// 내용: 두 실수 10.5와 20.2를 get_sum_product 함수에 전달하고, 결과를 result1, result2에 받아 출력한다.
// 입력: 없음
// 출력: sum, product의 값
// 오류: 없음
int main(void)
{
    double result1, result2;

    get_sum_product(10.5, 20.2, &result1, &result2);

    printf("sum = %.2f, product = %.2f\n", result1, result2);

    return 0;
}

// 기능명: get_sum_product. 두 수의 합과 곱 계산
// 내용: 두 실수를 받아 합과 곱을 계산하고 포인터 매개변수를 통해 결과 저장
// 입력: double x, double y(계산 대상), double* sum, double* product (결과 저장할 주소)
// 출력: 없음 (결과는 포인터가 가리키는 변수에 저장)
// 오류: sum, product 포인터가 NULL이면 결과 저장 불가
void get_sum_product(double x, double y, double* sum, double* product)
{
    if (sum == NULL || product == NULL)
    {
        // NULL 포인터 체크
        return;
    }

    *sum = x + y;
    *product = x * y;
}