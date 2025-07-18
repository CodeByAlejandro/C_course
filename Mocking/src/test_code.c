#include "enable_testing.h"

#ifdef TEST
    #include <stdio.h>
    #include <assert.h>
    #include "code.h"
    #include "mocking.h"

    int add(int x, int y);

    static void test_add(void);
    static void test_add_triplet(void);
    static void test_add_quintet(void);

    void test_code(void) {
        printf("* ----- Testing code ----- *\n");
        test_add();
        test_add_triplet();
        test_add_quintet();
    }

    static void test_add(void) {
        printf("Testing add(x, y):\n");
        assert(add(1, 2) == 3);
    }

    static void test_add_triplet(void) {
        printf("Testing add_triplet(x, y, z):\n");
        int mock_val = 3;
        set_mock((void *) add, (void *) &mock_val);
        assert(add_triplet(1, 2, 3) == 6);
        reset_mocks();
    }

    static void test_add_quintet(void) {
        printf("Testing add_quintet(v, w, x, y, z):\n");
        int mock_add_val = 3, mock_add_triplet_val = 6;
        set_mock((void *) add, (void *) &mock_add_val);
        set_mock((void *) add_triplet, (void *) &mock_add_triplet_val);
        assert(add_quintet(1, 2, 1, 2, 3) == 9);
    }
#endif