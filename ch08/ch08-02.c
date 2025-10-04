/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 강의 함수와 포인터 실습
	날짜 : 2025.09.17
*/

#include <stdio.h>

int test_function_pointer();
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);

// 기능명: main. 프로그램 시작점
// 내용: 함수 포인터 실습 함수를 호출하여 실행한다.
// 입력: 없음
// 출력: 각 함수 포인터 호출 결과를 콘솔에 출력한다.
// 오류: 없음
int main()
{
	test_function_pointer();
	return 0;
}

/*
	함수명: test_function_pointer
	내용: 함수 포인터를 선언하여 add, sub, mul 등의 함수를 번갈아 가리키게 한 후,
		  포인터를 통해 함수를 호출하고 결과를 출력한다.
	입력: 없음
	출력: 각 함수 호출 결과를 콘솔에 출력한다.
	오류: 없음
*/
int test_function_pointer()
{
	double (*pfunc)(double a, double b) = NULL; // double형 매개변수 2개, double 반환 함수 포인터
	double result = 0.0;

	pfunc = add; // 함수 포인터에 add 함수의 주소를 저장
	add(3.0, 4.0);
	result = (*pfunc)(3, 4); // 함수 포인터로 add 함수 호출

	printf("(*pfunc)(3, 4)의 결과는 : %.1f\n", (*pfunc)(3, 4));

	pfunc = mul; // 함수 포인터에 mul 함수의 주소를 저장
	printf("(*pfunc)(3, 4)의 결과는 : %.1f\n", (*pfunc)(3, 4));

	return 0;
}

/*
	함수명: add
	내용: 두 실수의 합을 계산하여 반환한다.
	입력: double a, double b
	출력: 없음
	반환: 두 수의 합
*/
double add(double a, double b)
{
	return a + b;
}

/*
	함수명: sub
	내용: 두 실수의 차를 계산하여 반환한다.
	입력: double a, double b
	출력: 없음
	반환: a - b의 결과값
*/
double sub(double a, double b)
{
	return a - b;
}

/*
	함수명: mul
	내용: 두 실수의 곱을 계산하여 반환한다.
	입력: double a, double b
	출력: 없음
	반환: 두 수의 곱
*/
double mul(double a, double b)
{
	return a * b;
}
