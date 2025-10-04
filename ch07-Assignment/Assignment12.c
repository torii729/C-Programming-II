/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 12. 기차표 예매 프로그램
		좌석은 10개이며, 예매할 좌석 수를 입력받아 빈 좌석부터 순서대로 예매한다.
		O이면 예매 가능, X면 예매 불가를 의미한다. 더 이상 예매할 수 없으면 프로그램을 종료한다.
	날짜 : 2025.09.16
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sit();
void sitPrint(int sitTrain[], int size);
void sitInput(int sitTrain[], int size);
void sitCheck(int sitTrain[], int size);

// 기능명: main. 프로그램 시작점
// 내용: sit 함수를 호출하여 좌석 예매 프로그램을 실행한다.
// 입력: 없음
// 출력: 좌석 상태 및 예매 결과를 콘솔에 출력한다.
// 오류: 없음
int main()
{
	sit();
	return 0;
}

// 기능명: sit. 좌석 배열 초기화 및 예매 시작
// 내용: 좌석 배열을 초기화한 뒤 sitInput 함수를 호출하여 예매 과정을 시작한다.
// 입력: 없음
// 출력: 좌석 상태 및 예매 결과를 콘솔에 출력한다.
// 오류: 없음
void sit()
{
	int sitTrain[10] = { 0 };
	int size = sizeof(sitTrain) / sizeof(sitTrain[0]);

	sitInput(sitTrain, size);
}

// 기능명: sitPrint. 현재 좌석 상태 출력
// 내용: 배열을 순회하며 0은 'O', 1은 'X'로 출력하여 현재 좌석 상태를 표시한다.
// 입력: int sitTrain[] (좌석 배열), int size (좌석 수)
// 출력: 좌석 상태를 콘솔에 출력한다.
// 오류: 없음
void sitPrint(int sitTrain[], int size)
{
	printf("현재 좌석 : [ ");

	for (int i = 0; i < size; i++)
	{
		if (sitTrain[i] == 0)
			printf("O ");
		else
			printf("X ");
	}
	printf("]\n");
}

// 기능명: sitInput. 좌석 예매 처리
// 내용: 사용자로부터 예매할 좌석 수를 입력받고, 가능한 좌석을 순서대로 예매한다.
//       남은 좌석보다 많은 좌석을 예매하려 하면 경고 후 프로그램을 종료한다.
// 입력: int sitTrain[] (좌석 배열), int size (좌석 수)
// 출력: 예매된 좌석 번호와 상태를 콘솔에 출력한다.
// 오류: 남은 좌석보다 많은 좌석을 요청 시 예매 불가 메시지 출력 후 종료
void sitInput(int sitTrain[], int size)
{
	int num = 0;

	while (1)
	{
		int sitReserved[10] = { 0 };
		int reserved = 0;
		int remain = 0;

		sitPrint(sitTrain, size);

		printf("예매할 좌석수? ");
		scanf("%d", &num);

		// 남은 좌석 수 계산
		for (int i = 0; i < size; i++)
		{
			if (sitTrain[i] == 0)
				remain++;
		}

		// 예매 불가 조건
		if (remain < num)
		{
			printf("예약 좌석이 부족합니다.\n");
			break;
		}

		// 예약 가능한 좌석부터 순서대로 예매
		for (int i = 0; reserved < num && i < size; i++)
		{
			if (sitTrain[i] == 0)
			{
				sitTrain[i] = 1;
				sitReserved[reserved] = i + 1; // 실제 좌석 번호는 1부터 시작
				reserved++;
			}
		}

		// 예매 결과 출력
		for (int j = 0; j < reserved; j++)
			printf("%d ", sitReserved[j]);
		printf("번 좌석을 예매했습니다.\n");

		sitCheck(sitTrain, size);
	}
}

// 기능명: sitCheck. 모든 좌석 예매 완료 여부 확인
// 내용: 좌석 배열을 확인하여 남은 좌석이 없으면 예매 종료 메시지를 출력한다.
// 입력: int sitTrain[] (좌석 배열), int size (좌석 수)
// 출력: 모든 좌석이 예매 완료되었을 경우 메시지를 출력한다.
// 오류: 없음
void sitCheck(int sitTrain[], int size)
{
	int all = 1;

	for (int i = 0; i < size; i++)
	{
		if (sitTrain[i] == 0)
		{
			all = 0;
			break;
		}
	}

	if (all == 1)
	{
		printf("모든 좌석 예매 완료.\n");
		exit(0); // 즉시 종료
	}
}
