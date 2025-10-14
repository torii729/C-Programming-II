/*
    �й� : 202511204
    �̸� : �����
    ���α׷� �� : ch07 PPT ���� Ǯ��

    1. �տ��� ������ selectionSortInt �Լ��� �Ǽ��� ������ �� �ֵ���
    selecttionSortFloat�Լ��� �����Ͻÿ�.

    2. ǥ�� ���̺귯���� qsort �Լ��� �̿��Ͽ� �Ǽ� �迭�� ���� ������ �ϵ��� �Ͻÿ�.

    3. �տ��� ������ selectionSortInt �Լ��� qsort ó�� ������ �迭�� ���� ������ ��
    �ֵ��� �����Ͻÿ�.

    4. ǥ�� ���̺귯���� qsort �Լ��� �̿��Ͽ� ����ó ����ü Ÿ�Կ� ���� ���� �ϴ�
    �����ڵ带 �ۼ��Ͻÿ�.

    ��¥ : 2025.09.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int selecttionSortFloat(float R[], int n);
int qsortfloat(const void* a, const void* b);
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*));
int contactUp(const void* a, const void* b);

// ��ɸ�: main. �׽�Ʈ ����
// ����: �� �������� �ۼ��� �Լ����� ������ Ȯ���Ѵ�.
// �Է�: ����
// ���: ���� (�ʿ� �� �� �Լ� ������ ��� ���)
// ����: ����
int main(void)
{
    return 0;
}

// ��ɸ�: selecttionSortFloat. �Ǽ� �迭 ���� ����
// ����: �Ǽ� �迭 R�� ������������ ���� �����Ѵ�.
// �Է�: float R[] (�Ǽ� �迭), int n (�迭 ũ��)
// ���: ���� ���� �� 0 ��ȯ
// ����: �迭 ũ�Ⱑ �����̰ų� �߸��� ������ �Է� �� �߸��� ���� ����
int selecttionSortFloat(float R[], int n)
{
    int i = 0;
    int j = 0;
    int m = 0;

    for (i = 0; i < n - 1; i++)
    {
        m = i;

        for (j = i + 1; j < n; j++)
        {
            if (R[j] < R[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            float t = R[i];
            R[i] = R[m];
            R[m] = t;
        }
    }
    return 0;
}

// ��ɸ�: qsortfloat. qsort�� �Ǽ� �� �Լ�
// ����: qsort���� ���Ǵ� �� �Լ���, �� �Ǽ��� ũ�⸦ ���Ѵ�.
// �Է�: const void* a, const void* b (���� �� �Ǽ��� �ּ�)
// ���: ����(���� ���� ��), 0(���� ��), ���(���� Ŭ ��)
// ����: �Է� �����Ͱ� NULL�̸� �߸��� ���� ����
int qsortfloat(const void* a, const void* b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// ��ɸ�: selectionSortInt. ���� �迭 ���� ����
// ����: qsortó�� �۵��ϴ� �Ϲ�ȭ�� ���� ���� �Լ�. 
//       cmp �� �Լ��� ������ �� ��Ģ�� ����� �����ϰ�, ������ int �������� �����Ѵ�.
// �Է�: void* base (�迭 ���� �ּ�), int n (��� ����), int sz (��� ũ��),
//       int (*cmp)(void*, void*) (�� �Լ� ������)
// ���: ���� ���� �� 0 ��ȯ
// ����: �迭 ũ�� �Ǵ� ũ�� ���� ���� �� ������ ���� ����
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*))
{
    char* a = (char*)base;

    for (int i = 0; i < n - 1; i++)
    {
        int m = i;

        for (int j = i + 1; j < n; j++)
        {
            void* pj = a + j * sz; // j��° ���� �ּ�
            void* pm = a + m * sz; // ���� �ּҰ� �ּ�

            int c = 0;

            if (cmp)
            {
                c = cmp(pj, pm);
            }
            else
            {
                int x = *(int*)pj;
                int y = *(int*)pm;

                if (x < y) c = -1;
                else if (x > y) c = 1;
                else c = 0;
            }

            if (c < 0) m = j;
        }

        if (m != i)
        {
            for (int k = 0; k < sz; k++)
            {
                char* p = a + i * sz + k;
                char* q = a + m * sz + k;
                char t = *p; *p = *q; *q = t;
            }
        }
    }
    return 0;
}

// ��ɸ�: contactUp. qsort�� ����ü �� �Լ�
// ����: Contact ����ü �迭�� �̸�(name) �������� �������� �����ϱ� ���� �� �Լ�.
// �Է�: const void* a, const void* b (���� �� ����ü �ּ�)
// ���: strcmp ����� (����/0/���) - ���ڿ� ������ ����
// ����: �Է� �����Ͱ� NULL�̸� �߸��� ���� ����
int contactUp(const void* a, const void* b)
{
    const Contact* x = (const Contact*)a;
    const Contact* y = (const Contact*)b;

    return strcmp(x->name, y->name);
}
