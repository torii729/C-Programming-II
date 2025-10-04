/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-6 : 구조체 배열의 검색
    날짜 : 2025.10.01
*/

/*
    관련 개념:
    구조체 배열은 여러 개의 구조체를 연속된 메모리에 저장한다.
    문자열 비교는 strcmp 함수를 사용해야 하며, 같으면 0을 반환한다.
    탐색에 실패했을 때를 대비해 임의의 변수 index를 선언해 0 또는 -1, 1 등을 저장한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define STR_SIZE 20

typedef struct contact {
    char name[STR_SIZE]; // 이름
    char phone[STR_SIZE]; // 전화번호
    int ringtone; // 벨소리 번호
} Contact;

// 기능명: main. 구조체 배열 검색 예제
// 내용: 구조체 배열에서 이름을 입력받아 해당 연락처 정보를 탐색하고 출력한다.
// 입력: 사용자로부터 검색할 이름 입력
// 출력: 이름이 존재하면 전화번호 출력, 없으면 안내 메시지 출력
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

    printf("이름? ");
    scanf("%s", name); // 이름 입력

    index = -1; // 못 찾은 경우 대비
    for (i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, name) == 0) // 이름 비교
        {
            index = i; // 찾은 위치 저장
            break; // 더 이상 탐색하지 않음
        }
    }

    if (index >= 0)
    {
        printf("%s의 전화번호 : %s\n", arr[index].name, arr[index].phone); // 찾은 경우 출력
    }
    else
    {
        printf("찾는 이름이 없습니다.\n"); // 못 찾은 경우 출력
    }

    return 0;
}
