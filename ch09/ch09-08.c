/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch09 PPT 예제 9-6 : 문자열의 검색
    날짜 : 2025.09.29
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char filename[] = "readme.txt"; // 파일 이름 문자열
    char* p = NULL; // 문자열 탐색 결과를 저장할 포인터

    p = strrchr(filename, '.'); // filename에서 마지막 '.' 위치 찾기
    if (p != NULL) // '.'을 찾았다면...
        printf("file extension: %s\n", p + 1); // '.' 다음부터 출력 → 확장자 출력

    p = strstr(filename, ".txt"); // filename에서 ".txt" 부분 문자열 찾기
    if (p != NULL) // ".txt" 발견 시
        printf("file type: TEXT file\n"); // 텍스트 파일이라고 출력

    return 0;
}
