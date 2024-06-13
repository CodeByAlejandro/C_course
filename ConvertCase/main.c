#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <readline/readline.h>

// This function is called to perform the completion
char **filename_completion_function(const char *text, int start, int end) {
    // Use Readline's default filename completion function
    return rl_completion_matches(text, rl_filename_completion_function);
}

// This function is called to initialize the Readline completion
void initialize_readline() {
    // Tell Readline to use our completion function
    rl_attempted_completion_function = filename_completion_function;
}

void removeTrailingWhitespace(char * restrict str);

int main(int argc, char **argv) {
    bool inputFromStdin = false;
    
    // Get filename
    char *pFilename = NULL;
    if (argc > 1) {
        pFilename = argv[1];
    } else {
        inputFromStdin = true;
        initialize_readline();
        while ((pFilename = readline("Enter file name: ")) == NULL);
        removeTrailingWhitespace(pFilename);
    }
    
    // Get file pointer
    FILE *fp = fopen(pFilename, "r+");
    //FILE *fp = fopen(pFilename, "r+");
    if (!fp) {
        printf("Couldn't open file '%s'!", argv[1]);
        // Cleanup input from readline
        if (inputFromStdin)
            free(pFilename);
        // Exit program
        exit(1);
    }
    
    // Get case of first character
    bool isLower;
    int c = fgetc(fp);
    rewind(fp);
    if (islower(c)) {
        isLower = true;
    } else {
        isLower = false;
    }
    
    // Convert characters to other case
    for (long pos; pos = ftell(fp), (c = fgetc(fp)) != EOF;) {
        fseek(fp, pos, SEEK_SET);
        if (isLower) {
            fputc(toupper(c), fp);
        } else {
            fputc(tolower(c), fp);
        }
        if (ferror(fp)) {
            printf("An error occurred while writing to file!\n");
            exit(2);
        }
    }
    
    // Close file
    fclose(fp);
    // Cleanup input from readline
    if (inputFromStdin)
        free(pFilename);
    
    return 0;
}

void removeTrailingWhitespace(char * restrict str) {
        while (*str)
            str++;
        while (isspace((int)*--str));
        *++str = '\0';
}