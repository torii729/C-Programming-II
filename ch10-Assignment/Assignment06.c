/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 06. DATE 구조체를 2개 매개변수로 전달받아 날짜가 같은지 비교하는 is_same_date 함수를
        정의하시오. DATE 구조체 배열을 선언해서 공휴일에 해당하는 날짜로 초기화한 다음 입력받은 날짜가
        공휴일인지 검사하는 프로그램을 작성. 입력받은 날짜가 "0 0 0"이면 프로그램 종료.
	날짜 : 2025.10.01
*/

/*
    메모리 동작:
    holiday 배열은 DATE 구조체를 원소로 가지며, SIZE 크기만큼 선언된다.
    same 함수는 두 DATE 구조체를 비교하여 모든 값이 같으면 1, 다르면 0을 반환한다.
*/

#include <stdio.h>

#define SIZE 2 // 공휴일 개수

typedef struct {
    int y, m, d; // 연, 월, 일
} DATE;

void run_date();
int same(DATE a, DATE b);

// 기능명: main. 프로그램 실행 시작
// 내용: run_date 함수를 호출하여 날짜 입력 및 공휴일 판별을 수행한다.
// 입력: 없음
// 출력: 없음
// 오류: 없음

int main()
{
    run_date(); // 공휴일 판별 실행
    return 0; // 정상 종료
}

// 기능명: same. 날짜 비교
// 내용: 두 DATE 구조체를 비교하여 연, 월, 일이 모두 같은지 확인한다.
// 입력: DATE a, DATE b
// 출력: 동일하면 1, 아니면 0
// 오류: 없음

int same(DATE a, DATE b)
{
    return (a.y == b.y && a.m == b.m && a.d == b.d);
}

// 기능명: run_date. 공휴일 판별
// 내용: 사용자로부터 날짜를 입력받아 공휴일 배열과 비교하고 결과를 출력한다.
// 입력: 표준 입력(년, 월, 일). 0 0 0 입력 시 종료.
// 출력: 입력한 날짜가 공휴일인지 여부
// 오류: 날짜 형식이 잘못 입력되면 동작이 보장되지 않음

void run_date()
{
    DATE holiday[SIZE] = {
        {2019, 1, 1}, {2019, 12, 25} // 임시 공휴일 데이터
    };
    DATE in;

    while (1)
    {
        printf("날짜 입력 (년 월 일, 종료 시 모두 0 입력): ");
        scanf_s("%d %d %d", &in.y, &in.m, &in.d, sizeof(in));
        if (in.y == 0 && in.m == 0 && in.d == 0)
        {
            break; // 0 0 0 입력 시 종료
        }

        int ok = 0;

        for (int i = 0; i < SIZE; i++)
        {
            if (same(in, holiday[i]))
            {
                printf("%d/%d/%d은 공휴일입니다.\n", holiday[i].y, holiday[i].m, holiday[i].d);
                ok = 1;
            }
        }
        if (!ok)
        {
            printf("%d/%d/%d은 공휴일이 아닙니다.\n", in.y, in.m, in.d);
        }
    }
}
