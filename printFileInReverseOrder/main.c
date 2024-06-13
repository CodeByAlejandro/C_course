#include <stdio.h>

#define PATH "D:\\Documents\\CodeLite\\Workspaces\\C-course\\printFileInReverseOrder\\"

int main(int argc, char **argv)
{
    // Create file handle
	FILE *pf = fopen(PATH"file.txt", "r");
    if (!pf) {
        printf("Could not open "PATH"file.txt for reading!\n");
        return 1;
    }
    
    // Move to last position in file
    if (fseek(pf, 0, SEEK_END)) {
        printf("Could not move to last position in file!\n");
        return 2;
    }
    
    // Decrement last position since we want to read the last position itself first, not the EOF.
    long pos = ftell(pf) - 1;
    
    // Read file in opposite direction
    // It's need we can also use EOF, since it is defined as -1
    for (; pos > EOF; pos--) {
        // Move to the previous position
        if (fseek(pf, pos, SEEK_SET)) {
            printf("Could not move previous position in file!\n");
            return 3;
        }
        //print character
        printf("%c", fgetc(pf));
    }
    
    // Close file handle
    fclose(pf);
    pf = NULL;
    
	return 0;
}