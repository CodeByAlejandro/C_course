#include <stdio.h>

int main(void)
{
	FILE *pFile = fopen("D:\\Documents\\CodeLite\\Workspaces\\C-course\\CountFileLines\\file.txt", "r");
    if(!pFile) {
        printf("Could not open file!\n");
        return 1;
    }
    
    int lineCount = 1;
    for (char c; (c = fgetc(pFile)) != EOF;) {
        if (c == '\n')
            lineCount++;
    }
    
    fclose(pFile);
    pFile = NULL;
    
    printf("Line count is %d\n", lineCount);
    
	return 0;
}