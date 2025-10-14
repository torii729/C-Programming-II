/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : 16. ����ڷκ��� ���̵�� �н����带 �Է¹޾� �α��� ���� ó��.
        5���� ���̵�� �н����尡 �̹� ��ϵǾ� ���� �� �α��� ��� ����
        ���̵� �������� �ʰų� �ش��ϴ� �н����尡 ��ġ���� ������ ���� �޽��� ��� �� �ٽ� �Է¹ް� �Ѵ�.
        3���� ��õ� �Ŀ��� �Է����� ���ϸ� �α��� ���� ���� �޽����� ����Ѵ�.
        ���̵� ���ڿ� �迭�� �н����� ���ڿ��� ������� ���Ѵ�.
    ��¥ : 2025.09.28
*/

#include <stdio.h>
#include <string.h>

// �Լ� ����
int login(const char* id, const char* pw);
void process_login(void);

// ��ɸ�: main. �α��� ���α׷� ����
// ����: process_login �Լ��� ȣ���Ͽ� �α��� ������ �����Ѵ�.
// �Է�: ����
// ���: �α��� ���� �Ǵ� ���� �޽��� ���
// ����: ����
int main(void)
{
    process_login(); // �α��� ���� ����
    return 0;
}

// ��ɸ�: login. �α��� ����
// ����: �Է¹��� ���̵�� ��й�ȣ�� ��ϵ� �����Ϳ� ��ġ�ϴ��� Ȯ���Ѵ�.
// �Է�: const char* id (���̵�), const char* pw (��й�ȣ)
// ���: 1(����), -1(��й�ȣ ����), 0(���̵� ����)
// ����: ����
int login(const char* id, const char* pw)
{
    char ids[5][20] = { "seoyon", "torii", "gimin", "kook", "jimin" };
    char pws[5][20] = { "1234", "2345", "3456", "4567", "5678" };

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(id, ids[i]) == 0) // ���̵� ����
        {
            if (strcmp(pw, pws[i]) == 0) // ����� ����
            {
                return 1; // ����
            }
            else
            {
                return -1; // ��� Ʋ��
            }
        }
    }
    return 0; // ���̵� ����
}

// ��ɸ�: process_login. �α��� ���� ó��
// ����: ����ڷκ��� ���̵�� ��й�ȣ�� �Է¹޾� login �Լ��� �����ϰ� ����� ����Ѵ�.
// �Է�: ����
// ���: �α��� ���� �Ǵ� ���� �޽��� ���
// ����: ����
void process_login(void)
{
    char id[20] = { 0 };
    char pw[20] = { 0 };
    int result = 0;
    int tries = 0;

    while (tries < 3)
    {
        printf("ID : ");
        scanf_s("%s", id, 20);
        printf("PW : ");
        scanf_s("%s", pw, 20);

        result = login(id, pw);

        if (result == 1)
        {
            printf("�α��� ����!\n");
            return;
        }
        else if (result == -1)
        {
            printf("�н����尡 Ʋ�Ƚ��ϴ�.\n");
        }
        else
        {
            printf("�ش� id�� �����ϴ�.\n");
        }

        tries++;
    }
    printf("�α��� ����!\n");
}
