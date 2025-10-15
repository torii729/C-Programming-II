/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch11 ���� 11-3 : ����� ����� �����ϴ� accumulator �Լ��� ���� �� ȣ��
	��¥ : 2025.10.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void accumulator(char op, int operand);

// ��ɸ�: main
// ����: ����ڷκ��� �����ڿ� ������ �Է¹޾� accumulator �Լ��� ȣ���Ͽ� ����� ����� ����
// �Է�: ����
// ���: ���� ����� �ֿܼ� ���
// ����: �߸��� �����ڰ� �ԷµǸ� �ƹ� �۾��� �������� ����
int main(void)
{
	while (1)
	{
		char op;
		int num;
		printf("�����ڿ� ������ �Է��ϼ���(. 0 �Է� �� ����) : ");
		scanf(" %c %d", &op, &num);

		if(op == '.' && num == 0)
			break;

		accumulator(op, num);
	}
}

// ��ɸ�: accumulator
// ����: static ���� ������ ����Ͽ� ����� ����� ����. �Էµ� �����ڿ� ���� ���� ����� �����ϰ� ���
// �Է�: ������(op)�� �ǿ�����(operand)
// ���: ���� ����� �ֿܼ� ���
// ����: �߸��� �����ڰ� �ԷµǸ� �ƹ� �۾��� �������� ����
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