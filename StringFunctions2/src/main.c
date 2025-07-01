#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char **argv) {
	if(argc != 3) {
		fprintf(stderr, "Usage: %s char filepath\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	FILE * fp = fopen(argv[2], "r");
	if(fp == NULL) {
		fprintf(stderr, "Could not open %s for reading!\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	size_t len = MAX_LINE_LENGTH * sizeof(char);
	char * line = (char *) malloc(len);
	for(int cnt = 1; getline(&line, &len, fp) != -1; cnt++) {
		if(strchr(line, *argv[1]) != NULL) {
			fputs(line, stdout);
			if(feof(stdout)) {
				fprintf(stderr, "Failed to write matching line to stdout!\n");
				free(line);
				fclose(fp);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);

	if(ferror(fp)) {
		fprintf(stderr, "Failed to read line from %s!\n", argv[2]);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	
	fclose(fp);
	return 0;
}