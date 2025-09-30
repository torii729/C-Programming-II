#include "contact.h"
#include <stdio.h>

Point mul10(Point p);
int test_point();

int main()
{
	test_point();
	return 0;
}

Point mul10(Point p)
{
	p.x *= 10;
	p.y *= 10;

	return p;
}

int test_point()
{
	Point p1 = { 1, 2 };
	Point p2 = { 3, 4 };
	Point p3 = { 0 };
	p3 = mul10(p1);

	printf("p3.x : %d, p3.y : %d\n", p3.x, p3.y);

	return 0;
}