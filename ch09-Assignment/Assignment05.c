/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : 5. ��ҹ��ڸ� �������� �ʰ� ���ڿ��� ���ϴ� strcmp_ic �Լ��� �ۼ��Ͻÿ�.
        ���ϰ��� lhs�� rhs���� ũ�� 0���� ū ��, �� ���ڿ��� ������ 0, lhs�� rhs���� ������ 0���� ���� ���� �����Ѵ�.
    ��¥ : 2025.09.28
*/

#include <stdio.h>
#include <ctype.h> // ��ҹ��� ��ȯ�� �ʿ�

int strcmp_ic(const char* lhs, const char* rhs);
void input_string(char* str1, char* str2);
void compare_and_print(const char* str1, const char* str2);

/*
    ��ɸ�: main. ���α׷� ������
    ����: �� ���ڿ��� �Է¹޾� ��ҹ��ڸ� �������� �ʰ� ���� �� ����� ����Ѵ�.
    �Է�: ����
    ���: �� ���ڿ��� ���ų� �ٸ��� ���θ� �ֿܼ� ����Ѵ�.
    ����: ����
*/
int main(void)
{
    char str1[100] = { 0 };
    char str2[100] = { 0 };

    input_string(str1, str2);
    compare_and_print(str1, str2);

    return 0;
}

/*
    ��ɸ�: strcmp_ic. ��ҹ��� ���� ���� ���ڿ� �� �Լ�
    ����: �� ���ڿ��� �ҹ��ڷ� ��ȯ�Ͽ� �� ���ھ� ���Ѵ�.
    �Է�: const char* lhs (���� ���ڿ� 1), const char* rhs (���� ���ڿ� 2)
    ���: ������ 0, lhs > rhs�� ���, lhs < rhs�� ����
    ����: ����
*/
int strcmp_ic(const char* lhs, const char* rhs)
{
    while ((*lhs != '\0') && (*rhs != '\0'))
    {
        char a = tolower(*lhs); // �ҹ��ڷ� �����ؼ� ��
        char b = tolower(*rhs);

        if (a != b)
            return a - b; // �ٸ��� ���̰� ��ȯ

        lhs++;
        rhs++;
    }
    return tolower(*lhs) - tolower(*rhs); // ���ڿ� ���̰� �ٸ� ��� ���� ��ȯ
}

/*
    ��ɸ�: input_string. ���ڿ� �Է� �Լ�
    ����: ����ڿ��� �� ���� ���ڿ��� �Է¹޾� ���� �����Ѵ�.
    �Է�: char* str1, char* str2 (�Է¹��� ���ڿ� ����� �迭)
    ���: ���� (�Է� ����� str1, str2�� �����)
    ����: ����
*/
void input_string(char* str1, char* str2)
{
    printf("ù ��° ���ڿ� ? ");
    gets(str1);

    printf("�� ��° ���ڿ� ? ");
    gets(str2);
}

/*
    ��ɸ�: compare_and_print. �� �� ��� ��� �Լ�
    ����: strcmp_ic�� �̿��� �� ���ڿ��� ���ϰ� ����� ����Ѵ�.
    �Է�: const char* str1, const char* str2
    ���: �� ����� �ֿܼ� ����Ѵ�.
    ����: ����
*/
void compare_and_print(const char* str1, const char* str2)
{
    if (strcmp_ic(str1, str2) == 0)
        printf("%s�� %s�� �����ϴ�.\n", str1, str2);
    else
        printf("%s�� %s�� �ٸ��ϴ�.\n", str1, str2);
}
