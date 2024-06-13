#include <stdio.h>
#include <ctype.h>

#define PATH "D:\\Documents\\CodeLite\\Workspaces\\C-course\\fileToUpperCase"

int main(int argc, char **argv)
{
	FILE *pFile = fopen(PATH"\\file.txt", "w+");
    if (!pFile) {
        printf("Could not open file.txt for writing/reading!\n");
        return 1;
    }
        
    fputs("This is line 1\n", pFile);
    fputs("This is a second line.\n", pFile);
    fputs("This is 3\n", pFile);
    fputs("Guess what, number four\n", pFile);
    fputs("And the last line is five.", pFile);
    
    rewind(pFile);
    
    FILE *pTemp = fopen(PATH"\\temp.txt", "w");
    if (!pTemp) {
        printf("Could not open temp.txt for writing!\n");
        return 2;
    }
    
    for (char c; (c = fgetc(pFile)) != EOF;) {
        if (fputc(toupper(c), pTemp) == EOF) {
            printf("Failed to write upper case character to temp.txt file!\n");
            return 3;
        }
    }
    
    fclose(pFile);
    pFile = NULL;
    fclose(pTemp);
    pTemp = NULL;
    
    if (rename(PATH"\\temp.txt", PATH"\\file.txt")) {
        printf("Failed to rename temp.txt file to file.txt file!\n");
        return 4;
    }
    
	return 0;
}