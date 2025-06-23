#include <stdio.h>
#include <stdlib.h>

#define chkWriteError(stream) \
	if (feof(stream)) { \
		fprintf(stderr, "Error writing to "#stream"!\n"); \
		return 1; \
	}

int cntNewlines(FILE * pFile);

int main(int argc, char **argv) {
	FILE * pFile = NULL;
	pFile = fopen("file.txt", "w+");
	if (!pFile) {
		fprintf(stderr, "Could not open file.txt for writing and reading!\n");
		return 1;
	}
	fputs("This file\n", pFile);
	// pFile->_flags |= _IO_EOF_SEEN; // Test
	chkWriteError(pFile);
	fputs("contains\n", pFile);
	chkWriteError(pFile);
	fputs("5\n", pFile);
	chkWriteError(pFile);
	fputs("lines.\n", pFile);
	chkWriteError(pFile);
	
	// Put current position back at star of file
	rewind(pFile);

	int countNewlines = cntNewlines(pFile);

	printf("The file contains %d %s.\n", countNewlines, countNewlines == 1 ? "newline" : "newlines");
	
	fclose(pFile);
	pFile = NULL;
	
	remove("file.txt");

	printf("\n");
	return 0;
}

int cntNewlines(FILE * pFile) {
	int countNewlines = 1;
	for(char c; (c = fgetc(pFile)) != EOF;) {
		if(c == '\n')
			countNewlines++;
	}
	// pFile->_flags |= _IO_ERR_SEEN; // Test
	if(ferror(pFile)) {
		fprintf(stderr, "Error occurred while reading!\n");
		exit(1);
	}
	return countNewlines;
}