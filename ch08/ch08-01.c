/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 강의 포인터 실습
    날짜 : 2025.09.17
*/

#include <stdio.h>

void menu();
void test_swap_double();
void* swapDouble(double* a, double* b);
int test_print_array();
void print_array_double(double arr[], int sz);
void printArrayDouble(double* arr, int sz);

// 기능명: main. 프로그램 시작점
// 내용: 메뉴를 호출하여 원하는 기능을 실행한다.
// 입력: 없음
// 출력: 각 기능 수행 결과를 콘솔에 출력한다.
// 오류: 없음
int main()
{
    menu();
    return 0;
}

// 기능명: menu. 기능 선택 메뉴
// 내용: 스왑, 배열 출력, 종료 중 선택해 해당 함수를 실행한다.
// 입력: 없음
// 출력: 선택된 기능 결과를 콘솔에 출력한다.
// 오류: 잘못된 번호 입력 시 재입력 요청
void menu()
{
    while (1)
    {
        int choice = 0;

        printf("1. 스왑\n2. 배열 출력\n3. 종료\n어떤 함수를 실행하겠습니까? : ");
        scanf_s("%d", &choice);

        if (choice == 1)
        {
            test_swap_double();
        }
        else if (choice == 2)
        {
            test_print_array();
        }
        else if (choice == 3)
        {
            printf("\n종료합니다.");
            break;
        }
        else
        {
            printf("\n다시 입력해주세요.");
        }
    }
}

// 기능명: test_swap_double. 실수형 변수 스왑 테스트
// 내용: swapDouble 함수를 이용해 두 변수의 값을 바꾸고 결과를 출력한다.
// 입력: 없음
// 출력: 스왑 결과를 콘솔에 출력한다.
// 오류: NULL 포인터 입력 시 예외 처리 메시지 출력
void test_swap_double()
{
    double x = 3.3, y = 6.6;

    // 1. x, y를 온전히 넘김
    double* pre = (double*)swapDouble(&x, &y);
    if (pre == NULL)
    {
        printf("pre 변수 : null\n");
    }
    else
    {
        printf("결과 : a = %.1f, b = %.1f\n", x, y);
    }

    // 2. null을 보내면?
    pre = swapDouble((double*)NULL, &y); // NULL을 넘겼기 때문에 pre == NULL이 된다. 당연히 결과가 출력되지 않는다.
    if (pre == NULL)
    {
        printf("pre 변수가 현재 NULL입니다.\n\n");
    }
    else
    {
        printf("결과 : a = %.1f, b = %.1f\n\n", x, y);
    }
}

// 기능명: swapDouble. 두 실수형 변수의 값 교환
// 내용: 두 실수형 변수의 값을 포인터로 받아 서로 교환한다.
// 입력: double* a, double* b (두 변수의 주소)
// 출력: 없음 (포인터 a 반환)
// 오류: NULL 입력 시 NULL 반환
void* swapDouble(double* a, double* b)
{
    if (a == NULL || b == NULL)
    {
        return NULL;
    }

    double temp = *a;
    *a = *b;
    *b = temp;

    return a;
}

// 기능명: test_print_array. 배열 출력 테스트
// 내용: 실수 배열을 생성하고 두 가지 방식(배열, 포인터)으로 출력한다.
// 입력: 없음
// 출력: 배열의 원소를 콘솔에 출력한다.
// 오류: 없음
int test_print_array()
{
    double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]); // 전체 / 첫번째 원소

    print_array_double(arr, size); // 배열 이름
    printArrayDouble(&arr[0], size); // 포인터(가리킨다), 배열의 첫번째 원소의 주소를 매개변수로서 보내야 한다.

    return 0;
}

/*
    기능명: print_array_double. 배열을 사용한 출력
    내용: 1차원 실수 배열을 전달받아 각 원소를 순서대로 출력한다.
    입력: double arr[] (배열 이름), int sz (배열 크기)
    출력: 배열의 값을 콘솔에 출력한다.
    오류: 없음
*/
void print_array_double(double arr[], int sz)
{
    printf("배열을 사용 : ");
    for (int i = 0; i < sz; i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

/*
    기능명: printArrayDouble. 포인터를 사용한 출력
    내용: 포인터를 이용하여 배열의 원소를 순서대로 출력한다.
    입력: double* arr (배열 첫 원소의 주소), int sz (배열 크기)
    출력: 배열의 값을 콘솔에 출력한다.
    오류: 없음
*/
void printArrayDouble(double* arr, int sz)
{
    printf("포인터를 사용 : ");
    for (int i = 0; i < sz; i++, arr++)
    {
        printf("%.1f ", *arr);
    }
    printf("\n\n");
}
