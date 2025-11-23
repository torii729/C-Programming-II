/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 11. DATE 구조체와 공휴일 검사 프로그램
    날짜 : 2025.11.23
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int year;
    int month;
    int day;
} DATE;

void test(void);
void print_date(DATE d);
DATE set_as_today(void);
int is_same_date(DATE a, DATE b);
int load_holidays(const char* filename, DATE** pArr);
int is_holiday(const DATE* arr, int n, DATE target);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 공휴일 검사 프로그램을 실행한다.
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
    내용: 텍스트 파일에서 공휴일 날짜들을 읽어 DATE 배열로 저장한 뒤
          사용자가 입력한 날짜가 공휴일인지 반복 검사한다.
          0 0 0을 입력하면 종료한다.
    입력: 날짜(연 월 일) 3개를 반복 입력받는다.
    출력: 공휴일 여부를 출력한다.
    오류: 파일 열기 실패 시 공휴일 0개로 진행한다.
*/
void test(void)
{
    const char* filename = "holidays.txt";
    DATE* holidays = NULL;
    int count;
    DATE input;
    int ok;

    count = load_holidays(filename, &holidays);

    while (1)
    {
        printf("날짜(연월일)? ");
        ok = scanf_s("%d %d %d", &input.year, &input.month, &input.day);
        if (ok != 3)
        {
            break;
        }

        if (input.year == 0 && input.month == 0 && input.day == 0)
        {
            break;
        }

        print_date(input);
        if (is_holiday(holidays, count, input))
        {
            printf("은 공휴일입니다.\n");
        }
        else
        {
            printf("은 공휴일이 아닙니다.\n");
        }
    }

    free(holidays);
}

/*
    기능명: print_date. 날짜 출력
    내용: USE_USA_FORMAT 매크로가 정의되면 "Jan 1 2022" 형식으로,
          정의되지 않으면 "2022/1/1" 형식으로 출력한다.
    입력: DATE 구조체 1개.
    출력: 날짜 문자열을 콘솔에 출력한다.
    오류: 없음
*/
void print_date(DATE d)
{
#ifdef USE_USA_FORMAT
    const char* months[12] =
    {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };

    if (d.month >= 1 && d.month <= 12)
    {
        printf("%s %d %d", months[d.month - 1], d.day, d.year);
    }
    else
    {
        printf("%d %d %d", d.year, d.month, d.day);
    }
#else
    printf("%d/%d/%d", d.year, d.month, d.day);
#endif
}

/*
    기능명: set_as_today. 오늘 날짜 생성
    내용: 오늘 날짜로 DATE 구조체를 만든다.
          간단 구현을 위해 고정된 날짜를 반환한다.
    입력: 없음
    출력: 오늘 날짜 DATE.
    오류: 없음
*/
DATE set_as_today(void)
{
    DATE today;

    today.year = 2022;
    today.month = 1;
    today.day = 1;
    return today;
}

/*
    기능명: is_same_date. 날짜 비교
    내용: 두 DATE가 같은 연 월 일을 가지는지 비교한다.
    입력: DATE 2개.
    출력: 같으면 1, 다르면 0.
    오류: 없음
*/
int is_same_date(DATE a, DATE b)
{
    if (a.year == b.year && a.month == b.month && a.day == b.day)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
    기능명: load_holidays. 공휴일 목록 로드
    내용: 텍스트 파일에서 "연 월 일" 형식의 날짜를 모두 읽어
          동적 DATE 배열로 저장한다.
    입력: 파일명, 배열 주소를 돌려받을 포인터.
    출력: 읽은 개수 반환, pArr에 배열 주소 저장.
    오류: 파일이 없거나 메모리 실패 시 0 반환.
*/
int load_holidays(const char* filename, DATE** pArr)
{
    FILE* fp;
    DATE* arr;
    int count;
    DATE temp;
    int ok;

    *pArr = NULL;
    arr = NULL;
    count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return 0;
    }

    while (1)
    {
        ok = fscanf_s(fp, "%d %d %d", &temp.year, &temp.month, &temp.day);
        if (ok != 3)
        {
            break;
        }

        arr = (DATE*)realloc(arr, sizeof(DATE) * (count + 1));
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
    기능명: is_holiday. 공휴일 여부 검사
    내용: 공휴일 배열에서 target과 같은 날짜가 있는지 찾는다.
    입력: 공휴일 배열, 개수 n, 검사할 날짜.
    출력: 공휴일이면 1, 아니면 0.
    오류: 없음
*/
int is_holiday(const DATE* arr, int n, DATE target)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (is_same_date(arr[i], target))
        {
            return 1;
        }
    }
    return 0;
}
