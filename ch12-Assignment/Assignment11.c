/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 11. CONTACT 구조체를 이용한 연락처 관리 프로그램에 텍스트 파일에서 연락처를 로딩하는 기능을 추가한다. 
        텍스트 파일에 정해진 형식으로 연락처를 저장하고 이 파일을 읽어서 CONTACT 구조체 배열을 생성하도록 프로그램을 작성하시오. 
        CONTACT 구조체 배열은 동적 메모리로 생성한다.
    날짜 : 2025.11.9
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define PHONE_LEN 20

typedef struct CONTACT
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} CONTACT;

void test(void);
int  count_contacts_in_file(const char* filename);
CONTACT* load_contacts_from_file(const char* filename, int* pCount);
int  find_contact_index(const CONTACT* list, int count, const char* name);
void call_contact_loop(const CONTACT* list, int count);

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
    내용: 연락처 파일명을 입력받아 파일에서 연락처를 로딩하고,
          이름을 입력받아 전화번호를 검색하는 반복 기능을 수행한다.
    입력: 콘솔에서 연락처 파일명과 이름 문자열을 입력받는다.
    출력: 로딩된 연락처 개수와 이름 검색 결과를 콘솔에 출력한다.
    오류: 파일을 열 수 없거나 메모리 할당에 실패한 경우 오류 메시지를 출력한다.
*/
void test(void)
{
    char filename[256];
    CONTACT* list = NULL;
    int count = 0;

    printf("연락처 파일명? ");
    if (scanf_s("%255s", filename, (unsigned int)sizeof(filename)) != 1)
    {
        printf("파일명을 읽을 수 없습니다.\n");
        return;
    }

    list = load_contacts_from_file(filename, &count);
    if (list == NULL || count == 0)
    {
        printf("연락처를 로딩하지 못했습니다.\n");
        return;
    }

    printf("%d개의 연락처를 로딩했습니다.\n", count);

    call_contact_loop(list, count);

    free(list);
}

/*
    기능명: count_contacts_in_file. 연락처 개수 세기
    내용: 지정한 텍스트 파일을 열어, 한 줄에 저장된 이름과 전화번호 쌍의 개수를 센다.
    입력: 파일 이름을 나타내는 문자열 포인터.
    출력: 파일 안에 존재하는 연락처(라인)의 개수를 정수로 반환한다.
    오류: 파일을 열 수 없는 경우 0을 반환하고 오류 메시지를 출력한다.
*/
int count_contacts_in_file(const char* filename)
{
    FILE* fp;
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 0;
    }

    while (fscanf_s(fp, "%s %s",
        name, sizeof(name),
        phone, sizeof(phone)) == 2)
    {
        count++;
    }

    fclose(fp);
    return count;
}

/*
    기능명: load_contacts_from_file. 연락처 로딩
    내용: 텍스트 파일에서 연락처를 읽어 CONTACT 구조체 동적 배열을 생성하고 데이터를 채운다.
    입력: 파일 이름 문자열, 실제 개수를 돌려줄 정수 포인터.
    출력: 동적으로 생성된 CONTACT 배열의 시작 주소를 반환하고,
          pCount에 읽은 연락처 개수를 저장한다.
    오류: 파일 열기 실패나 메모리 할당 실패 시 NULL을 반환하고 pCount를 0으로 설정한다.
*/
CONTACT* load_contacts_from_file(const char* filename, int* pCount)
{
    FILE* fp;
    CONTACT* list;
    int count;
    int i;

    *pCount = 0;

    count = count_contacts_in_file(filename);
    if (count == 0)
    {
        return NULL;
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 다시 열 수 없습니다.\n");
        return NULL;
    }

    list = (CONTACT*)malloc(sizeof(CONTACT) * count);
    if (list == NULL)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        fclose(fp);
        return NULL;
    }

    for (i = 0; i < count; i++)
    {
        if (fscanf_s(fp, "%s %s",
            list[i].name, sizeof(list[i].name),
            list[i].phone, sizeof(list[i].phone)) != 2)
        {
            // 예상보다 적게 읽힌 경우
            count = i;
            break;
        }
    }

    fclose(fp);

    *pCount = count;
    return list;
}

/*
    기능명: find_contact_index. 이름 검색
    내용: CONTACT 배열에서 주어진 이름과 일치하는 연락처의 인덱스를 찾는다.
    입력: CONTACT 배열 포인터, 배열에 저장된 개수, 찾을 이름 문자열.
    출력: 찾은 경우 인덱스(0 이상), 찾지 못한 경우 -1을 반환한다.
    오류: 없음
*/
int find_contact_index(const CONTACT* list, int count, const char* name)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (strcmp(list[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

/*
    기능명: call_contact_loop. 이름 입력, 검색 반복
    내용: 사용자가 이름을 입력하면 배열에서 검색하여
          해당 전화번호를 출력하는 동작을 반복 수행한다.
    입력: CONTACT 배열 포인터, 배열에 저장된 개수.
    출력: 검색 결과(전화번호 또는 없음)를 콘솔에 출력한다.
    오류: 이름 입력에 실패한 경우 반복을 종료한다.
*/
void call_contact_loop(const CONTACT* list, int count)
{
    char name[NAME_LEN];
    int index;

    while (1)
    {
        printf("이름(. 입력 시 종료)? ");
        if (scanf_s("%s", name, sizeof(name)) != 1)
        {
            printf("이름을 읽을 수 없습니다.\n");
            return;
        }

        if (strcmp(name, ".") == 0)
        {
            break;
        }

        index = find_contact_index(list, count, name);
        if (index == -1)
        {
            printf("연락처를 찾을 수 없습니다.\n");
        }
        else
        {
            printf("%s의 전화번호 %s로 전화를 겁니다....\n",
                list[index].name, list[index].phone);
        }
    }
}

