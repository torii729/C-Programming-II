/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 10. 3x3 행렬의 합을 구하는 add_matrix 함수 작성. 행렬로 사용될 2차원 배열은 마음대로 초기화해도 된다.
    날짜 : 2025.09.22
*/

#include <stdio.h>

void test(void);
void add_matrix(int x[][3], int y[][3], int out[][3]);
void print_mat3(int m[][3], const char* title);

/*
    기능명: main. 프로그램 시작점
    내용: test 함수를 호출하여 3x3 행렬의 합을 계산하고 출력한다.
    입력: 없음
    출력: 각 행렬 및 합 행렬을 콘솔에 출력한다.
    오류: 없음
*/
int main(void)
{
    test();
    return 0;
}

/*
    기능명: add_matrix. 두 3x3 행렬의 합 계산
    내용: 3x3 크기의 행렬 x와 y를 더하여 out에 저장한다.
    입력: int x[][3], int y[][3], int out[][3]
    출력: 없음 (결과는 out 배열에 저장됨)
    오류: 없음
*/
void add_matrix(int x[][3], int y[][3], int out[][3])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            out[i][j] = x[i][j] + y[i][j];
        }
    }
}

/*
    기능명: print_mat3. 3x3 행렬 출력
    내용: 3x3 행렬을 보기 좋은 형태로 콘솔에 출력한다.
    입력: int m[][3] (행렬), const char* title (행렬 이름)
    출력: 콘솔에 행렬 내용 출력
    오류: 없음
*/
void print_mat3(int m[][3], const char* title)
{
    int i = 0;
    int j = 0;

    printf("%s\n", title);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

/*
    기능명: test. add_matrix 함수 테스트
    내용: 3x3 행렬 두 개를 초기화하고, add_matrix 함수를 호출해 합을 계산한 뒤 결과를 출력한다.
    입력: 없음
    출력: 행렬 x, y, 그리고 합 행렬 z를 콘솔에 출력한다.
    오류: 없음
*/
void test(void)
{
    int x[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int y[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int z[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

    print_mat3(x, "x:");
    printf("\n");
    print_mat3(y, "y:");
    printf("\n");

    add_matrix(x, y, z);

    print_mat3(z, "x + y:");
}
