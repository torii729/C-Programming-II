/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch09 PPT ���� 9-6 : ���ڿ��� �˻�
    ��¥ : 2025.09.29
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char filename[] = "readme.txt"; // ���� �̸� ���ڿ�
    char* p = NULL; // ���ڿ� Ž�� ����� ������ ������

    p = strrchr(filename, '.'); // filename���� ������ '.' ��ġ ã��
    if (p != NULL) // '.'�� ã�Ҵٸ�...
        printf("file extension: %s\n", p + 1); // '.' �������� ��� �� Ȯ���� ���

    p = strstr(filename, ".txt"); // filename���� ".txt" �κ� ���ڿ� ã��
    if (p != NULL) // ".txt" �߰� ��
        printf("file type: TEXT file\n"); // �ؽ�Ʈ �����̶�� ���

    return 0;
}
