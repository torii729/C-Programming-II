/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 9-7 : 문자열 토큰 분리 (strtok)
    날짜 : 2025.09.29
*/

#include <stdio.h>
#include <string.h>

/*
    기능명: main. 프로그램 시작점
    내용: strtok 함수를 이용해 문자열을 구분자('-') 기준으로 분리한다.
          전화번호 문자열을 지역번호, 국번, 가입자 번호로 나누어 각각 출력한다.
    입력: 없음
    출력: 구분된 전화번호의 각 부분을 콘솔에 출력한다.
    오류: 없음
*/
int main(void)
{
    char phone[] = "02-123-4567"; // 전화번호 문자열
    char* p = NULL; // 토큰을 가리킬 포인터

    p = strtok(phone, "-"); // 첫 번째 토큰 추출 ("02")
    printf("area code: %s\n", p); // 지역번호 출력

    p = strtok(NULL, "-"); // 두 번째 토큰 추출 ("123")
    printf("prefix: %s\n", p); // 국번 출력

    p = strtok(NULL, "-"); // 세 번째 토큰 추출 ("4567")
    printf("line number: %s\n", p); // 가입자 번호 출력

    return 0; // 프로그램 종료
}
