/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 문제 풀이

    구조체 타입을 하나 임의로 선언 : 예) 연락처(이름, 전화번호, 메모)
    typedef struct _contact { char name[64]; char phone1[24] } Contact;

    구조체 배열에 대한 다음 두 함수를 구현하고
    void printArrayContact(Contact R[], int size)
    void copyArrayContact(Contact from[], Contact to[], int size)

    Test 함수를 작성하고 main 에서 호출하여 실행해 보시오
    Int test_printArrayContact()
    Int Test_copyArrayContact()

    날짜 : 2025.09.15
*/

#include <stdio.h>
#include <string.h>
#include "struct.h"

void copyArrayContact(Contact from[], Contact to[], int size);
void printArrayContact(Contact R[], int size);
int test_copyArrayContact();
int test_printArrayContact();

// 기능명: main. 테스트 실행
// 내용: 구조체 배열 출력 및 복사 테스트 함수를 실행한다.
// 입력: 없음
// 출력: 각 테스트 결과를 콘솔에 출력한다.
// 오류: 없음
int main()
{
    test_printArrayContact();
    test_copyArrayContact();
    return 0;
}

// 기능명: copyArrayContact. 구조체 배열 복사
// 내용: from 배열의 각 구조체 원소를 to 배열로 순서대로 복사한다.
// 입력: Contact from[], Contact to[], int size
// 출력: 없음
// 오류: size가 음수이거나 배열 크기보다 크면 잘못된 동작 발생 가능
void copyArrayContact(Contact from[], Contact to[], int size)
{
    for (int i = 0; i < size; i++)
    {
        to[i] = from[i];
    }
}

// 기능명: printArrayContact. 구조체 배열 출력
// 내용: R 배열의 각 구조체 원소의 이름과 전화번호를 순서대로 출력한다.
// 입력: Contact R[], int size
// 출력: 각 구조체의 이름과 전화번호를 콘솔에 출력한다.
// 오류: 없음
void printArrayContact(Contact R[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("이름 : %s, 전화번호 : %s\n", R[i].name, R[i].phone1);
    }
    printf("\n");
}

// 기능명: test_copyArrayContact. 구조체 배열 복사 테스트
// 내용: 구조체 배열을 다른 배열로 복사하고, 원본과 복사본을 각각 출력한다.
// 입력: 없음
// 출력: 원본 배열과 복사된 배열의 내용을 콘솔에 출력한다.
// 오류: 없음
int test_copyArrayContact()
{
    Contact arr[2] = {
        {"이서", "010-1234-5678"},
        {"서연", "010-9876-5432"}
    };

    Contact null[2] = { 0 };

    copyArrayContact(arr, null, 2);

    printf("원본 배열 : \n");
    printArrayContact(arr, 2);

    printf("복사된 배열 : \n");
    printArrayContact(null, 2);

    return 0;
}

// 기능명: test_printArrayContact. 구조체 배열 출력 테스트
// 내용: 구조체 배열을 선언하고 printArrayContact 함수로 출력한다.
// 입력: 없음
// 출력: 구조체 배열의 이름과 전화번호를 콘솔에 출력한다.
// 오류: 없음
int test_printArrayContact()
{
    Contact arr[3] = {
        {"민기", "010-1111-2222"},
        {"철수", "010-3333-4444"},
        {"기민", "010-5555-6666"}
    };

    printf("결과 : \n");
    printArrayContact(arr, 3);

    return 0;
}
