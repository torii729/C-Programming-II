/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 08. 제품 정보를 나타내는 PRODUCT 구조체를 정의. 각 제품별로 제품명, 가격, 재고를 저장.
        PRODUCT 구조체를 매개변수로 전달받아 제품 정보를 출력하는 print_product 함수를 정의.
        PRODUCT 구조체 변수를 선언하고 제품명, 가격, 재고를 입력받아 저장하고 출력하는 프로그램 작성.
        제품명은 빈칸 없는 한 단어로 입력한다.
	날짜 : 2025.10.01
*/

/*
    메모리 동작:
    PRODUCT 구조체 변수 p는 name 배열과 price, stock 멤버를 가진다.
    입력된 데이터는 각 멤버에 저장되어 최종적으로 출력된다.
*/

#include <stdio.h>

#define SIZE 20 // 문자열 크기

typedef struct {
    char name[SIZE]; // 제품명
    int price; // 가격
    int stock; // 재고
} PRODUCT;

void run_product();

// 기능명: main. 프로그램 실행 시작
// 내용: run_product 함수를 호출하여 제품 정보를 입력받고 출력한다.
// 입력: 없음
// 출력: 없음
// 오류: 없음

int main()
{
    run_product(); // 제품 정보 처리 실행
    return 0; // 정상 종료
}

// 기능명: run_product. 제품 정보 입력 및 출력
// 내용: 사용자로부터 제품명, 가격, 재고를 입력받아 구조체 멤버에 저장 후 출력한다.
// 입력: 표준 입력(제품명, 가격, 재고)
// 출력: 제품명, 가격, 재고 정보 출력
// 오류: 입력 크기가 배열 크기를 초과하면 잘못된 동작 발생 가능

void run_product()
{
    PRODUCT p;

    printf("제품명? "); scanf_s("%s", p.name, sizeof(p.name));
    printf("가격? "); scanf_s("%d", &p.price);
    printf("재고? "); scanf_s("%d", &p.stock);

    printf("[%s %d원 재고:%d]\n", p.name, p.price, p.stock);
}
