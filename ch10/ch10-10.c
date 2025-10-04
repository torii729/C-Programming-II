/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-8 : 구조체 포인터의 활용
    날짜 : 2025.10.01
*/

/*
    관련 개념 :
    구조체 배열은 여러 개의 구조체 변수를 연속된 메모리에 저장한다.
    구조체 포인터는 특정 구조체 원소의 주소를 가리키며, -> 연산자로 멤버에 접근할 수 있다.
    반복문과 strcmp 함수를 이용해 배열에서 원하는 이름을 검색할 수 있다.
    최근 검색한 구조체 원소의 주소를 포인터에 저장하면, 마지막 검색 결과를 쉽게 참조할 수 있다.

    메모리 동작 :
    arr 배열은 Contact 구조체 7개를 연속으로 저장한다.
    name 배열은 검색할 이름을 임시로 저장한다.
    recent 포인터는 마지막으로 검색에 성공한 구조체 원소의 주소를 저장한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define STR_SIZE 20

typedef struct contact {
    char name[20]; // 이름
    char phone[20]; // 전화번호
    int ringtone; // 벨소리 번호
} Contact;

// 기능명: main. 구조체 포인터 활용 예제
// 내용: 구조체 배열에서 이름을 입력받아 해당 연락처를 검색하고, 최근 검색된 연락처를 출력한다.
// 입력: 사용자로부터 이름 입력 ('.' 입력 시 종료)
// 출력: 검색 결과(전화번호 및 최근 통화 내역)를 콘솔에 출력한다.
// 오류: 없음

int main(void)
{
    Contact arr[] = {
        {"Alice", "010-1111-1111", 1},
        {"Bob", "010-2222-2222", 2},
        {"Charlie", "010-3333-3333", 3},
        {"David", "010-4444-4444", 4},
        {"Eve", "010-5555-5555", 5},
        {"Frank", "010-6666-6666", 6},
        {"Grace", "010-7777-7777", 7}
    };

    int size = sizeof(arr) / sizeof(arr[0]); // 배열 원소 개수
    int i;
    char name[STR_SIZE]; // 검색할 이름
    int index;

    Contact* recent = NULL; // 최근 검색한 연락처 포인터

    while (1)
    {
        printf("이름(. 입력 시 종료)? ");
        scanf("%s", name);
        if (strcmp(name, ".") == 0) // 종료 조건
            break;

        index = -1; // 초기값은 못 찾음 상태
        for (i = 0; i < size; i++)
        {
            if (strcmp(arr[i].name, name) == 0) // 이름이 같은지 검사
            {
                index = i; // 찾은 위치 저장
                break; // 더 이상 탐색 안 함
            }
        }
        if (index >= 0)
        {
            printf("%s의 전화번호 %s로 전화를 겁니다....\n", arr[index].name, arr[index].phone);
            recent = &arr[index]; // 최근 검색한 연락처 주소 저장
        }
        else
        {
            printf("연락처를 찾을 수 없습니다.\n");
        }
    }

    if (recent)
        printf("최근 통화 : %s %s\n", recent->name, recent->phone); // 마지막으로 검색된 연락처 출력

    return 0;
}
