/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch11-08.c�� �����Ͽ� ch11 ���� 11-4 : �ٸ� �ҽ� ���Ͽ� ���ǵ� �Լ��� ȣ��
	��¥ : 2025.10.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_gcd(int x, int y);
extern int get_factorial(int n);

// ��ɸ�: main
// ����: get_gcd �Լ��� ȣ���Ͽ� �� ���� �ִ������� ����ϰ�, get_factorial �Լ��� ȣ���Ͽ� ���丮�� ���� ���
// �Է�: ����
// ���: �� ���� �ִ������� ���丮�� ��
// ����: ����
int main(void)
{
	int i;
	srand((unsigned int)time(NULL));

	// 0~9 ������ ������ ���� 5���� �����Ͽ� ���丮�� ���
	for (i = 0; i < 5; i++)
	{
		int num = rand() % 10;
		printf("%2d! = %7d\n", num, get_factorial(num));
	}

	// 0~99 ������ ������ ���� 5���� �����Ͽ� �ִ����� ���
	for (i = 0; i < 5; i++)
	{
		int a = rand() % 100;
		int b = rand() % 100;
		printf("%2d�� %2d�� gcd = %2d\n", a, b, get_gcd(a, b));
	}

	return 0;
}