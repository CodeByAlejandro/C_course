#include <stdio.h>
#include <assert.h>
#include "code.h"
#include "mocking.h"

MOCK(int, add, int, int)

int add(int x, int y);
static int add_mock(int x, int y);

void test_add_triplet_mock_func(void) {
    printf("inside test_add_triplet_mock_func\n");
    MOCK_FUNC(add, add_mock)
    int result = add_triplet(1, 2, 3);
    assert(result == 6);
    assert(ASSERT_FUNC_CALLED_WITH_ARGS(add, 1, 2));
}

void test_add_triplet_mock_val(void) {
    printf("inside test_add_triplet_mock_val\n");
    MOCK_VAL(add, 3)
    int result = add_triplet(1, 2, 3);
    assert(result == 6);
    assert(ASSERT_FUNC_CALLED_WITH_ARGS(add, 1, 2));
}

void test_add_triplet_mock_real(void) {
    printf("inside test_add_triplet_mock_real\n");
    MOCK_REAL(add)
    int result = add_triplet(1, 2, 3);
    assert(result == 6);
    assert(ASSERT_FUNC_CALLED_WITH_ARGS(add, 1, 2));
}
static int add_mock(int x, int y) {
    printf("-> inside mock add function\n");
    return 3;
}