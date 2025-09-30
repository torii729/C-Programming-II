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
	Contact lee = { "¾È³ç", "01012341234", 1 };
	Contact lee2 = { 0 };

	lee2 = lee;

	// lee2 = { "¾È³ç2", "01023452345", 2 }; ¿¡·¯ ¹ß»ý
	strcpy(lee2.name, "¾È³ç2");
	strcpy(lee2.phone, "01023452345");
	lee2.ringtone = 2;

	return 0;
}

