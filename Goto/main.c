#include <stdio.h>
#include <string.h>

/*
 * DIKKE FUCKING SPAGHETTI CODE BOIIII !!!!
 * No seriously only use goto's to exit inner nested loops
 */

int main(void)
{
	unsigned char tree_width = 0;
    
    // Retrieve tree width
    char buffer[100]; // Assuming a reasonable buffer size
    do {
        printf("Enter a uneven number for tree width (3-255) [9]: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%hhu", &tree_width) != 1) {
                if (strlen(buffer) <= 1 && *buffer == '\n') {
                    tree_width = 9;
                    break;
                }
            }
        }
    } while (tree_width < 3 || tree_width % 2 == 0);
    
    printf("\n");
    
    //Draw tree
    unsigned char lineCount = tree_width / 2 + 1;
    unsigned char line = 1;
    unsigned char charIdx = 1;
    unsigned char offset = lineCount - 1;
    
    printLine:
    if (charIdx != tree_width) {
        goto printCharacter;
    }
    printf("\n");
    if (line < lineCount) {
        line++;
        charIdx = 1;
        offset--;
        goto printLine;
    }
    
    return 0;
    
    printCharacter:
    if (offset) {
        (charIdx == 1 + offset || charIdx == tree_width - offset) ? printf("*") : printf(" ");
    } else {
        printf("*");
    }
    if (charIdx < tree_width) {
        charIdx++;
        goto printCharacter;
    } else {
        goto printLine;
    }
}