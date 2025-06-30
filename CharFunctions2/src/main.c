#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <readline/readline.h>

#define TEST_FILEPATH "./src/test.txt"

void writeTestFile(void);
void convertCase(const char * filePath);

int main(int argc, char **argv) {
	char * filePath = NULL;

	if(argc > 1) {
		filePath = argv[1];
	} else {
		writeTestFile();
	
		filePath = readline("Enter file path: ");

		// Remove trailing white-space
		char * pc = filePath;
		while(*pc) pc++;
		pc--;
		while(isspace(*pc)) pc--;
		*++pc = '\0';
		
		// Reallocate mem for the modified filePath
		pc = realloc(filePath, strlen(filePath) + 1);
		if(pc) {
			filePath = pc;
		}
	}
	
	convertCase(filePath);

	if(argc < 2)
		free(filePath);

	return 0;
}

void writeTestFile(void) {
	FILE * fp = fopen(TEST_FILEPATH, "w");
	if(!fp) {
		fprintf(stderr, "Could not open %s for writing!\n", TEST_FILEPATH);
		exit(EXIT_FAILURE);
	}
	fputs("De INHOUD van deze\nFILE moet worden geswiTCHED\nVAN CASE! :)\n", fp);
	if(feof(fp)) {
		fprintf(stderr, "Failed to write test contents to %s!\n", TEST_FILEPATH);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
}

void convertCase(const char * filePath) {
	FILE * fp = fopen(filePath, "r+");
	if(!fp) {
		fprintf(stderr, "Could not open %s for reading!\n", filePath);
		exit(EXIT_FAILURE);
	}
	for(int c; (c = fgetc(fp)) != EOF;) {
		c = isupper(c) ? tolower(c) : toupper(c);
		fseek(fp, -1, SEEK_CUR);
		fputc(c, fp);
		if(feof(fp)) {
			fprintf(stderr, "Failed to write character %d to %s!\n", c, filePath);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
	}
	if(ferror(fp)) {
		fprintf(stderr, "Failed to read character from %s!\n", filePath);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
}