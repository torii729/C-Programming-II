/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 4. Ư�� ������ �ʱ�ȭ�� ������ �迭�� ���Ͽ� �迭�� ���� �� �ִ��� ���� ���ҿ�
		�ּڰ��� ���� ���Ҹ� ã�Ƽ� �ε����� ���� �Բ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
		�迭�� �ʱⰪ�� ������� ���Ͻÿ�.
	��¥ : 2025.09.16
*/

/*
	�ٽ� ����:
	�ִ񰪰� �ּڰ��� ��� �˾Ƴ� ���ΰ�?
	�ε��� ����ϴ� ����� �����ΰ�?
*/

#include <stdio.h>

void array();
void maxArray(int arrayInt[], int size);
void minArray(int arrayInt[], int size);
void printArray(int arrayInt[], int size);

// ��ɸ�: main. ���α׷� ������
// ����: array �Լ��� ȣ���Ͽ� �迭�� �ʱ�ȭ�ϰ�, �ִ񰪰� �ּڰ��� ����Ѵ�.
// �Է�: ����
// ���: �迭, �ִ�, �ּڰ��� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
	array();
	return 0;
}

// ��ɸ�: array. �迭 �ʱ�ȭ �� ó��
// ����: ���� �迭�� �����ϰ� �ʱ�ȭ�� ��, printArray, maxArray, minArray �Լ��� ȣ���Ѵ�.
// �Է�: ����
// ���: �迭 ����, �ִ�, �ּڰ��� �ֿܼ� ����Ѵ�.
// ����: ����
void array()
{
	int arrayInt[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
	int size = sizeof(arrayInt) / sizeof(arrayInt[0]);

	printArray(arrayInt, size);
	maxArray(arrayInt, size);
	minArray(arrayInt, size);
}

// ��ɸ�: printArray. �迭 ���
// ����: ���޹��� �迭�� ��� ���Ҹ� ������� ����Ѵ�.
// �Է�: int arrayInt[] (���� �迭), int size (�迭 ũ��)
// ���: �迭�� ��� ���Ҹ� �ֿܼ� ����Ѵ�.
// ����: ����
void printArray(int arrayInt[], int size)
{
	printf("�迭 : ");
	for (int n = 0; n < size; n++)
	{
		printf("%d ", arrayInt[n]);
	}
	printf("\n");
}

// ��ɸ�: maxArray. �迭�� �ִ� Ž��
// ����: �迭 �� �ִ񰪰� �� �ε����� ã�� ����Ѵ�.
// �Է�: int arrayInt[] (���� �迭), int size (�迭 ũ��)
// ���: �ִ񰪰� �ش� �ε����� �ֿܼ� ����Ѵ�.
// ����: ����
void maxArray(int arrayInt[], int size)
{
	int max = arrayInt[0];
	int maxIndex = 0;

	for (int i = 1; i < size; i++)
	{
		if (arrayInt[i] > max)
		{
			max = arrayInt[i];
			maxIndex = i; // �ִ� �߻� �� ���� �ε����� ����
		}
	}

	printf("�ִ� : �ε��� = %d, �� = %d\n", maxIndex, max);
}

// ��ɸ�: minArray. �迭�� �ּڰ� Ž��
// ����: �迭 �� �ּڰ��� �� �ε����� ã�� ����Ѵ�.
// �Է�: int arrayInt[] (���� �迭), int size (�迭 ũ��)
// ���: �ּڰ��� �ش� �ε����� �ֿܼ� ����Ѵ�.
// ����: ����
void minArray(int arrayInt[], int size)
{
	int min = arrayInt[0];
	int minIndex = 0;

	for (int j = 1; j < size; j++)
	{
		if (arrayInt[j] < min)
		{
			min = arrayInt[j];
			minIndex = j;
		}
	}

	printf("�ּڰ� : �ε��� = %d, �� = %d", minIndex, min);
}
