#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "file.txt"

void writeOriginalFile(const char * filePath);
void convertToUpperCase(const char * filePath);
void determineTempFilepath(char * tempFilePath, const char * filePath);

int main(int argc, char **argv) {
	writeOriginalFile(FILENAME);
	convertToUpperCase(FILENAME);
	
	// if(remove(FILENAME)) {
	// 	fprintf(stderr, "Failed to remove %s!\n", FILENAME);
	// 	exit(6);
	// }

	return 0;
}
 
void writeOriginalFile(const char * filePath) {
	FILE * pFile = NULL;
	pFile = fopen(filePath, "w");
	if(!pFile) {
		fprintf(stderr, "Could not open %s for writing!\n", filePath);
		exit(1);
	}
	fputs("This file\nis to be converted\n to upper\ncase! ;)", pFile);
	if(feof(pFile)) {
		fprintf(stderr, "Failed to write to file %s!\n", filePath);
		exit(2);
	}
	fclose(pFile);
	pFile = NULL;
}

void convertToUpperCase(const char * filePath) {
	char tempFilePath[255];
	FILE * pFile = NULL;
	FILE * pTemp = NULL;

	determineTempFilepath(tempFilePath, filePath);

	pFile = fopen(filePath, "r");
	if(!pFile) {
		fprintf(stderr, "Could not open %s for reading!\n", filePath);
		exit(1);
	}
	
	pTemp = fopen(tempFilePath, "w");
	if (!pTemp) {
		fprintf(stderr, "Could not open %s for writing!\n", tempFilePath);
		exit(1);
	}
	
	for(int c; (c = fgetc(pFile)) != EOF;) {
		fputc(toupper(c), pTemp);
		if(feof(pFile)) {
			fprintf(stderr, "Failed to write to file %s!\n", tempFilePath);
			exit(2);
		}
	}
	if(ferror(pFile)) {
		fprintf(stderr, "Failed to read from file %s!\n", filePath);
		exit(3);
	}
	
	if(fclose(pFile) == EOF) {
		fprintf(stderr, "Failed to close file %s!\n", filePath);
		exit(4);
	}

	if(fclose(pTemp)) {
		fprintf(stderr, "Failed to close file %s!\n", tempFilePath);
		exit(4);
	}
	
	pFile = NULL;
	pTemp = NULL;

	if(rename(tempFilePath, filePath)) {
		fprintf(stderr, "Failed to rename %s to %s!\n", tempFilePath, filePath);
		exit(5);
	}
}

void determineTempFilepath(char * tempFilePath, const char * filePath) {
	for(; *filePath != '.'; *tempFilePath++ = *filePath++);
	strcpy(tempFilePath, "_temp");
	tempFilePath += 5;
	for(; *filePath; *tempFilePath++ = *filePath++);
	*tempFilePath = '\0';
}