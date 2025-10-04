/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 6. ũ�Ⱑ 10�� �Ǽ��� �迭�� ���ؼ� ���ҵ��� �������� ����� ���α׷��� �ۼ��Ͻÿ�.
		�Ǽ��� �迭�� �ʱⰪ�� ������� ���Ͻÿ�.
	��¥ : 2025.09.16
*/

#include <stdio.h>

void array();
void printArray(double arrayDouble[], int size);
void ArrayRe(double arrayDouble[], int size);

// ��ɸ�: main. ���α׷� ������
// ����: array �Լ��� ȣ���Ͽ� �迭�� �ʱ�ȭ�ϰ�,
//       ���� ��ȯ �� ��� ������ �����Ѵ�.
// �Է�: ����
// ���: ���� �迭�� ���� �迭�� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
	array();
	return 0;
}

// ��ɸ�: array. �迭 �ʱ�ȭ �� ���� ó��
// ����: �Ǽ��� �迭�� �ʱ�ȭ�ϰ�, printArray�� ���� �迭�� ����� ��
//       ArrayRe�� ȣ���Ͽ� �迭�� �������� ���� �� �ٽ� ����Ѵ�.
// �Է�: ����
// ���: ���� �迭�� ���� �迭�� �ֿܼ� ����Ѵ�.
// ����: ����
void array()
{
	double arrayDouble[10] = { 1.2, 3.1, 4.3, 4.5, 6.7, 2.3, 8.7, 9.5, 2.3, 5.8 };
	int size = sizeof(arrayDouble) / sizeof(arrayDouble[0]);

	printf("�迭 : ");
	printArray(arrayDouble, size);

	ArrayRe(arrayDouble, size);

	printf("���� : ");
	printArray(arrayDouble, size);
}

// ��ɸ�: printArray. �迭 ���
// ����: ���޹��� �Ǽ��� �迭�� ���Ҹ� ������� ����Ѵ�.
// �Է�: double arrayDouble[] (�Ǽ��� �迭), int size (�迭 ũ��)
// ���: �迭�� ��� ���Ҹ� �ֿܼ� �Ҽ��� ù° �ڸ����� ����Ѵ�.
// ����: ����
void printArray(double arrayDouble[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%.1lf ", arrayDouble[i]); // �Ҽ��� ù° �ڸ����� ���
	printf("\n");
}

// ��ɸ�: ArrayRe. �迭 ���� ��ȯ
// ����: �迭�� �հ� �� ���Ҹ� ��ȯ�Ͽ� ��ü �迭�� �������� �����.
// �Է�: double arrayDouble[] (�Ǽ��� �迭), int size (�迭 ũ��)
// ���: ���� (�迭 ��ü�� ������)
// ����: ����
void ArrayRe(double arrayDouble[], int size)
{
	for (int a = 0; a < (size / 2); a++)
	{
		double base = arrayDouble[a];
		arrayDouble[a] = arrayDouble[size - 1 - a];
		arrayDouble[size - 1 - a] = base;
	}
}
