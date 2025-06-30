#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void trim(char *str);
void trimLeading(char *str);
void trimTrailing(char *str);

int main(int argc, char **argv) {
	char toTrim[] = "  \t\nHello, World!  \t\n";
	char toLeadingTrim[] = "  \t\nHello, World!  \t\n";
	char toTrailingTrim[] = "  \t\nHello, World!  \t\n";
	trim(toTrim);
	trimLeading(toLeadingTrim);
	trimTrailing(toTrailingTrim);
	printf("Trimmed string: '%s'\n", toTrim);
	printf("Leading trimmed string: '%s'\n", toLeadingTrim);
	printf("Trailing trimmed string: '%s'\n", toTrailingTrim);

	printf("\n");
	return 0;
}

void trim(char *str) {
	char *start = str;
	char *end;

	while(isspace((unsigned char)*start)) start++;

	if(*start == '\0') {
		*str = '\0';
		return;
	}

	end = start + strlen(start) - 1;
	while(end > start && isspace((unsigned char)*end)) end--;
	*++end = '\0';
	
	while((*str++ = *start++) != '\0');
}

void trimLeading(char *str) {
	char *start = str;

	while(isspace((unsigned char)*start)) start++;

	if(*start == '\0') {
		*str = '\0';
		return;
	}

	while((*str++ = *start++) != '\0');
}

void trimTrailing(char *str) {
	char *end;

	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end)) end--;
	*++end = '\0';
}