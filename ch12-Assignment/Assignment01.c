/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 1. 텍스트 파일의 이름을 입력받아서 파일의 내용을 라인 번호와 함께 출력하는 프로그램을 작성하시오. 
    날짜 : 2025.11.9
*/

#include <stdio.h>

void print_file_with_line_numbers(const char* filename);
void test(void);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 프로그램을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    test();
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 사용자에게 파일명을 입력받아 파일 내용을 줄 번호와 함께 출력하는 함수를 호출한다.
    입력: 콘솔에서 파일 이름 문자열을 입력받는다.
    출력: 없음 (실제 출력은 다른 함수에서 수행한다.)
    오류: 파일 이름 입력에 실패한 경우 오류 메시지를 출력한다.
*/
void test(void)
{
    char filename[300];

    printf("파일명? ");
    if (scanf_s("%s", filename, sizeof(filename)) != 1)
    {
        printf("파일명을 읽을 수 없습니다.\n");
        return;
    }

    print_file_with_line_numbers(filename);
}

/*
    기능명: print_file_with_line_numbers. 파일 내용 출력
    내용: 지정한 텍스트 파일을 열어 한 줄씩 읽으면서 줄 번호와 함께 화면에 출력한다.
    입력: 파일 이름을 나타내는 문자열 포인터.
    출력: 파일의 각 줄을 "줄번호: 줄내용" 형식으로 콘솔에 출력한다.
    오류: 파일을 열 수 없는 경우 오류 메시지를 출력한다.
*/
void print_file_with_line_numbers(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    char line[1000];
    int line_no = 1;

    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%d: %s", line_no, line);
        line_no++;
    }

    fclose(fp);
}
