/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : 17. �뷡 ���� ���� ���α׷��� �˻� ����� �߰��Ѵ�. ��� �Ǵ� �������� �Է¹޾Ƽ�
        �ش� �뷡 ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��϶�. ��ġ�ϴ� �뷡�� ���� ���̸� ��� ���.
	��¥ : 2025.10.01
*/

/*
    �޸� ����:
    SONG ����ü �迭 list�� �� �뷡�� ����, ����, �帣, ��� �ð��� �����Ѵ�.
    key ���ڿ��� �Է¹޾� �� �뷡�� title�� artist�� ���� �κ� �˻��� �����Ѵ�.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 30 // ���ڿ� ũ��

typedef struct {
    char title[SIZE];  // �뷡 ����
    char artist[SIZE]; // ���� �̸�
    char genre[SIZE];  // �帣
    int time; // ��� �ð�(��)
} SONG;

void run_song();

// ��ɸ�: main. ���α׷� ���� ����
// ����: run_song �Լ��� ȣ���Ͽ� �뷡 �˻� ����� �����Ѵ�.
// �Է�: ����
// ���: ����
// ����: ����
int main()
{
    run_song();
    return 0; // ���� ����
}

// ��ɸ�: run_song. �뷡 �˻� ���
// ����: �뷡 ����� �غ��ϰ�, ����ڰ� �Է��� Ű���带 ����� �������� �˻��Ͽ� ����� ����Ѵ�.
// �Է�: ǥ�� �Է�(�˻� Ű����). ���� ������ "." �Է�
// ���: �˻��� �뷡 ����(title, artist, genre, time)
// ����: ����
void run_song()
{
    SONG list[4] = {
        {"I'm Fine", "��ź�ҳ��", "hip-hop", 209},
        {"����", "��ź�ҳ��", "hip-hop", 274},
        {"Awake", "��ź�ҳ��", "ballad", 226},
        {"�� ���� ����", "�ں���", "ballad", 316}
    };

    char key[SIZE];

    while (1)
    {
        printf("�˻�(. �Է� �� ����) : ");
        scanf_s("%s", key, sizeof(key));

        if (!strcmp(key, "."))
        {
            break; // ���� ����
        }

        for (int i = 0; i < 4; i++)
        {
            if (strstr(list[i].title, key) || strstr(list[i].artist, key))
            {
                printf("%s %s %s %d��\n", list[i].title, list[i].artist, list[i].genre, list[i].time);
            }
        }
    }
}
