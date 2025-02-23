#include <stdio.h>
#include <stdlib.h>

#define SLEN 30

struct item {
    char *itemName;
    float price;
    int quantity;
    float amount;
};

void readItem(struct item *pItem);
void printItem(const struct item *pItem);
void removeEndingNewlineFromStr(char *pStr);

int main(int argc, char **argv)
{
	struct item aItem, *pItem = &aItem;
    pItem->itemName = (char *) malloc(SLEN * sizeof(char));
    if (!pItem->itemName)
        return 1;
    readItem(pItem);
    printItem(pItem);
    free(pItem->itemName);
    pItem->itemName = NULL;
	return 0;
}

void readItem(struct item *pItem) {
    printf("Please provide item information:\n");
    
    printf("\tProduct name: ");
    fgets(pItem->itemName, SLEN, stdin);
    removeEndingNewlineFromStr(pItem->itemName);
    
    printf("\tProduct price: ");
    scanf("%f", &pItem->price);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    printf("\tProduct quantity: ");
    scanf("%d", &pItem->quantity);
    for (char c; (c = getchar()) != '\n' && c != EOF;);
    
    pItem->amount = pItem->quantity * pItem->price;
    printf("\n");
}

void printItem(const struct item *pItem) {
    printf(
        "Item information:\n\tProduct name: %s\n\tProduct price: %.2f\n\tProduct quantity: %d\n\tProduct amount: %.2f\n",
        pItem->itemName, pItem->price, pItem->quantity, pItem->amount
    );
}

void removeEndingNewlineFromStr(char *pStr) {
    while (*pStr)
        pStr++;
    pStr--;
    if (*pStr == '\n')
        *pStr = '\0';
}