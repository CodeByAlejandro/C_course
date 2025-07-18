#include <stdbool.h>
#include "enable_testing.h"
#include "mocking.h"

#ifdef TEST
    #define EXTERN_FOR_TEST 
    #define MOCK_FOR_TEST(real_call, func, return_type) (((get_mock((void *) func))->found) ? *((return_type *) ((get_mock((void *) func))->mock.val)) : real_call)
#else
    #define EXTERN_FOR_TEST static
    #define MOCK_FOR_TEST(real_call, func, return_type) real_call
#endif