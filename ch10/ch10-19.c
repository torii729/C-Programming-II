/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : Ű����κ��� ���� ���ڵ带 �� �� �Է¹޾� �ʵ带 �����Ͽ�
		����ü �迭�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	��¥ : 2025.10.01
*/

/*
	����
	�Է� : �̸� | �й� | �а� | �г�(����)
	�Է� ���� ���� : "exit" �Է�
	�Է°� �Է¹��� �� �Ľ��Ͽ� ����, ���. �̷��� �Լ� 3�� �̻���
*/

// �Լ��� �Է� 1 ���� 1 ��� 1 �� 3��
// strtok�� ��Ƽ�� �� �ڸ��� �迭 �̿�
// ���� ���� ������ ��� ���� �ϳ� ����(�̸� ������ ��Ȱ�� ���)
// strcpy�� �����Ͽ� ct->name[0] = '��', ct->name[1] = '��', ct->name[2] = '��' �̷��� �Ϸ�����
// �̷��ԵǸ� ������ �г� ������ atoi�� ������ ��ȯ�ؼ� �����ϸ� ��

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf, gets
#include <string.h> // str~
#include <stdlib.h> // atoi

#define SIZE 100

typedef struct Student {
	char name[20];
	char id[20];
	char major[20];
	int year;
} Student;

int input_student(Student arr[]);
void print_student(Student arr[], int count);
void save_student(char* line, Student* arr);

// ��ɸ�: main. �л� ���� �Է� �� ��� ���α׷�
// ����: �л� ������ �Է¹޾� ����ü �迭�� �����ϰ�, ��ü ����� ����Ѵ�.
// �Է�: �̸�|�й�|�а�|�г� ������ ���ڿ� �Է�
// ���: ��� �л��� ���� ���
// ����: ����

int main(void)
{
	Student arr[SIZE];
	int cnt = 0;

	cnt = input_student(arr);
	print_student(arr, cnt);
	return 0;
}

// ��ɸ�: input_student. �л� ���� �Է� �Լ�
// ����: ����ڷκ��� �л� ������ �Է¹޾� save_student �Լ��� ���� ����ü�� �����Ѵ�.
// �Է�: Student arr[] (����ü �迭)
// ���: �Է¹��� �л� �� ��ȯ
// ����: ����

int input_student(Student arr[])
{
	int count = 0;
	char input_line[SIZE] = { 0 };
	printf("�̸�|�й�|�а�|�г�\n���� : ���|202500000|��ǻ�Ͱ��а�|1\n");

	while (1)
	{
		printf("�Է�(exit : ����) : ");
		gets(input_line);

		if (strcmp(input_line, "exit") == 0)
		{
			printf("�Է��� �����մϴ�.\n");
			break;
		}
		save_student(input_line, &arr[count]); // &arr[count]�� count��° �л� ����ü 1��
		count++;
	}
	return count;
}

// ��ɸ�: save_student. �л� ���� ���� �Լ�
// ����: �Է¹��� ���ڿ��� '|' �������� ������ ����ü ����� �����Ѵ�.
// �Է�: char* line (�Է� ���ڿ�), Student* arr (������ ����ü �ּ�)
// ���: ����
// ����: ����

void save_student(char* line, Student* arr)
{
	strcpy(arr->name, strtok(line, "|"));
	strcpy(arr->id, strtok(NULL, "|"));
	strcpy(arr->major, strtok(NULL, "|"));
	arr->year = atoi(strtok(NULL, "|"));
}

// ��ɸ�: print_student. �л� ���� ��� �Լ�
// ����: ����� ��� �л��� ������ ������� ����Ѵ�.
// �Է�: Student arr[] (����ü �迭), int count (�л� ��)
// ���: �л� ��� �ܼ� ���
// ����: ����

void print_student(Student arr[], int count)
{
	printf("\n ~ �л� ��� ~ \n");
	int num = 1;
	for (int i = 0; i < count; i++)
	{
		printf("%d��° �л� | �̸� : %s, �й� : %s, �а� : %s, �г� : %d\n",
			num, arr[i].name, arr[i].id, arr[i].major, arr[i].year);
		num++;
	}
}
