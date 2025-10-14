/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ���� ������ �ǽ�
    ��¥ : 2025.09.17
*/

#include <stdio.h>

void menu();
void test_swap_double();
void* swapDouble(double* a, double* b);
int test_print_array();
void print_array_double(double arr[], int sz);
void printArrayDouble(double* arr, int sz);

// ��ɸ�: main. ���α׷� ������
// ����: �޴��� ȣ���Ͽ� ���ϴ� ����� �����Ѵ�.
// �Է�: ����
// ���: �� ��� ���� ����� �ֿܼ� ����Ѵ�.
// ����: ����
int main()
{
    menu();
    return 0;
}

// ��ɸ�: menu. ��� ���� �޴�
// ����: ����, �迭 ���, ���� �� ������ �ش� �Լ��� �����Ѵ�.
// �Է�: ����
// ���: ���õ� ��� ����� �ֿܼ� ����Ѵ�.
// ����: �߸��� ��ȣ �Է� �� ���Է� ��û
void menu()
{
    while (1)
    {
        int choice = 0;

        printf("1. ����\n2. �迭 ���\n3. ����\n� �Լ��� �����ϰڽ��ϱ�? : ");
        scanf_s("%d", &choice);

        if (choice == 1)
        {
            test_swap_double();
        }
        else if (choice == 2)
        {
            test_print_array();
        }
        else if (choice == 3)
        {
            printf("\n�����մϴ�.");
            break;
        }
        else
        {
            printf("\n�ٽ� �Է����ּ���.");
        }
    }
}

// ��ɸ�: test_swap_double. �Ǽ��� ���� ���� �׽�Ʈ
// ����: swapDouble �Լ��� �̿��� �� ������ ���� �ٲٰ� ����� ����Ѵ�.
// �Է�: ����
// ���: ���� ����� �ֿܼ� ����Ѵ�.
// ����: NULL ������ �Է� �� ���� ó�� �޽��� ���
void test_swap_double()
{
    double x = 3.3, y = 6.6;

    // 1. x, y�� ������ �ѱ�
    double* pre = (double*)swapDouble(&x, &y);
    if (pre == NULL)
    {
        printf("pre ���� : null\n");
    }
    else
    {
        printf("��� : a = %.1f, b = %.1f\n", x, y);
    }

    // 2. null�� ������?
    pre = swapDouble((double*)NULL, &y); // NULL�� �Ѱ�� ������ pre == NULL�� �ȴ�. �翬�� ����� ��µ��� �ʴ´�.
    if (pre == NULL)
    {
        printf("pre ������ ���� NULL�Դϴ�.\n\n");
    }
    else
    {
        printf("��� : a = %.1f, b = %.1f\n\n", x, y);
    }
}

// ��ɸ�: swapDouble. �� �Ǽ��� ������ �� ��ȯ
// ����: �� �Ǽ��� ������ ���� �����ͷ� �޾� ���� ��ȯ�Ѵ�.
// �Է�: double* a, double* b (�� ������ �ּ�)
// ���: ���� (������ a ��ȯ)
// ����: NULL �Է� �� NULL ��ȯ
void* swapDouble(double* a, double* b)
{
    if (a == NULL || b == NULL)
    {
        return NULL;
    }

    double temp = *a;
    *a = *b;
    *b = temp;

    return a;
}

// ��ɸ�: test_print_array. �迭 ��� �׽�Ʈ
// ����: �Ǽ� �迭�� �����ϰ� �� ���� ���(�迭, ������)���� ����Ѵ�.
// �Է�: ����
// ���: �迭�� ���Ҹ� �ֿܼ� ����Ѵ�.
// ����: ����
int test_print_array()
{
    double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]); // ��ü / ù��° ����

    print_array_double(arr, size); // �迭 �̸�
    printArrayDouble(&arr[0], size); // ������(����Ų��), �迭�� ù��° ������ �ּҸ� �Ű������μ� ������ �Ѵ�.

    return 0;
}

/*
    ��ɸ�: print_array_double. �迭�� ����� ���
    ����: 1���� �Ǽ� �迭�� ���޹޾� �� ���Ҹ� ������� ����Ѵ�.
    �Է�: double arr[] (�迭 �̸�), int sz (�迭 ũ��)
    ���: �迭�� ���� �ֿܼ� ����Ѵ�.
    ����: ����
*/
void print_array_double(double arr[], int sz)
{
    printf("�迭�� ��� : ");
    for (int i = 0; i < sz; i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

/*
    ��ɸ�: printArrayDouble. �����͸� ����� ���
    ����: �����͸� �̿��Ͽ� �迭�� ���Ҹ� ������� ����Ѵ�.
    �Է�: double* arr (�迭 ù ������ �ּ�), int sz (�迭 ũ��)
    ���: �迭�� ���� �ֿܼ� ����Ѵ�.
    ����: ����
*/
void printArrayDouble(double* arr, int sz)
{
    printf("�����͸� ��� : ");
    for (int i = 0; i < sz; i++, arr++)
    {
        printf("%.1f ", *arr);
    }
    printf("\n\n");
}
