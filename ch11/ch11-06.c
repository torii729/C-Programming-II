/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : ch11 예제 11-3 : 누산기 기능을 제공하는 accumulator 함수의 정의 및 호출
	날짜 : 2025.10.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void accumulator(char op, int operand);

// 기능명: main
// 내용: 사용자로부터 연산자와 정수를 입력받아 accumulator 함수를 호출하여 누산기 기능을 수행
// 입력: 없음
// 출력: 연산 결과를 콘솔에 출력
// 오류: 잘못된 연산자가 입력되면 아무 작업도 수행하지 않음
int main(void)
{
	while (1)
	{
		char op;
		int num;
		printf("연산자와 정수를 입력하세요(. 0 입력 시 종료) : ");
		scanf(" %c %d", &op, &num);

		if(op == '.' && num == 0)
			break;

		accumulator(op, num);
	}
}

// 기능명: accumulator
// 내용: static 지역 변수를 사용하여 누산기 기능을 제공. 입력된 연산자에 따라 누산 결과를 갱신하고 출력
// 입력: 연산자(op)와 피연산자(operand)
// 출력: 연산 결과를 콘솔에 출력
// 오류: 잘못된 연산자가 입력되면 아무 작업도 수행하지 않음
void accumulator(char op, int operand)
{
	static int result = 0;

	switch (op)
	{
		case '+':
			result += operand;
			break;
		case '-':
			result -= operand;
			break;
		case '*':
			result *= operand;
			break;
		case '/':
			result /= operand;
			break;
		default:
			return;
	}
	printf("%c %d = %d\n", op, operand, result);
}