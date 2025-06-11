#include <stdio.h>

int main() {
	enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT = 100 };
	enum Company xerox = XEROX, google = GOOGLE, ebay = EBAY, microsoft = MICROSOFT; 
	printf("XEROX: %d\nGOOGLE: %d\nEBAY: %d\nMICROSOFT: %d\n\n", xerox, google, ebay, microsoft);
	return 0;
}