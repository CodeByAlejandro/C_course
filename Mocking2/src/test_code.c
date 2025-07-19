#include <stdio.h>
#include "code.h"

extern int (*add_ptr) (int, int);

static int add_mock(int x, int y);

void test_add_triplet(void) {
    add_ptr = add_mock;
    add_triplet(1, 2, 3);
}

static int add_mock(int x, int y) {
    printf("-> inside mock add function\n");
    return 3;
}