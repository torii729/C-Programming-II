/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ���� �ǽ� (ch11-02.c�� �����Ͽ� extern ���)
	��¥ : 2025.10.14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

// ��ɸ�: main
// ����: get_id �Լ��� ���� 3���� ȸ�� id�� ����ϰ� ������ id�� ���
// �Է�: ����
// ���: 3���� ȸ�� id�� ������ id
// ����: ����
int main(int argc, char* argv[])
{
	printf("�ʹ� ������\n");
	printf("ȸ��1�� id = %d\n", get_id());
	printf("ȸ��2�� id = %d\n", get_id());
	printf("ȸ��3�� id = %d\n", get_id());

	printf("������ id = %d\n", last_id);
	return 0;
}