#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int a:4;  // 4 bits
    unsigned int b:4;  // 4 bits
    unsigned short c;  // 16 bits
    unsigned int d:8;  // 8 bits
    unsigned int e:8;  // 8 bits
    unsigned int f:16; // 16 bits
} No_padding;

typedef struct {
    unsigned int a:4;  // 4 bits
    unsigned int b:4;  // 4 bits
    unsigned short int :0;   // Force alignment to the next boundary -> short keyword is CRUCIAL here because the type also determines the byte alignment and thus padding size !!!!
    unsigned short c;  // 16 bits
    unsigned int d:8;  // 8 bits
    unsigned int e:8;  // 8 bits
    unsigned int f:16; // 16 bits
} Padding;

int main() {
    printf("Size of struct example_no_padding: %lu bytes\n", sizeof(No_padding));
    printf("Size of struct example_with_padding: %lu bytes\n", sizeof(Padding));
    
    No_padding* pNoPadding = (No_padding*) malloc(sizeof(No_padding));
    *pNoPadding = (No_padding) { 0xF, 0xF, 0xFFFF, 0xFF, 0xFF, 0xFFFF };
    Padding* pPadding = (Padding*) malloc(sizeof(Padding));
    *pPadding = (Padding) { 0xF, 0xF, 0xFFFF, 0xFF, 0xFF, 0xFFFF };
    
    //Look at memory with debugger
    
    free(pNoPadding);
    free(pPadding);
    
    return 0;
}