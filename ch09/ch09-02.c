/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch09 PPT ���� ���� : ���ڿ��� �� �� ���鹮�� ���� (trim)
    ��¥ : 2025.09.29
*/

/*
    ���� ���� :
    isspace �Լ��� ���ڰ� ����, ����, ��, ���� �� ���� �Ǻ��Ѵ�.
    ���ڿ��� ���� ���ſ��� ������ ����� �ݺ����� Ȱ���� �� �ִ�.
    ���� ���� ���Ŵ� ���� �����͸� �ű�� �ǰ�, ������ ���� ���Ŵ� ���ڿ� ���� '\0'���� �ٲٸ� �ȴ�.

    �޸� ���� :
    ���ڿ��� �迭�� ���ÿ� ����ȴ�.
    ltrim�� �����͸� �Űܼ� ���� ��ġ�� �ٲ����� ���� �迭�� ������ �������� �ʴ´�.
    rtrim�� ���ڿ� �� �κ��� '\0'���� ����Ἥ ���� �迭 ������ �����Ѵ�.
    trim�� rtrim�� ltrim�� ���ʷ� ȣ���Ͽ� ���� ������ �����Ѵ�.

    �� ����� ���� ���� :
    �Էµ� ���ڿ��� ��ó���� �� ���ʿ��� �յ� ������ �����ϴ� ���� �ſ� ���� �۾��̴�.
    ���� ���Ÿ� �Լ��� ����� �θ� �ڵ� ���뼺�� �������� ��������.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* ltrim(char* str)
{
    if (str == NULL) return NULL;

    while (*str && isspace(*str)) // ���� ���� ���� �ǳʶ�
        str++;

    return str;
}

char* rtrim(char* str)
{
    if (str == NULL) return NULL;

    int len = strlen(str); // ���ڿ� ���� ���
    if (len == 0) return str;

    char* end = str + len - 1; // ���ڿ� ������ ���� ��ġ
    while (end >= str && isspace(*end))
    {
        *end = '\0'; // ���� ���ڸ� ���ڿ� ������ �ٲ�
        end--;
    }
    return str;
}

char* trim(char* str)
{
    if (str == NULL) return NULL;

    rtrim(str); // ���� ������ ���� ����
    return ltrim(str); // �̾ ���� ���� ����
}

int main()
{
    char temp1[] = "   hello world   ";
    char temp2[] = "\t\n  C Programming  \r\n ";

    printf("1: '%s'\n", ltrim(temp1)); // �� ���� ����
    printf("2: '%s'\n", rtrim(temp1)); // �� ���� ����
    printf("3: '%s'\n", trim(temp2)); // �յ� ���� ����

    return 0;
}
