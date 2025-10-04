/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 강의 구조체 실습
	날짜 : 2025.09.30
*/

#include "contact.h"
#include <stdio.h>

// 함수 선언
Point mul10(Point p);
int test_point();

// 기능명: main. 구조체 실습 프로그램 실행
// 내용: test_point 함수를 호출하여 구조체 연산 결과를 확인한다.
// 입력: 없음
// 출력: 구조체의 멤버 값 출력
// 오류: 없음
int main()
{
	test_point();
	return 0;
}

// 기능명: mul10. 구조체 값 10배 계산
// 내용: 전달받은 Point 구조체의 x, y 값을 각각 10배로 만들어 반환한다.
// 입력: Point p (x, y 값을 가진 구조체)
// 출력: Point (x, y가 10배로 된 구조체)
// 오류: 없음
Point mul10(Point p)
{
	p.x *= 10;
	p.y *= 10;

	return p;
}

// 기능명: test_point. 구조체 연산 테스트
// 내용: Point 구조체 변수를 생성하고 mul10 함수를 통해 결과를 출력한다.
// 입력: 없음
// 출력: 계산된 구조체의 x, y 값 콘솔 출력
// 오류: 없음
int test_point()
{
	Point p1 = { 1, 2 };
	Point p2 = { 3, 4 };
	Point p3 = { 0 };
	p3 = mul10(p1);

	printf("p3.x : %d, p3.y : %d\n", p3.x, p3.y);

	return 0;
}
