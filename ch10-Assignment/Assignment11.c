/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 11. PRODUCT 구조체 배열을 이용해서 제품명을 입력받아 검색 후 주문 처리하는 프로그램
        주문 수량을 입력받아 결제 금액을 알려주고, 제품 재고를 주문 수량만큼 감소시킨다.
        제품명으로 검색할 수 없거나 찾은 제품의 재고가 주문 수량보다 적으면 에러 메시지 출력.
        PRODUCT 구조체 배열은 크기가 5인 배열로 선언, 적당한 값으로 초기화.
	날짜 : 2025.10.01
*/

/*
    메모리 동작 :
    run_order 함수에서 list 배열이 선언되고, find 함수는 해당 배열에서 제품명을 검색한다.
    order 함수는 선택된 구조체 멤버를 직접 수정하여 재고를 차감한다.
    print_all 함수는 구조체 배열의 전체 상품 정보를 출력한다.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 20 // 문자열 크기
#define N 3 // 상품 개수

typedef struct {
    char name[SIZE]; // 제품명
    int price; // 가격
    int stock; // 재고
} PRODUCT;

void run_order();
int find(PRODUCT list[], int n, char* key);
void order(PRODUCT* p, int q);
void print_all(PRODUCT list[], int n);

// 기능명: main. 프로그램 실행 시작
// 내용: run_order 함수를 호출하여 주문 프로그램을 실행한다.
// 입력: 없음
// 출력: 없음
// 오류: 없음

int main()
{
    run_order();
    return 0; // 정상 종료
}

// 기능명: find. 제품 검색
// 내용: 구조체 배열에서 key와 같은 제품명을 가진 인덱스를 찾는다.
// 입력: PRODUCT list[], int n, char* key
// 출력: 찾은 인덱스(정수). 없으면 -1 반환
// 오류: key가 NULL이면 비교 불가

int find(PRODUCT list[], int n, char* key)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(list[i].name, key))
        {
            return i;
        }
    }
    return -1;
}

// 기능명: order. 주문 처리
// 내용: 특정 상품에 대해 주문 수량만큼 결제 금액을 계산하고 재고를 차감한다.
// 입력: PRODUCT* p (주문할 상품), int q (주문 수량)
// 출력: 없음 (결제 금액과 변경된 재고 출력)
// 오류: 재고 부족 시 주문 불가

void order(PRODUCT* p, int q)
{
    if (p->stock < q)
    {
        printf("재고 부족\n");
        return;
    }
    printf("결제 금액: %d %s 재고: %d\n", p->price * q, p->name, p->stock - q);

    p->stock = p->stock - q;
}

// 기능명: print_all. 전체 상품 출력
// 내용: 구조체 배열에 저장된 모든 상품의 이름, 가격, 재고를 출력한다.
// 입력: PRODUCT list[], int n
// 출력: 없음 (상품 정보를 콘솔에 출력)
// 오류: 없음

void print_all(PRODUCT list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%s %d원 재고:%d]\n", list[i].name, list[i].price, list[i].stock);
    }
}

// 기능명: run_order. 주문 실행
// 내용: 상품 목록을 준비하고, 사용자로부터 제품명과 수량을 입력받아 주문을 처리한다.
// 입력: 표준 입력(제품명, 주문 수량). 종료 조건은 "." 입력
// 출력: 주문 처리 결과 및 모든 상품 정보 출력
// 오류: 잘못된 입력 시 동작이 보장되지 않음

void run_order()
{
    PRODUCT list[N] = {
        {"아메리카노", 4000, 5},
        {"카페라떼", 4500, 7},
        {"플랫화이트", 5000, 10}
    };

    char key[SIZE];
    int q = 0;

    while (1)
    {
        printf("주문할 제품명? (종료 시 . 입력) ");
        scanf_s("%s", key, sizeof(key));

        if (!strcmp(key, "."))
        {
            break;
        }

        printf("주문할 수량? ");
        scanf_s("%d", &q);

        int idx = find(list, N, key);

        if (idx == -1)
        {
            printf("상품 없음\n");
        }
        else
        {
            order(&list[idx], q);
        }
    }
    print_all(list, N);
}

