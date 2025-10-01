/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch08 PPT 예제 8-14 : 함수의 처리 결과를 매개변수로 전달하는 경우
    날짜 : 2025.09.18
*/

/*
    관련 개념:
    C 언어 함수는 여러 개의 값을 반환할 수 없다. 따라서 여러 결과를 돌려받으려면
    포인터 매개변수를 사용하여 결과를 호출한 쪽 변수에 직접 저장해야 한다.
    이 예제에서는 합(sum)과 곱(product)을 동시에 반환한다.

    메모리 동작:
    get_sum_product 함수는 sum, product 변수의 주소를 인자로 받는다.
    함수 내부에서 *sum, *product로 접근하면 main의 result1, result2 값이 직접 변경된다.
*/

#include <stdio.h>

// 기능명: main. 합과 곱 계산 요청
// 내용: 두 정수 10과 20을 get_sum_product 함수에 전달하고,
//       결과를 result1, result2에 받아 출력한다.
// 입력: 없음
// 출력: sum, product의 값
// 오류: 없음
int main(void)
{
    int result1, result2;

    get_sum_product(10, 20, &result1, &result2); // 결과를 저장할 변수 주소 전달
    printf("sum = %d, product = %d\n", result1, result2);

    return 0; // 정상 종료
}

// 기능명: get_sum_product. 두 수의 합과 곱 계산
// 내용: 두 정수를 받아 합과 곱을 계산하고 포인터 매개변수를 통해 결과 저장
// 입력: int x, int y (계산 대상), int* sum, int* product (결과 저장할 주소)
// 출력: 없음 (결과는 포인터가 가리키는 변수에 저장)
// 오류: sum, product 포인터가 NULL이면 결과 저장 불가
void get_sum_product(int x, int y, int* sum, int* product)
{
    *sum = x + y; // 합 저장
    *product = x * y; // 곱 저장
}
