#include <stdio.h>

int main() {
	enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT = 100, NETFLIX };
	enum Company xerox = XEROX,
				 google = GOOGLE,
				 ebay = EBAY,
				 microsoft = MICROSOFT,
				 netflix = NETFLIX;
	printf("XEROX: %d\nGOOGLE: %d\nEBAY: %d\nMICROSOFT: %d\nNETFLIX: %d\n\n",
			xerox, google, ebay, microsoft, netflix);
	return 0;
}