#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s character filename\n\n", argv[0]);
        fprintf(stderr, "Please provide the following arguments:\n");
        fprintf(stderr, "\t- a character to find lines that contain it\n");
        fprintf(stderr, "\t- a file path for the file to search in\n");
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1) {
        fprintf(stderr, "The first argument must be a single character!\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[2], "r");
    if (!fp) {
        fprintf(stderr, "Couldn't open file '%s' for reading!\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    ssize_t nread;
    size_t size = 256; // Allow 254 chars + \n + \0 terminator for initial buffer size
    char *pLine = (char*) malloc(size);
    while ((nread = getline(&pLine, &size, fp)) != -1) {
        for (int i = 0; i < nread; i++) {
            // Check if string contains character
            if (pLine[i] == *argv[1]){
                fputs(pLine, stdout);
                break;
            }
        }
        if (ferror(stdout)) {
            fprintf(stderr, "Error occurred while writing to stdout!\n");
            exit(EXIT_FAILURE);
        }
    }
    if (ferror(fp)) {
        fprintf(stderr, "Error occurred while reading file!\n");
        exit(EXIT_FAILURE);
    }
    free(pLine);
    return 0;
}