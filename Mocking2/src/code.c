#include <stdio.h>
#include "testable.h"

EXTERN_FOR_TEST int add(int x, int y);

int (*add_ptr) (int, int) = add;

int add_triplet(int x, int y, int z) {
    return (*add_ptr)(x, y) + z;
}

EXTERN_FOR_TEST int add(int x, int y) {
    printf("-> inside real add function\n");
    return x + y;
}