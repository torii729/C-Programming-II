/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ch10 PPT ���� 10-16 : ����ü�� �̿��� RGB ���� ǥ��
	��¥ : 2025.10.01
*/

/*
    ���� ����:
    ����ü(union)�� ���� �޸� ������ �����Ѵ�.
    unsigned int color�� unsigned char rgb[4]�� ���� �޸𸮸� ����Ų��.
    ���� rgb �迭�� ���� �����ϸ� color ���� �ٲ��.

    �޸� ����:
    rgb[0] = red, rgb[1] = green, rgb[2] = blue, rgb[3] = not used.
    ������ ����Ʈ�� ä�� ������ 4����Ʈ ���� color ���� �ڵ����� �����ȴ�.
*/

#include <stdio.h>

typedef union color_t {
    unsigned int color; // 4����Ʈ ����(��ȣ����)
    unsigned char rgb[4]; // 1����Ʈ�� ���� �����Ϸ��� �迭 ����
} COLOR_T;

int main(void)
{
    COLOR_T c1;

    c1.rgb[0] = 0xFF; // red
    c1.rgb[1] = 0xAB; // green
    c1.rgb[2] = 0x1F; // blue
    c1.rgb[3] = 0x00; // not used

    printf("rgb color = %08X\n", c1.color); // 32��Ʈ ������ ���

    return 0;
}
