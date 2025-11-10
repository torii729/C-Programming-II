/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 12. 연락처 검색 실패 시 추가하고 종료 시 파일 저장
    날짜 : 2025.11.23
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char phone[50];
} CONTACT;

void test(void);
int load_contacts(const char* filename, CONTACT** pArr);
int save_contacts(const char* filename, const CONTACT* arr, int n);
int find_contact(const CONTACT* arr, int n, const char* name);
void trim_newline(char* s);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 연락처 검색 프로그램을 실행한다.
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
    내용: 파일에서 연락처를 로드한 뒤 이름으로 검색한다.
          검색 실패 시 등록 여부를 물어보고 추가한다.
          종료 시 전체 연락처를 파일로 저장한다.
    입력: 연락처 파일명, 이름, 등록하는 경우 전화번호.
    출력: 검색 결과, 저장 결과 출력.
    오류: 파일 로드 실패나 메모리 실패 시에도 빈 목록으로 동작한다.
*/
void test(void)
{
    char filename[300];
    CONTACT* list;
    int count;
    char name[50];
    char phone[50];
    int idx;
    char yn[10];

    list = NULL;

    printf("연락처 파일명? ");
    if (scanf_s("%299s", filename, (unsigned)_countof(filename)) != 1)
    {
        return;
    }

    count = load_contacts(filename, &list);
    printf("%d개의 연락처를 로딩했습니다.\n", count);

    getchar();

    while (1)
    {
        printf("이름(. 입력 시 종료)? ");
        fgets(name, sizeof(name), stdin);
        trim_newline(name);

        if (strcmp(name, ".") == 0)
        {
            break;
        }

        idx = find_contact(list, count, name);
        if (idx >= 0)
        {
            printf("%s의 전화번호 %s로 전화를 겁니다....\n", list[idx].name, list[idx].phone);
        }
        else
        {
            printf("연락처를 찾을 수 없습니다. 연락처를 등록하시겠습니까(y/n)? ");
            fgets(yn, sizeof(yn), stdin);
            trim_newline(yn);

            if (yn[0] == 'y' || yn[0] == 'Y')
            {
                printf("전화번호? ");
                fgets(phone, sizeof(phone), stdin);
                trim_newline(phone);

                list = (CONTACT*)realloc(list, sizeof(CONTACT) * (count + 1));
                if (list == NULL)
                {
                    return;
                }

                strcpy_s(list[count].name, sizeof(list[count].name), name);
                strcpy_s(list[count].phone, sizeof(list[count].phone), phone);
                count++;
            }
        }
    }

    save_contacts(filename, list, count);
    printf("%s로 %d개의 연락처를 저장했습니다.\n", filename, count);

    free(list);
}

/*
    기능명: load_contacts. 연락처 로드
    내용: 텍스트 파일에서 name phone 형식으로 연락처를 모두 읽는다.
    입력: 파일명, 동적 배열 주소를 돌려받을 포인터.
    출력: 읽은 개수 반환, pArr에 배열 주소 저장.
    오류: 파일이 없으면 0 반환하고 빈 배열로 처리한다.
*/
int load_contacts(const char* filename, CONTACT** pArr)
{
    FILE* fp;
    CONTACT* arr;
    int count;
    CONTACT temp;

    *pArr = NULL;
    count = 0;
    arr = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf_s(fp, "%49s %49s", temp.name, (unsigned)_countof(temp.name), temp.phone, (unsigned)_countof(temp.phone)) == 2)
    {
        arr = (CONTACT*)realloc(arr, sizeof(CONTACT) * (count + 1));
        if (arr == NULL)
        {
            fclose(fp);
            return 0;
        }
        arr[count] = temp;
        count++;
    }

    fclose(fp);
    *pArr = arr;
    return count;
}

/*
    기능명: save_contacts. 연락처 저장
    내용: 연락처 배열을 name phone 형식으로 텍스트 파일에 저장한다.
    입력: 파일명, 연락처 배열, 개수 n.
    출력: 성공하면 1, 실패하면 0.
    오류: 파일 열기 실패 시 0 반환.
*/
int save_contacts(const char* filename, const CONTACT* arr, int n)
{
    FILE* fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%s %s\n", arr[i].name, arr[i].phone);
    }

    fclose(fp);
    return 1;
}

/*
    기능명: find_contact. 연락처 검색
    내용: 이름이 같은 연락처의 인덱스를 찾는다.
    입력: 연락처 배열, 개수 n, 찾을 이름.
    출력: 찾으면 인덱스, 없으면 -1.
    오류: 없음
*/
int find_contact(const CONTACT* arr, int n, const char* name)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (strcmp(arr[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

/*
    기능명: trim_newline. 개행 제거
    내용: 문자열 끝의 개행을 제거한다.
    입력: 문자열.
    출력: 없음
    오류: 없음
*/
void trim_newline(char* s)
{
    size_t n;

    n = strcspn(s, "\n");
    s[n] = '\0';
}
