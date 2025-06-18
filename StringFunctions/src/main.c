#include <stdio.h>
#include <string.h>

void testReverseString(void);
void reverseString(char * string);

void testBubbleSort(void);
void bubbleSort(char string[][20], int nbrOfStr);

int main(int argc, char **argv) {
	testReverseString();
	testBubbleSort();

	printf("\n");
	return 0;
}

void testReverseString(void) {
	char string[20];

	printf("Enter a string: ");
	scanf("%s", string);

	reverseString(string);
	
	printf("The reversed string is \"%s\".\n", string);
}

void reverseString(char * string) {
	for(int startIdx = 0, endIdx = strlen(string) - 1; endIdx > startIdx; startIdx++, endIdx--) {
		// Swap values at startIdx and endIdx
		string[startIdx] ^= string[endIdx];
		string[endIdx] ^= string[startIdx];		
		string[startIdx] ^= string[endIdx];
	}
}

void testBubbleSort(void) {
	int nbrOfStr = 0;
	printf("\nEnter the number of Strings: ");
	scanf("%d", &nbrOfStr);

	char string[nbrOfStr][20];
	for(int i = 0; i < nbrOfStr; i++) {
		printf("%2d> ", i + 1);
		scanf("%s", string[i]);
	}
	
	bubbleSort(string, nbrOfStr);
	
	printf("\nThis is the sorted string array:\n");
	for(int i = 0; i < nbrOfStr; i++) {
		printf("%s\n", string[i]);
	}
}

void bubbleSort(char (*string)[20], int nbrOfStr) {
	for(int endIdx = nbrOfStr - 1; endIdx > 0; endIdx--) {
		for(int i = 0; i < endIdx; i++) {
			if(strcmp(string[i], string[i + 1]) > 0) {
				// Swap string at index i with string at index i + 1
				char tempStr[20];
				strncpy(tempStr, string[i + 1], sizeof(tempStr) - 1);
				strncpy(string[i + 1], string[i], sizeof(string[i + 1]) - 1);
				strncpy(string[i], tempStr, sizeof(string[i]) - 1);
			}
		}
	}
}