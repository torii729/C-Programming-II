/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 예제 7-9 : 배열의 탐색
    날짜 : 2025.09.15
*/

/*
    관련 개념:
    배열에서 원하는 값을 찾으려면 반복문을 이용해 원소를 하나씩 비교해야 한다.
    data[i] == key 조건을 만족하면 해당 인덱스가 탐색 결과다.
    이 방식은 선형 탐색으로, 배열이 정렬되지 않아도 사용할 수 있다.

    메모리 동작:
    data 배열은 스택에 연속적으로 저장된다.
    key는 사용자 입력을 받아 저장되는 변수다.
    for 반복문에서 data[i]를 차례로 읽어 key와 비교한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 기능명: main. 배열 탐색 시연
// 내용: 정수 배열을 선언하고 사용자로부터 탐색할 값을 입력받아,
//       선형 탐색으로 배열 내의 모든 일치 위치를 출력한다.
// 입력: 사용자로부터 탐색할 정수 key를 입력받는다.
// 출력: 배열의 원소와 탐색 결과(일치한 인덱스)를 콘솔에 출력한다.
// 오류: 없음
int main(void)
{
    int data[] = { 78, 34, 52, 15, 63, 15, 25 }; // 탐색 대상 배열
    int size;
    int key, i;

    size = sizeof(data) / sizeof(data[0]); // 배열 크기 계산

    printf("arr = ");
    for (i = 0; i < size; i++)
        printf("%d ", data[i]); // 배열 원소 출력
    printf("\n");

    printf("찾을 값(key)? ");
    scanf("%d", &key); // 찾을 값 입력

    for (i = 0; i < size; i++) {
        if (data[i] == key) // 배열의 원소와 key 비교
            printf("찾은 원소의 인덱스: %d\n", i); // 찾은 위치 출력
    }

    return 0;
}
