/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch08 PPT 예제 8-15 : 배열을 입력 매개변수로 사용하는 함수
    날짜 : 2025.09.18
*/

/*
    관련 개념:
    배열은 함수의 매개변수로 전달할 때 자동으로 포인터로 변환된다.
    따라서 배열 전체를 함수로 넘겨 처리할 수 있다.
    const 키워드를 사용하면 원본 배열을 수정하지 못하게 보호할 수 있다.

    메모리 동작:
    copy_array 함수는 source 배열에서 target 배열로 원소를 복사한다.
    print_array 함수는 배열의 원소를 순서대로 출력한다.
*/

#include <stdio.h>
#define SIZE 10

// 기능명: main. 배열 복사 및 출력 테스트
// 내용: x 배열을 y 배열로 복사하고 두 배열을 각각 출력한다.
// 입력: 없음
// 출력: 두 배열의 원소
// 오류: 없음
int main(void)
{
    int x[SIZE] = { 10, 20, 30, 40, 50 }; // 초기 데이터
    int y[SIZE] = { 0 }; // 0으로 초기화된 배열

    printf("x = ");
    print_array(x, SIZE); // 원본 배열 출력

    copy_array(x, y, SIZE); // x의 내용을 y로 복사

    printf("y = ");
    print_array(y, SIZE); // 복사된 배열 출력

    return 0; // 정상 종료
}

// 기능명: copy_array. 배열 복사
// 내용: source 배열의 원소를 target 배열로 복사한다.
// 입력: const int source[], int target[], int size
// 출력: 없음
// 오류: size가 잘못되면 접근 오류 발생 가능
void copy_array(const int source[], int target[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i]; // 각 원소 복사
}

// 기능명: print_array. 배열 출력
// 내용: arr 배열의 원소를 순서대로 출력한다.
// 입력: const int arr[], int size
// 출력: 없음 (배열 원소를 콘솔에 출력)
// 오류: 없음
void print_array(const int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]); // 원소 출력
    printf("\n");
}
