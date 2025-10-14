/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ���� �ǽ� (ch11-01.c�� �����Ͽ� extern ���)
	��¥ : 2025.10.14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_id(void); // static �������� ���� ����
static int inc_id(int n);
int last_id = 1000;

// ��ɸ�: get_id
// ����: 1001������ ���ʷ� ������ ��ȣ�� �����ϸ鼭 ��ȯ�ϴ� ���
// �Է�: ����
// ���: ����
// ��ȯ��: 1001���� �����ؼ� 1�� �����ϴ� ������ ��
// ����: ����
int get_id(void) // �� �Լ��� static�̸� ch11-01.c���� ���� �Ұ�
{
	last_id = inc_id(last_id);

	return last_id;
}

// ��ɸ�: inc_id
// ����: �Էµ� ������ 1�� ���ؼ� ��ȯ
// �Է�: ����
// ���: ����
// ��ȯ��: n + 1
// ����: ����
int inc_id(int n)
{
	return n + 1;
}
