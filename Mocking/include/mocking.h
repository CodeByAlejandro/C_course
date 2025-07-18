#include <stdbool.h>

struct mock {
    const void * func;
    void * val;
};

struct found_mock {
    bool found;
    struct mock mock;
};

/*
 * Use this function to set a mock in test code (at runtime), for a function wrapped by the MOCK_FOR_TEST-macro in non-test code.
 * Simply do not use this function, if you still want to run the real function call, in a particular test.
 */
void set_mock(const void * func, void * val);

/*
 * Function for use in the MOCK_FOR_TEST-macro that is expanded in non-test code.
 * It is used to retrieve the mocked value set by the set_mock-function in a test.
 * The returned struct contains a bool found to indicate whether a mock was found and thus whether the mocked value or the real call should be used.
 */
struct found_mock * get_mock(const void * func);

/*
 * Use this function to remove a previously set mock in test code (at runtime), for a function wrapped by the MOCK_FOR_TEST-macro in non-test code.
 */
void remove_mock(const void * func);

/*
 * Use this function to remove all previously set mocks in test code (at runtime), for functions wrapped by the MOCK_FOR_TEST-macro in non-test code.
 * It will deallocate all the dynamically allocated mock list memory.
 * 
 * Note: If you don't call this function, and if you don't remove all previously set mocks 1 by 1 with the remove_mock function manually, you will technically create a memory leak.
 * This is not such a big deal though as the mock list is to be used during the entire lifetime of the test execution anyway.
 */
void reset_mocks(void);