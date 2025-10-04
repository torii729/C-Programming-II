/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 키보드로부터 다음 레코드를 한 줄 입력받아 필드를 구분하여
		구조체 배열에 저장 후 출력하는 프로그램을 작성하시오.
	날짜 : 2025.10.01
*/

/*
	문제
	입력 : 이름 | 학번 | 학과 | 학년(정수)
	입력 종료 조건 : "exit" 입력
	입력과 입력받은 것 파싱하여 저장, 출력. 이렇게 함수 3개 이상쯤
*/

// 함수는 입력 1 저장 1 출력 1 총 3개
// strtok로 버티컬 바 자르고 배열 이용
// 정보 받을 때마다 어떠한 변수 하나 증가(이를 가지고 원활한 출력)
// strcpy로 복사하여 ct->name[0] = '강', ct->name[1] = '기', ct->name[2] = '민' 이렇게 하려고함
// 이렇게되면 정수인 학년 변수는 atoi로 정수로 변환해서 저장하면 됨

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf, gets
#include <string.h> // str~
#include <stdlib.h> // atoi

#define SIZE 100

typedef struct Student {
	char name[20];
	char id[20];
	char major[20];
	int year;
} Student;

int input_student(Student arr[]);
void print_student(Student arr[], int count);
void save_student(char* line, Student* arr);

// 기능명: main. 학생 정보 입력 및 출력 프로그램
// 내용: 학생 정보를 입력받아 구조체 배열에 저장하고, 전체 목록을 출력한다.
// 입력: 이름|학번|학과|학년 형태의 문자열 입력
// 출력: 모든 학생의 정보 출력
// 오류: 없음

int main(void)
{
	Student arr[SIZE];
	int cnt = 0;

	cnt = input_student(arr);
	print_student(arr, cnt);
	return 0;
}

// 기능명: input_student. 학생 정보 입력 함수
// 내용: 사용자로부터 학생 정보를 입력받아 save_student 함수를 통해 구조체에 저장한다.
// 입력: Student arr[] (구조체 배열)
// 출력: 입력받은 학생 수 반환
// 오류: 없음

int input_student(Student arr[])
{
	int count = 0;
	char input_line[SIZE] = { 0 };
	printf("이름|학번|학과|학년\n예시 : 기민|202500000|컴퓨터공학과|1\n");

	while (1)
	{
		printf("입력(exit : 종료) : ");
		gets(input_line);

		if (strcmp(input_line, "exit") == 0)
		{
			printf("입력을 종료합니다.\n");
			break;
		}
		save_student(input_line, &arr[count]); // &arr[count]는 count번째 학생 구조체 1개
		count++;
	}
	return count;
}

// 기능명: save_student. 학생 정보 저장 함수
// 내용: 입력받은 문자열을 '|' 기준으로 나누어 구조체 멤버에 저장한다.
// 입력: char* line (입력 문자열), Student* arr (저장할 구조체 주소)
// 출력: 없음
// 오류: 없음

void save_student(char* line, Student* arr)
{
	strcpy(arr->name, strtok(line, "|"));
	strcpy(arr->id, strtok(NULL, "|"));
	strcpy(arr->major, strtok(NULL, "|"));
	arr->year = atoi(strtok(NULL, "|"));
}

// 기능명: print_student. 학생 정보 출력 함수
// 내용: 저장된 모든 학생의 정보를 순서대로 출력한다.
// 입력: Student arr[] (구조체 배열), int count (학생 수)
// 출력: 학생 목록 콘솔 출력
// 오류: 없음

void print_student(Student arr[], int count)
{
	printf("\n ~ 학생 목록 ~ \n");
	int num = 1;
	for (int i = 0; i < count; i++)
	{
		printf("%d번째 학생 | 이름 : %s, 학번 : %s, 학과 : %s, 학년 : %d\n",
			num, arr[i].name, arr[i].id, arr[i].major, arr[i].year);
		num++;
	}
}
