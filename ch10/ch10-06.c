/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch10 PPT 예제 10-4 : 구조체 변수의 비교
    날짜 : 2025.09.30
*/

/*
    관련 개념:
    문자열 멤버 비교는 strcmp 함수를 사용해야 한다.
    멤버 값이 모두 동일해야 두 구조체가 같은 값을 가진다고 볼 수 있다.
    typedef를 사용해 구조체 타입에 별칭을 부여하면 코드가 더 간결해진다.

    메모리 동작:
    ct1과 ct2는 각각 스택에 독립적으로 존재한다.
    대입 연산으로 ct1의 모든 멤버 값이 ct2에 복사된다.
    이후 비교는 값 비교이며 메모리 공유는 일어나지 않는다.
*/

#include <stdio.h>
#include <string.h>

typedef struct contact
{
    char name[20]; // 이름 문자열
    char phone[20]; // 전화번호 문자열
    int ringtone; // 벨소리 번호
} contact;

// 기능명: main. 구조체 변수 비교 예제
// 내용: 두 구조체 변수의 문자열 및 정수형 멤버 값을 비교하여 동일 여부를 출력한다.
// 입력: 없음
// 출력: 두 구조체의 값이 같은지 여부를 콘솔에 출력한다.
// 오류: 없음

int main(void)
{
    struct contact ct1 = { "Alice", "010-1234-5678", 1 }; // 구조체 변수 초기화
    struct contact ct2 = ct1; // 구조체 대입으로 값 복사

    if (strcmp(ct1.name, ct2.name) == 0 && // 문자열 비교
        strcmp(ct1.phone, ct2.phone) == 0 && // 문자열 비교
        ct1.ringtone == ct2.ringtone) // 정수 비교
    {
        printf("ct1과 ct2의 값이 같습니다.\n");
    }
    else
    {
        printf("ct1과 ct2의 값이 같지 않습니다.\n");
    }

    return 0;
}
