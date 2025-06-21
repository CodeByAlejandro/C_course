#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

struct item {
	char * itemName;
	int quantity;
	float price;
	float amount;
};

void readItem(struct item * pItem);
char * readString(const char * promptString);
void printItem(struct item * pItem);

int main(int argc, char **argv) {
	if(setjmp(buf)) {
		return 1;
	}

	struct item sItem;

	readItem(&sItem);
	printf("\n");

	printItem(&sItem);
	printf("\n");

	free(sItem.itemName);
	return 0;
}

void readItem(struct item * pItem) {
	printf("Enter item information:\n");
	pItem->itemName = readString("\tname: ");
	printf("\tquantity: ");
	scanf("%d", &pItem->quantity);
	printf("\tprice: ");
	scanf("%f", &pItem->price);
	pItem->amount = pItem->quantity * pItem->price;
}

char * readString(const char * promptString) {
	printf("%s", promptString);

	char * pString = (char *) malloc(sizeof(char));
	if (!pString) {
		fprintf(stderr, "Could not allocate memory for iten name string!\n");
		longjmp(buf, 1);
	}

	int idx = 0;
	while((pString[idx] = getchar()) != '\n' && pString[idx] != EOF) {
		char * const pNewString = realloc(pString, (idx + 2) * sizeof(char));
		if (!pNewString) {
			fprintf(stderr, "Could not reallocate memory for iten name string!\n");
			free(pString);
			longjmp(buf, 1);
		} else {
			pString = pNewString;
		}
		idx++;
	}
	pString[idx] = '\0';
	
	return pString;
}

void printItem(struct item * pItem) {
	printf("Item information:\n");
	printf("\tname: %s\n", pItem->itemName);
	printf("\tquantity: %d\n", pItem->quantity);
	printf("\tprice: %.2f\n", pItem->price);
	printf("\tamount: %.2f\n", pItem->amount);
}