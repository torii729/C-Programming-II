/*
	학번 : 202511204
	이름 : 강기민
	프로그램 명 : 강의 구조체 실습
	날짜 : 2025.09.30
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
	Contact lee = { "안녕", "01012341234", 1 };
	Contact lee2 = { 0 };

	lee2 = lee;

	// lee2 = { "안녕2", "01023452345", 2 }; 에러 발생
	strcpy(lee2.name, "안녕2");
	strcpy(lee2.phone, "01023452345");
	lee2.ringtone = 2;

	return 0;
}

