/*
	�й� : 202511204
	�̸� : �����
	���α׷� �� : ���� ����ü �ǽ�
	��¥ : 2025.09.30
*/

/*
struct contact
{
	char name[20];
	char phone[20];
	int ringtone;
};

typedef struct contact Contact;
*/

#include <string.h>
#include "contact.h"

Contact kim = { 0 };

int main()
{
	Contact lee = { "�ȳ�", "01012341234", 1 };
	Contact lee2 = { 0 };

	lee2 = lee;

	// lee2 = { "�ȳ�2", "01023452345", 2 }; ���� �߻�
	strcpy(lee2.name, "�ȳ�2");
	strcpy(lee2.phone, "01023452345");
	lee2.ringtone = 2;

	return 0;
}

