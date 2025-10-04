/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 12. ����ǥ ���� ���α׷�
		�¼��� 10���̸�, ������ �¼� ���� �Է¹޾� �� �¼����� ������� �����Ѵ�.
		O�̸� ���� ����, X�� ���� �Ұ��� �ǹ��Ѵ�. �� �̻� ������ �� ������ ���α׷��� �����Ѵ�.
	��¥ : 2025.09.16
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sit();
void sitPrint(int sitTrain[], int size);
void sitInput(int sitTrain[], int size);
void sitCheck(int sitTrain[], int size);

// ��ɸ�: main. ���α׷� ������
// ����: sit �Լ��� ȣ���Ͽ� �¼� ���� ���α׷��� �����Ѵ�.
// �Է�: ����
// ���: �¼� ���� �� ���� ����� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
	sit();
	return 0;
}

// ��ɸ�: sit. �¼� �迭 �ʱ�ȭ �� ���� ����
// ����: �¼� �迭�� �ʱ�ȭ�� �� sitInput �Լ��� ȣ���Ͽ� ���� ������ �����Ѵ�.
// �Է�: ����
// ���: �¼� ���� �� ���� ����� �ֿܼ� ����Ѵ�.
// ����: ����
void sit()
{
	int sitTrain[10] = { 0 };
	int size = sizeof(sitTrain) / sizeof(sitTrain[0]);

	sitInput(sitTrain, size);
}

// ��ɸ�: sitPrint. ���� �¼� ���� ���
// ����: �迭�� ��ȸ�ϸ� 0�� 'O', 1�� 'X'�� ����Ͽ� ���� �¼� ���¸� ǥ���Ѵ�.
// �Է�: int sitTrain[] (�¼� �迭), int size (�¼� ��)
// ���: �¼� ���¸� �ֿܼ� ����Ѵ�.
// ����: ����
void sitPrint(int sitTrain[], int size)
{
	printf("���� �¼� : [ ");

	for (int i = 0; i < size; i++)
	{
		if (sitTrain[i] == 0)
			printf("O ");
		else
			printf("X ");
	}
	printf("]\n");
}

// ��ɸ�: sitInput. �¼� ���� ó��
// ����: ����ڷκ��� ������ �¼� ���� �Է¹ް�, ������ �¼��� ������� �����Ѵ�.
//       ���� �¼����� ���� �¼��� �����Ϸ� �ϸ� ��� �� ���α׷��� �����Ѵ�.
// �Է�: int sitTrain[] (�¼� �迭), int size (�¼� ��)
// ���: ���ŵ� �¼� ��ȣ�� ���¸� �ֿܼ� ����Ѵ�.
// ����: ���� �¼����� ���� �¼��� ��û �� ���� �Ұ� �޽��� ��� �� ����
void sitInput(int sitTrain[], int size)
{
	int num = 0;

	while (1)
	{
		int sitReserved[10] = { 0 };
		int reserved = 0;
		int remain = 0;

		sitPrint(sitTrain, size);

		printf("������ �¼���? ");
		scanf("%d", &num);

		// ���� �¼� �� ���
		for (int i = 0; i < size; i++)
		{
			if (sitTrain[i] == 0)
				remain++;
		}

		// ���� �Ұ� ����
		if (remain < num)
		{
			printf("���� �¼��� �����մϴ�.\n");
			break;
		}

		// ���� ������ �¼����� ������� ����
		for (int i = 0; reserved < num && i < size; i++)
		{
			if (sitTrain[i] == 0)
			{
				sitTrain[i] = 1;
				sitReserved[reserved] = i + 1; // ���� �¼� ��ȣ�� 1���� ����
				reserved++;
			}
		}

		// ���� ��� ���
		for (int j = 0; j < reserved; j++)
			printf("%d ", sitReserved[j]);
		printf("�� �¼��� �����߽��ϴ�.\n");

		sitCheck(sitTrain, size);
	}
}

// ��ɸ�: sitCheck. ��� �¼� ���� �Ϸ� ���� Ȯ��
// ����: �¼� �迭�� Ȯ���Ͽ� ���� �¼��� ������ ���� ���� �޽����� ����Ѵ�.
// �Է�: int sitTrain[] (�¼� �迭), int size (�¼� ��)
// ���: ��� �¼��� ���� �Ϸ�Ǿ��� ��� �޽����� ����Ѵ�.
// ����: ����
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
		printf("��� �¼� ���� �Ϸ�.\n");
		exit(0); // ��� ����
	}
}
