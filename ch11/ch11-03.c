/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch11-04.c�� �����Ͽ� ���� 11-1 : ���� ������ extern ����
	��¥ : 2025.10.15
*/

#include <stdio.h>

void test_global(void); // ch11-04.c�� ���ǵ� �Լ��� ȣ���Ϸ��� �Լ� ������ �ʿ��ϴ�.

extern int global; // ch11-04.c�� ���ǵ� global ������ ����ϱ� ���� extern �����Ѵ�.

// ��ɸ�: main
// ����: test_global �Լ��� ȣ���Ͽ� global ���� ���� �����ϰ� ���
// �Է�: ����
// ���: ����� global ���� ��
// ����: ����
int main(void)
{
	test_global();
	printf("global = %d\n", global);

	return 0;
}