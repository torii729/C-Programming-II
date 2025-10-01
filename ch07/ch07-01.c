/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 문제 풀이

    실수 배열에 대한 다음 두 함수를 구현하고
    printArrayFloat(float R[], int size)
    copyArrayFloat(float from[], float to[], int size)

    Test 함수를 작성하고 main에서 호출하여 실행해 보시오
    Int test_printArrayFloat()
    Int Test_copyArrayFloat()

    날짜 : 2025.09.15
*/

#include <stdio.h>

void copyArrayFloat(float from[], float to[], int size);
void printArrayFloat(float R[], int size);
int test_copyArrayFloat();
int test_printArrayFloat();

// 기능명: main. 테스트 실행
// 내용: 배열 출력 및 배열 복사 테스트 함수를 실행한다.
// 입력: 없음
// 출력: 없음
// 오류: 없음
int main()
{
    test_printArrayFloat();
    test_copyArrayFloat();
    return 0;
}

// 기능명: copyArrayFloat. 실수 배열 복사
// 내용: from 배열의 원소를 to 배열로 순서대로 복사한다.
// 입력: float from[], float to[], int size
// 출력: 없음
// 오류: size가 음수이거나 배열 크기보다 크면 잘못된 동작 발생 가능
void copyArrayFloat(float from[], float to[], int size)
{
    for (int i = 0; i < size; i++)
    {
        to[i] = from[i];
    }
}

// 기능명: printArrayFloat. 실수 배열 출력
// 내용: R 배열의 원소들을 순서대로 출력한다.
// 입력: float R[], int size
// 출력: 없음 (배열 원소를 콘솔에 출력)
// 오류: 없음
void printArrayFloat(float R[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", R[i]);
    }
    printf("\n");
}

// 기능명: test_copyArrayFloat. 배열 복사 테스트
// 내용: 실수 배열을 다른 배열로 복사하고 결과를 출력한다.
// 입력: 없음
// 출력: 없음 (테스트 결과를 콘솔에 출력)
// 오류: 없음
int test_copyArrayFloat()
{
    float num_float[5] = { 1.0, 22.0, 333.0, 4444.0, 5555.0 };
    float null[5] = { 0 };

    copyArrayFloat(num_float, null, 5);

    printf("원본 배열 : ");
    printArrayFloat(num_float, 5);

    printf("복사된 배열 : ");
    printArrayFloat(null, 5);

    return 0;
}

// 기능명: test_printArrayFloat. 배열 출력 테스트
// 내용: 실수 배열을 선언하고 printArrayFloat로 출력한다.
// 입력: 없음
// 출력: 없음 (테스트 결과를 콘솔에 출력)
// 오류: 없음
int test_printArrayFloat()
{
    float arr[5] = { 6.6, 7.7, 8.8, 9.9, 10.1 };

    printf("배열 출력 테스트 : ");
    printArrayFloat(arr, 5);

    return 0;
}
