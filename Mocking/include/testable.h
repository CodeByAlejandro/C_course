#include <stdbool.h>
#include "enable_testing.h"
#include "mocking.h"

#ifdef TEST
    /*
     * Sets static methods to be extern in TEST-mode to allow testing from a separate source file.
     */
    #define EXTERN_FOR_TEST 
    /*
     * Use this macro in non-test code to allow mocking in TEST mode.
     * If no mock is found at runtime the real call is used as fallback.
     *
     * Note: the get_mock function is called twice but the return value is cached.
     */
    #define MOCK_FOR_TEST(real_call, func, return_type) (((get_mock((void *) func))->found) ? *((return_type *) ((get_mock((void *) func))->mock.val)) : real_call)
#else
    /*
     * Resolves to static since TEST-mode is off.
     */
    #define EXTERN_FOR_TEST static
    /*
     * Runs the real call since TEST mode is off.
     */
    #define MOCK_FOR_TEST(real_call, func, return_type) real_call
#endif