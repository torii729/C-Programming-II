/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch09 PPT ���� 9-5 : ���ڿ� ���� (strcat)
	��¥ : 2025.09.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char sentence[100] = ""; // �ϼ��� ������ ������ �迭 (ó���� �� ���ڿ�)
    char word[20]; // �Է¹��� �ܾ ������ �迭

    do {
        printf("�ܾ�? "); // �ܾ� �Է� ��û
        scanf("%s", word); // �ܾ� �Է¹���

        strcat(sentence, word); // sentence ���� �Էµ� �ܾ� �߰�
        strcat(sentence, " "); // �ܾ� �ڿ� ���� �߰� (�ܾ� ���п�)

    } while (strcmp(word, ".") != 0); // �Էµ� �ܾ "."�� �ƴ� �� �ݺ�

    printf("%s\n", sentence); // �ϼ��� ������ ���

    return 0;
}

