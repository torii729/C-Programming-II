/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 3. 텍스트 파일의 이름을 입력받아서 파일 내의 문자열들에 대하여 영문자의 개수를 문자별로 세서 출력하는 프로그램을 작성하시오.
            문자의 개수를 셀 때는 대소문자를 구분하지 않는다.
    날짜 : 2025.11.9
*/

#include <stdio.h>
#include <ctype.h>

void test(void);
void count_letters_in_file(const char* filename);

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
    내용: 사용자로부터 텍스트 파일 이름을 입력받고,
          해당 파일의 영문자 개수를 세는 함수를 호출한다.
    입력: 콘솔에서 파일 이름 문자열을 입력받는다.
    출력: 없음 (실제 출력은 다른 함수에서 수행한다.)
    오류: 파일 이름 입력에 실패한 경우 오류 메시지를 출력한다.
*/
void test(void)
{
    char filename[256];

    printf("파일명? ");
    if (scanf_s("%255s", filename, (unsigned int)sizeof(filename)) != 1)
    {
        printf("파일명을 읽을 수 없습니다.\n");
        return;
    }

    count_letters_in_file(filename);
}

/*
    기능명: count_letters_in_file. 영문자 개수 세기
    내용: 지정한 텍스트 파일을 열어 내용을 그대로 출력하면서,
          파일에 등장하는 영문자의 개수를 문자별로 세어 출력한다.
    입력: 파일 이름을 나타내는 문자열 포인터.
    출력: 파일의 내용을 콘솔에 그대로 출력하고,
          이어서 사용된 영문자와 그 개수를 "문자:개수" 형식으로 출력한다.
    오류: 파일을 열 수 없는 경우 오류 메시지를 출력한다.
*/
void count_letters_in_file(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    int count[26] = { 0 };
    int ch;
    int i;

    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 파일 내용을 문자 단위로 읽으면서 동시에 개수 세기
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);  /* 원래 문자 출력 */

        if (isalpha((unsigned char)ch))
        {
            ch = tolower((unsigned char)ch);
            count[ch - 'a']++;
        }
    }

    fclose(fp);

    printf("\n");

    // 등장한 문자만 알파벳 순서로 출력
    for (i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c:%d  ", 'a' + i, count[i]);
        }
    }
    printf("\n");
}
