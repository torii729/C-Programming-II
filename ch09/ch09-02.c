/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch09 PPT ���� ���� : ���ڿ��� �� �� ���鹮�� ���� (trim)
    ��¥ : 2025.09.29
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// isspace() : �Ű������� ���� ���� �������� Ȯ���ϰ�, �����̸� 0�� �ƴ� ���� ��ȯ, �׷��� ������ 0�� ��ȯ
// \0, \n, \t, \v, \f, \r�� �����̶� �Ǵ���

// ���ڿ� ���� ���� ���� (Left Trim)
char* ltrim(char* str) 
{
    if (str == NULL) return NULL;

    // ���� ���� ���ڸ� �ǳʶڴ�
    while (*str && isspace(*str))
    {
        str++;
    }
    return str;
}

// ���ڿ� ���� ���� ���� (Right Trim)
char* rtrim(char* str) 
{
    if (str == NULL) return NULL;

    int len = strlen(str);
    if (len == 0) return str;

    // �ڿ������� ���� ���ڸ� NULL�� ����
    char* end = str + len - 1;
    while (end >= str && isspace(*end)) 
    {
        *end = '\0';// ���� ��� ���ڿ� �� ǥ��
        end--;
    }
    return str;
}

// ���ڿ� �յ� ���� ���� (Trim)
char* trim(char* str) 
{
    if (str == NULL) return NULL;

    // ���� ������ trim�� �ϰ�, �� ���� ���� trim�� �Ѵ�
    rtrim(str);
    return ltrim(str);
}

int main() 
{
    char temp1[] = "   hello world   ";
    char temp2[] = "\t\n  C Programming  \r\n ";

    // �յ� ������ ���ŵǴ��� Ȯ�� ���
    printf("1: '%s'\n", ltrim(temp1)); // �� ���� ����
    printf("2: '%s'\n", rtrim(temp1)); // �� ���� ����
    printf("3: '%s'\n", trim(temp2)); // �յ� ���� ����
}
