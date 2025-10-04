/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : ch07 PPT 문제 풀이

    배열 범위 중 최소값 찾는 함수 :
    int findMinInt(int R[], int from, int to) : from부터 to까지 최소값을 갖는 인덱스 하나를 반환

    배열의 두 원소를 교환하기 :
    void swapInt(int R[], int aindex, int bindex)

    두 함수를 구현하고, 이를 이용한 선택정렬 함수를 구현
    Int selectionSortInt(int R[], int length) : 정상 0, 실패 0이 아닌 수

    테스트 코드
    잘 동작하는지 시험하는 함수를 작성하고 main에서 호출
    Int test_selectionSortInt(void) : 성공 0, 실패 0이 아닌 수
    임의의 정수 배열을 선언한 후 정렬하고, 원래 배열과 정렬된 결과를 출력

    날짜 : 2025.09.15
*/

#include <stdio.h>

int findMinInt(int R[], int from, int to);
void swapInt(int R[], int aindex, int bindex);
int selectionSortInt(int R[], int length);
int test_selectionSortInt();

// 기능명: main. 테스트 실행
// 내용: 선택 정렬 테스트 함수를 실행한다.
// 입력: 없음
// 출력: 원본 배열과 정렬된 배열을 콘솔에 출력한다.
// 오류: 없음
int main()
{
    test_selectionSortInt();
    return 0;
}

// 기능명: findMinInt. 최소값 인덱스 찾기
// 내용: 배열 R에서 from부터 to까지 구간 중 최소값의 인덱스를 찾아 반환한다.
// 입력: int R[] (정수 배열), int from (시작 인덱스), int to (끝 인덱스)
// 출력: 최소값을 갖는 인덱스 번호
// 오류: from이나 to가 배열 범위를 벗어나면 잘못된 동작 가능
int findMinInt(int R[], int from, int to)
{
    int min_Index = from;
    int i = 0;

    for (i = from + 1; i <= to; i++)
    {
        if (R[i] < R[min_Index])
        {
            min_Index = i;
        }
    }
    return min_Index;
}

// 기능명: swapInt. 배열의 두 원소 교환
// 내용: 배열 R의 aindex 원소와 bindex 원소의 값을 서로 바꾼다.
// 입력: int R[] (정수 배열), int aindex (첫 번째 인덱스), int bindex (두 번째 인덱스)
// 출력: 없음
// 오류: 인덱스가 배열 범위를 벗어나면 잘못된 동작 가능
void swapInt(int R[], int aindex, int bindex)
{
    int temp = R[aindex];
    R[aindex] = R[bindex];
    R[bindex] = temp;
}

// 기능명: selectionSortInt. 선택 정렬
// 내용: 배열 R을 오름차순으로 정렬한다. 최소값을 차례대로 선택하여 앞으로 보낸다.
// 입력: int R[] (정수 배열), int length (배열 길이)
// 출력: 정상적으로 동작하면 0 반환, 실패 시 0이 아닌 수 반환
// 오류: length가 음수이거나 배열 크기를 초과할 경우 잘못된 동작 가능
int selectionSortInt(int R[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = findMinInt(R, i, length - 1);

        if (minIndex != i)
        {
            swapInt(R, i, minIndex);
        }
    }
    return 0;
}

// 기능명: test_selectionSortInt. 선택 정렬 테스트
// 내용: 임의의 정수 배열을 선언하여 선택 정렬 함수를 검증한다.
// 입력: 없음
// 출력: 원래 배열과 정렬된 배열을 콘솔에 출력한다.
// 오류: 없음
int test_selectionSortInt()
{
    int arr[8] = { 64, 25, 12, 22, 11, 90, 55, 3 };
    int length = 8;

    printf("원래 배열 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = selectionSortInt(arr, length);

    printf("정렬된 배열 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
