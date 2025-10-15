/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch11 ���� 11-2 : static ���� ����
	��¥ : 2025.10.15
*/

#include <stdio.h>

// ��ɸ�: test_static
// ����: ���� ������ static ���� ������ ���̸� �����ش�.
// �Է�: ����
// ���: ���� ������ static ���� ������ ���� ��
// ����: ����
void test_static(void)
{
	int local = 0; // �Լ��� ȣ��� ������ ����
	static int s_local = 0; // ���α׷� ���� �� ����

	printf("local = %d, ", local++);
	printf("s_local = %d\n", s_local++);
}

// ��ɸ�: main
// ����: test_static �Լ��� ���� �� ȣ���Ͽ� ���� ������ static ���� ������ ���� ����
// �Է�: ����
// ���: �� ȣ�� ������ ���� ������ static ���� ���� ��
// ����: ����
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		test_static();
	}

	return 0;
}
