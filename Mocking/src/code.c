#include <stdio.h>
#include "testable.h"

EXTERN_FOR_TEST int add(int x, int y);

int add_triplet(int x, int y, int z) {
    return MOCK_FOR_TEST(add(x, y), int) + z;
}

int add_quintet(int v, int w, int x, int y, int z) {
    int add_res = 0;
    add_res += MOCK_FOR_TEST(add(v, w), int);
    add_res += MOCK_FOR_TEST(add_triplet(x, y, z), int);
    return add_res;
}

EXTERN_FOR_TEST int add(int x, int y) {
    printf("-> inside real add function\n"); // DEBUG
    return x + y;
}