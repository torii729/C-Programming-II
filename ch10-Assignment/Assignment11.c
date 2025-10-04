/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 11. PRODUCT ����ü �迭�� �̿��ؼ� ��ǰ���� �Է¹޾� �˻� �� �ֹ� ó���ϴ� ���α׷�
        �ֹ� ������ �Է¹޾� ���� �ݾ��� �˷��ְ�, ��ǰ ��� �ֹ� ������ŭ ���ҽ�Ų��.
        ��ǰ������ �˻��� �� ���ų� ã�� ��ǰ�� ��� �ֹ� �������� ������ ���� �޽��� ���.
        PRODUCT ����ü �迭�� ũ�Ⱑ 5�� �迭�� ����, ������ ������ �ʱ�ȭ.
	��¥ : 2025.10.01
*/

/*
    �޸� ���� :
    run_order �Լ����� list �迭�� ����ǰ�, find �Լ��� �ش� �迭���� ��ǰ���� �˻��Ѵ�.
    order �Լ��� ���õ� ����ü ����� ���� �����Ͽ� ��� �����Ѵ�.
    print_all �Լ��� ����ü �迭�� ��ü ��ǰ ������ ����Ѵ�.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 20 // ���ڿ� ũ��
#define N 3 // ��ǰ ����

typedef struct {
    char name[SIZE]; // ��ǰ��
    int price; // ����
    int stock; // ���
} PRODUCT;

void run_order();
int find(PRODUCT list[], int n, char* key);
void order(PRODUCT* p, int q);
void print_all(PRODUCT list[], int n);

// ��ɸ�: main. ���α׷� ���� ����
// ����: run_order �Լ��� ȣ���Ͽ� �ֹ� ���α׷��� �����Ѵ�.
// �Է�: ����
// ���: ����
// ����: ����

int main()
{
    run_order();
    return 0; // ���� ����
}

// ��ɸ�: find. ��ǰ �˻�
// ����: ����ü �迭���� key�� ���� ��ǰ���� ���� �ε����� ã�´�.
// �Է�: PRODUCT list[], int n, char* key
// ���: ã�� �ε���(����). ������ -1 ��ȯ
// ����: key�� NULL�̸� �� �Ұ�

int find(PRODUCT list[], int n, char* key)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(list[i].name, key))
        {
            return i;
        }
    }
    return -1;
}

// ��ɸ�: order. �ֹ� ó��
// ����: Ư�� ��ǰ�� ���� �ֹ� ������ŭ ���� �ݾ��� ����ϰ� ��� �����Ѵ�.
// �Է�: PRODUCT* p (�ֹ��� ��ǰ), int q (�ֹ� ����)
// ���: ���� (���� �ݾװ� ����� ��� ���)
// ����: ��� ���� �� �ֹ� �Ұ�

void order(PRODUCT* p, int q)
{
    if (p->stock < q)
    {
        printf("��� ����\n");
        return;
    }
    printf("���� �ݾ�: %d %s ���: %d\n", p->price * q, p->name, p->stock - q);

    p->stock = p->stock - q;
}

// ��ɸ�: print_all. ��ü ��ǰ ���
// ����: ����ü �迭�� ����� ��� ��ǰ�� �̸�, ����, ��� ����Ѵ�.
// �Է�: PRODUCT list[], int n
// ���: ���� (��ǰ ������ �ֿܼ� ���)
// ����: ����

void print_all(PRODUCT list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%s %d�� ���:%d]\n", list[i].name, list[i].price, list[i].stock);
    }
}

// ��ɸ�: run_order. �ֹ� ����
// ����: ��ǰ ����� �غ��ϰ�, ����ڷκ��� ��ǰ��� ������ �Է¹޾� �ֹ��� ó���Ѵ�.
// �Է�: ǥ�� �Է�(��ǰ��, �ֹ� ����). ���� ������ "." �Է�
// ���: �ֹ� ó�� ��� �� ��� ��ǰ ���� ���
// ����: �߸��� �Է� �� ������ ������� ����

void run_order()
{
    PRODUCT list[N] = {
        {"�Ƹ޸�ī��", 4000, 5},
        {"ī���", 4500, 7},
        {"�÷�ȭ��Ʈ", 5000, 10}
    };

    char key[SIZE];
    int q = 0;

    while (1)
    {
        printf("�ֹ��� ��ǰ��? (���� �� . �Է�) ");
        scanf_s("%s", key, sizeof(key));

        if (!strcmp(key, "."))
        {
            break;
        }

        printf("�ֹ��� ����? ");
        scanf_s("%d", &q);

        int idx = find(list, N, key);

        if (idx == -1)
        {
            printf("��ǰ ����\n");
        }
        else
        {
            order(&list[idx], q);
        }
    }
    print_all(list, N);
}

