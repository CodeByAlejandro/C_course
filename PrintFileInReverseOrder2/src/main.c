#include <stdio.h>
#include <stdlib.h>

#define FILENAME "file.txt"

void writeOriginalFile(const char * filePath);

int main(int argc, char **argv) {
	writeOriginalFile(FILENAME);
	
	FILE * pFile = NULL;
	pFile = fopen(FILENAME, "r");
	if(!pFile) {
		fprintf(stderr, "Could not open %s for reading!\n", FILENAME);
		exit(1);
	}

	if(fseek(pFile, 0, SEEK_END)) {
		fprintf(stderr, "Failed to seek in %s!\n", FILENAME);
		exit(4);
	}
	long fpos = ftell(pFile);
	fpos--;
	
	for(; fpos >= 0; fpos--) {
		if(fseek(pFile, fpos, SEEK_SET)) {
			fprintf(stderr, "Failed to seek in %s!\n", FILENAME);
			exit(4);
		}
		printf("%c", fgetc(pFile));
		if(ferror(pFile)) {
			fprintf(stderr, "Failed to read from %s!\n", FILENAME);
			exit(3);
		}
	}
	
	fclose(pFile);
	pFile = NULL;

	printf("\n");
	return 0;
}

void writeOriginalFile(const char * filePath) {
	FILE * pFile = NULL;
	pFile = fopen(filePath, "w");
	if(!pFile) {
		fprintf(stderr, "Could not open %s for writing!\n", filePath);
		exit(1);
	}
	fputs("This file\nis to be printed\nin reverse\norder!", pFile);
	if(feof(pFile)) {
		fprintf(stderr, "Failed to write to file %s!\n", filePath);
		exit(2);
	}
	fclose(pFile);
	pFile = NULL;
}