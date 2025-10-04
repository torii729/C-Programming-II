/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 11. 직사각형의 넓이와 둘레를 구하는 get_rect_info 함수를 작성.
        직사각형의 가로, 세로의 길이를 입력받은 다음 get_rect_info함수를 이용해서 직사각형의 넓이와 둘레를 구해서 출력하는 프로그램 작성.
    날짜 : 2025.09.22
*/

#include <stdio.h>

/*
    기능명: main. 프로그램 시작점
    내용: test 함수를 호출하여 직사각형의 넓이와 둘레를 계산하고 출력한다.
    입력: 없음
    출력: 직사각형의 넓이와 둘레를 콘솔에 출력한다.
    오류: 없음
*/
int main(void)
{
    test();
    return 0;
}

/*
    기능명: get_rect_info. 직사각형의 넓이와 둘레 계산
    내용: 가로와 세로를 입력받아 넓이와 둘레를 계산하고, 포인터를 통해 외부 변수에 결과를 저장한다.
    입력: int w (가로 길이), int h (세로 길이), int* area (넓이 저장 주소), int* peri (둘레 저장 주소)
    출력: 없음 (포인터로 결과 전달)
    오류: 없음
*/
void get_rect_info(int w, int h, int* area, int* peri)
{
    *area = w * h;// 넓이 = 가로 * 세로 
    *peri = 2 * (w + h);// 둘레 = (가로 + 세로) * 2
}

/*
    기능명: test. get_rect_info 함수 테스트
    내용: 사용자로부터 직사각형의 가로, 세로를 입력받아 넓이와 둘레를 계산 후 출력한다.
    입력: 없음 (사용자 입력)
    출력: 직사각형의 넓이와 둘레를 콘솔에 출력한다.
    오류: 입력 오류 시 메시지 출력 후 함수 종료
*/
void test(void)
{
    int w = 0;
    int h = 0;
    int area = 0;
    int peri = 0;

    printf("가로? ");
    if (scanf_s("%d", &w) != 1)
    {
        printf("입력 오류\n");
        return;
    }

    printf("세로? ");
    if (scanf_s("%d", &h) != 1)
    {
        printf("입력 오류\n");
        return;
    }

    get_rect_info(w, h, &area, &peri);
    printf("넓이: %d, 둘레: %d\n", area, peri);
}
