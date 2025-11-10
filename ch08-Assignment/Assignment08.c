/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 8. 정수형 배열을 특정 값으로 채우는 fill_array 함수와 테스트 프로그램
    날짜 : 2025.11.23
*/

#include <stdio.h>

void test(void);
void fill_array(int* arr, int size, int value);
void print_array(const int* arr, int size);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 배열 채우기 프로그램을 실행한다.
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
    내용: 크기 20인 int 배열과 값을 입력받아 fill_array로 채운 뒤 출력한다.
    입력: 배열에 저장할 값 하나를 입력받는다.
    출력: 채워진 배열을 출력한다.
    오류: 입력 실패 시 종료한다.
*/
void test(void)
{
    int arr[20];
    int value;
    int ok;

    printf("배열의 원소에 저장할 값? ");
    ok = scanf_s("%d", &value);
    if (ok != 1)
    {
        return;
    }

    fill_array(arr, 20, value);
    print_array(arr, 20);
}

/*
    기능명: fill_array. 배열 채우기
    내용: 포인터와 역참조 연산자를 사용해 배열을 특정 값으로 채운다.
    입력: 배열 시작 주소, 배열 크기, 채울 값.
    출력: 없음
    오류: 없음
*/
void fill_array(int* arr, int size, int value)
{
    int i;

    for (i = 0; i < size; i++)
    {
        *(arr + i) = value;
    }
}

/*
    기능명: print_array. 배열 출력
    내용: 배열의 모든 원소를 공백으로 구분해 출력한다.
    입력: 배열 시작 주소, 배열 크기.
    출력: 배열 원소 출력.
    오류: 없음
*/
void print_array(const int* arr, int size)
{
    int i;

    printf("배열: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
