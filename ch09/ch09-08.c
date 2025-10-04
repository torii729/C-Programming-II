/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 9-6 : 문자열의 검색
    날짜 : 2025.09.29
*/

#include <stdio.h>
#include <string.h>

/*
    기능명: main. 프로그램 시작점
    내용: 문자열 내에서 특정 문자의 위치나 부분 문자열을 검색하는 예제이다.
          strrchr 함수로 마지막 '.' 위치를 찾고, strstr 함수로 특정 확장자를 탐색한다.
    입력: 없음
    출력: 파일 확장자와 파일 형식(TEXT 파일 여부)을 콘솔에 출력한다.
    오류: 없음
*/
int main(void)
{
    char filename[] = "readme.txt"; // 파일 이름 문자열
    char* p = NULL; // 탐색 결과를 저장할 포인터

    p = strrchr(filename, '.'); // 문자열에서 마지막 '.' 위치 찾기
    if (p != NULL)
        printf("file extension: %s\n", p + 1); // '.' 다음 문자열(확장자) 출력

    p = strstr(filename, ".txt"); // 문자열에서 ".txt" 부분 문자열 찾기
    if (p != NULL)
        printf("file type: TEXT file\n"); // ".txt"가 있으면 텍스트 파일로 판별

    return 0; // 프로그램 종료
}
