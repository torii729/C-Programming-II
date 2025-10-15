/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 14. 13번 프로그램을 실행해서 크기가 다른 2진 파일을 2개 생성한 다음 두 파일을 읽어서 하나의 int 배열을 생성한 다음
        정렬 후에 다시 2진 파일로 저장하는 프로그램을 작성하시오.
    날짜 : 2025.11.9
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test(void);
int  load_int_array_from_binary(const char* filename, int** pArr);
int  save_int_array_to_binary(const char* filename, const int* arr, int n);
int  compare_ints(const void* a, const void* b);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 2진 파일 병합 및 정렬 프로그램을 실행한다.
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
    내용: 두 개의 2진 파일명을 입력받아 각 파일에서 정수 배열을 읽어 오고,
          두 배열을 합쳐 정렬한 후 다른 2진 파일로 저장한다.
    입력: 콘솔에서 첫 번째 파일명, 두 번째 파일명, 저장할 파일명을 입력받는다.
    출력: 각 파일에서 읽은 정수 개수와 최종 저장된 개수를 콘솔에 출력한다.
    오류: 파일 열기 실패, 메모리 할당 실패 시 오류 메시지를 출력하고 종료한다.
*/
void test(void)
{
    char file1[300];
    char file2[300];
    char outfile[300];
    int* arr1 = NULL;
    int* arr2 = NULL;
    int* merged = NULL;
    int n1, n2, n_all;
    int i;

    printf("첫 번째 파일명? ");
    if (scanf_s("%s", file1, sizeof(file1)) != 1)
    {
        printf("파일명을 읽을 수 없습니다.\n");
        return;
    }

    n1 = load_int_array_from_binary(file1, &arr1);
    if (n1 <= 0)
    {
        printf("첫 번째 파일에서 정수를 읽지 못했습니다.\n");
        return;
    }
    printf("정수 %d개를 읽었습니다.\n", n1);

    printf("두 번째 파일명? ");
    if (scanf_s("%s", file2, sizeof(file2)) != 1)
    {
        printf("파일명을 읽을 수 없습니다.\n");
        free(arr1);
        return;
    }

    n2 = load_int_array_from_binary(file2, &arr2);
    if (n2 <= 0)
    {
        printf("두 번째 파일에서 정수를 읽지 못했습니다.\n");
        free(arr1);
        return;
    }
    printf("정수 %d개를 읽었습니다.\n", n2);

    n_all = n1 + n2;
    merged = (int*)malloc(sizeof(int) * n_all);
    if (merged == NULL)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        free(arr1);
        free(arr2);
        return;
    }

    for (i = 0; i < n1; i++)
    {
        merged[i] = arr1[i];
    }
    for (i = 0; i < n2; i++)
    {
        merged[n1 + i] = arr2[i];
    }

    free(arr1);
    free(arr2);

    qsort(merged, n_all, sizeof(int), compare_ints);

    printf("저장할 파일명? ");
    if (scanf_s("%s", outfile, sizeof(outfile)) != 1)
    {
        printf("파일명을 읽을 수 없습니다.\n");
        free(merged);
        return;
    }

    if (!save_int_array_to_binary(outfile, merged, n_all))
    {
        printf("정렬된 배열을 파일로 저장하지 못했습니다.\n");
        free(merged);
        return;
    }

    printf("정수 %d개를 저장했습니다.\n", n_all);

    free(merged);
}

/*
    기능명: load_int_array_from_binary. 2진 파일에서 정수 배열 읽기
    내용: 지정된 2진 파일을 열어, 처음에 저장된 정수 N을 읽고
          크기 N의 int 배열을 동적 할당한 뒤 내용을 모두 읽어 온다.
    입력: 파일 이름 문자열, int 포인터의 포인터(읽은 배열 주소를 돌려주기 위한 인자).
    출력: 읽어 온 정수의 개수 N을 반환하고, pArr가 가리키는 곳에 동적 배열 주소를 저장한다.
    오류: 파일 열기 실패, 읽기 실패, 메모리 할당 실패 시 0 이하를 반환하고 pArr에는 NULL을 저장한다.
*/
int load_int_array_from_binary(const char* filename, int** pArr)
{
    FILE* fp;
    int n;
    int* arr;

    *pArr = NULL;

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("파일 %s을(를) 열 수 없습니다.\n", filename);
        return 0;
    }

    if (fread(&n, sizeof(int), 1, fp) != 1 || n <= 0)
    {
        printf("파일 %s에서 개수를 읽지 못했습니다.\n", filename);
        fclose(fp);
        return 0;
    }

    arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        fclose(fp);
        return 0;
    }

    if (fread(arr, sizeof(int), n, fp) != (size_t)n)
    {
        printf("파일 %s에서 데이터를 모두 읽지 못했습니다.\n", filename);
        free(arr);
        fclose(fp);
        return 0;
    }

    fclose(fp);
    *pArr = arr;
    return n;
}

/*
    기능명: save_int_array_to_binary. 2진 파일로 정수 배열 저장
    내용: 정수 개수 N과 정수 배열 내용을 2진 형식으로 지정된 파일에 저장한다.
    입력: 파일 이름 문자열, int 배열 포인터, 배열 크기 n.
    출력: 저장에 성공하면 1, 실패하면 0을 반환한다.
    오류: 파일을 열지 못하거나 쓰기에 실패하면 0을 반환한다.
*/
int save_int_array_to_binary(const char* filename, const int* arr, int n)
{
    FILE* fp;

    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("파일 %s을(를) 저장용으로 열 수 없습니다.\n", filename);
        return 0;
    }

    if (fwrite(&n, sizeof(int), 1, fp) != 1)
    {
        printf("개수를 파일에 기록하지 못했습니다.\n");
        fclose(fp);
        return 0;
    }

    if (fwrite(arr, sizeof(int), n, fp) != (size_t)n)
    {
        printf("데이터를 파일에 모두 기록하지 못했습니다.\n");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

/*
    기능명: compare_ints. qsort용 비교 함수
    내용: 두 개의 int 값을 비교하여 qsort에서 사용할 순서를 결정한다.
    입력: const void 포인터 두 개(각각 int 하나를 가리킨다).
    출력: 첫 번째 값이 작으면 음수, 같으면 0, 크면 양수를 반환한다.
    오류: 없음
*/
int compare_ints(const void* a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y)
    {
        return -1;
    }
    else if (x > y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
