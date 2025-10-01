/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-5 : 배열의 원소가 변수로서 사용되는 경우
    날짜 : 2025.09.15
*/

/*
    관련 개념:
    배열은 원소를 인덱스로 접근해 직접 값 대입, 수식 계산, 함수 인자로 활용할 수 있다.
    배열 원소의 주소를 scanf에 넘겨주면 입력값을 배열에 직접 저장할 수 있다.
    {0} 초기화는 배열 전체를 0으로 세팅한다.

    메모리 동작:
    int arr[ARR_SIZE]는 스택에 int 5개를 연속적으로 할당한다.
    arr[0], arr[1]은 직접 대입으로 값이 저장되고 arr[2]는 함수 호출 결과가 저장된다.
    arr[3], arr[4]는 scanf에서 주소를 통해 입력된 값이 저장된다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_SIZE 5

int add(int a, int b);

int add(int a, int b) { return a + b; }

int main(void)
{
    int arr[ARR_SIZE] = { 0 }; // 배열 전체를 0으로 초기화
    int i;

    arr[0] = 5; // 직접 대입
    arr[1] = arr[0] + 10; // 기존 원소를 수식에 사용
    arr[2] = add(arr[0], arr[1]); // 함수 인자로 전달하여 계산 결과 저장

    printf("정수를 2개 입력하세요: ");
    scanf("%d %d", &arr[3], &arr[4]); // 입력된 값을 배열 원소에 저장

    for (i = 0; i < ARR_SIZE; i++)
        printf("%d ", arr[i]); // 배열 출력
    printf("\n");

    return 0;
}
