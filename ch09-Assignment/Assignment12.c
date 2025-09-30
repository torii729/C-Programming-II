/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : 12. ���ù��� ���ڿ��� ���Ͽ� �̵��� ���� ���� �Է¹޾� ���� �Ǵ� ���������� ȸ���� ����� ���
        ���� -> abcdef�� ���������� 2���� ȸ���ϸ� efabcd (���� ���� ������ ����, ����� ������, �̵��� ���ڼ� 0 �Է� �� ����)
    ��¥ : 2025.09.28
*/

#include <stdio.h>
#include <string.h>

// �Լ� ����
void reverse(char* str, int start, int end);
void rotate(char* str, int k);
void input_string(char* str);
void process_rotation(char* str);

// ���� �Լ�
int main(void)
{
    char str[100];

    input_string(str); // ���ڿ� �Է� ����
    process_rotation(str);  // ȸ�� ó�� ����

    return 0;
}

// ���ڿ� �Է� �ޱ�
void input_string(char* str)
{
    printf("���ڿ�? ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // ���� ����
}

// ȸ�� ���� �� ���
void process_rotation(char* str)
{
    int k = 0;
    while (1)
    {
        printf("�̵��� ���ڼ�? ");
        scanf_s("%d", &k);

        if (k == 0)
        {
            break;
        }

        rotate(str, k);
        printf("%s\n", str);
    }
}

// ���ڿ� ȸ��
void rotate(char* str, int k)
{
    int len = strlen(str);
    if (len == 0)
    {
        return;
    }

    /*
        k�� len���� ���� �������� ���ؾ� �Ѵ�
        len = 5��� �������� ��
        5�� ������ �����¿� �Ȱ���
        6�� ������ 1�� ���� �Ͱ� ����
        �� k�� len���� ���� ��������ŭ�� �ϸ� �ȴ�
        �׸��� �迭 ������ ����� ���� �����ϱ� ���Ե� �ִ�

        ������ ����� �ٲ��
        k = -2��� �������� ��
        ���������� 3ĭ ������ �Ͱ� �������� 2ĭ ������ ���� ����� ����
        ������ ȸ���� ó���ϰ� �Ϸ��� ������ ����� �ٲٴ� ��
    */
    k = k % len; // �ϴ� �������� ����

    if (k < 0)
    {
        k = k + len;  // ������ ����� �ٲ���
    }

    // ���ڿ��� ó������ ������ ���� ��������� �ǹ̷� �Ű������� ������
    // len �״�� ������ �ι��ڱ��� �ǵ帮�Ƿ� -1�� �Ѵ�
    reverse(str, 0, len - 1); 
    reverse(str, 0, k - 1);
    reverse(str, k, len - 1);
}


// ���ڿ� ������
void reverse(char* str, int start, int end)
{
    while (start < end)
    {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        start++;
        end--;
    }
}
