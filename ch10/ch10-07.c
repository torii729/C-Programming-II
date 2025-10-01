/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch10 PPT 예제 10-5 : 구조체 배열
	날짜 : 2025.10.01
*/

/*
    관련 개념:
    구조체 배열은 같은 구조체 타입의 여러 개 변수를 연속된 메모리 공간에 저장한다.
    sizeof 연산으로 전체 크기를 한 원소 크기로 나누면 배열의 원소 개수를 구할 수 있다.
    반복문을 사용해 구조체 배열의 모든 원소를 순서대로 출력할 수 있다.

    메모리 동작:
    arr 배열은 CONTACT 구조체를 세 개 연속으로 저장한다.
    arr[i].name, arr[i].phone, arr[i].ringtone을 통해 각 멤버에 접근한다. (. 기호 사용)
*/

#include <stdio.h>

typedef struct {
    char name[20]; // 이름
    char phone[20]; // 전화번호
    int ringtone; // 벨소리 번호
} CONTACT;

int main(void)
{
    CONTACT arr[] = {
        {"Alice", "010-1111-2222", 1}, // 첫 번째 연락처
        {"Bob", "010-3333-4444", 2}, // 두 번째 연락처
        {"Charlie", "010-5555-6666", 3} // 세 번째 연락처
    };
    int size = sizeof(arr) / sizeof(arr[0]); // 구조체 배열 크기 계산
    int i;

    printf(" 이름 전화번호 벨\n");
    for (i = 0; i < size; i++)
    {
        printf("%6s %11s %d\n", arr[i].name, arr[i].phone, arr[i].ringtone); // 구조체 배열 출력
    }

    return 0;
}

