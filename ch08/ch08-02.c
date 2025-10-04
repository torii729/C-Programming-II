/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ���� �Լ��� ������ �ǽ�
	��¥ : 2025.09.17
*/

#include <stdio.h>

int test_function_pointer();
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);

// ��ɸ�: main. ���α׷� ������
// ����: �Լ� ������ �ǽ� �Լ��� ȣ���Ͽ� �����Ѵ�.
// �Է�: ����
// ���: �� �Լ� ������ ȣ�� ����� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
	test_function_pointer();
	return 0;
}

/*
	�Լ���: test_function_pointer
	����: �Լ� �����͸� �����Ͽ� add, sub, mul ���� �Լ��� ������ ����Ű�� �� ��,
		  �����͸� ���� �Լ��� ȣ���ϰ� ����� ����Ѵ�.
	�Է�: ����
	���: �� �Լ� ȣ�� ����� �ֿܼ� ����Ѵ�.
	����: ����
*/
int test_function_pointer()
{
	double (*pfunc)(double a, double b) = NULL; // double�� �Ű����� 2��, double ��ȯ �Լ� ������
	double result = 0.0;

	pfunc = add; // �Լ� �����Ϳ� add �Լ��� �ּҸ� ����
	add(3.0, 4.0);
	result = (*pfunc)(3, 4); // �Լ� �����ͷ� add �Լ� ȣ��

	printf("(*pfunc)(3, 4)�� ����� : %.1f\n", (*pfunc)(3, 4));

	pfunc = mul; // �Լ� �����Ϳ� mul �Լ��� �ּҸ� ����
	printf("(*pfunc)(3, 4)�� ����� : %.1f\n", (*pfunc)(3, 4));

	return 0;
}

/*
	�Լ���: add
	����: �� �Ǽ��� ���� ����Ͽ� ��ȯ�Ѵ�.
	�Է�: double a, double b
	���: ����
	��ȯ: �� ���� ��
*/
double add(double a, double b)
{
	return a + b;
}

/*
	�Լ���: sub
	����: �� �Ǽ��� ���� ����Ͽ� ��ȯ�Ѵ�.
	�Է�: double a, double b
	���: ����
	��ȯ: a - b�� �����
*/
double sub(double a, double b)
{
	return a - b;
}

/*
	�Լ���: mul
	����: �� �Ǽ��� ���� ����Ͽ� ��ȯ�Ѵ�.
	�Է�: double a, double b
	���: ����
	��ȯ: �� ���� ��
*/
double mul(double a, double b)
{
	return a * b;
}
