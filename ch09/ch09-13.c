/*
    학번 : 202511204
    이름 : 강기민
	프로그램 명 : ch09 PPT 예제 9-11 : swap_string 함수의 정의 및 호출
    날짜 : 2025.09.29
*/

/*
    관련 개념 :
    문자열은 배열이므로 단순 대입으로 교환할 수 없고 strcpy를 이용해 복사해야 한다.
    문자열 길이는 strlen으로 확인할 수 있으며, 널 문자를 포함하기 때문에 +1을 고려해야 한다.
    포인터 매개변수는 문자열 배열의 시작 주소를 전달받아 함수 내에서 직접 내용을 수정할 수 있다.

    메모리 동작 :
    str1, str2 배열은 main 함수의 스택 영역에 고정 크기로 할당된다.
    swap_string 함수 내부에서 temp 배열이 스택에 생성되어 임시 저장 용도로 사용된다.
    strcpy는 소스 문자열의 내용을 대상 배열에 복사하며 널 문자까지 함께 복사한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 128

int swap_string(char* lhs, char* rhs, int size); // 문자열 교환 함수 원형 선언

int main(void)
{
    char str1[SIZE] = ""; // 첫 번째 문자열 저장할 배열
    char str2[SIZE] = ""; // 두 번째 문자열 저장할 배열

    printf("문자열 2개? "); // 문자열 2개 입력 안내
    scanf("%s %s", str1, str2); // 문자열 2개 입력받음

    printf("str1=%s, str2=%s\n", str1, str2); // 입력된 문자열 출력
    swap_string(str1, str2, SIZE); // 두 문자열 교환
    printf("str1=%s, str2=%s\n", str1, str2); // 교환된 결과 출력

    return 0;
}

int swap_string(char* lhs, char* rhs, int size)
{
    int lhs_len = strlen(lhs); // lhs 문자열 길이
    int rhs_len = strlen(rhs); // rhs 문자열 길이
    char temp[SIZE] = ""; // 임시 저장 배열

    if (lhs_len + 1 > size || rhs_len + 1 > size) // 문자열이 size보다 크면 교환 불가
        return 0; // swap 실패

    strcpy(temp, lhs); // lhs를 temp로 복사
    strcpy(lhs, rhs); // rhs를 lhs로 복사
    strcpy(rhs, temp); // temp를 rhs로 복사

    return 1; // swap 성공
}
