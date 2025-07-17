#include "enable_testing.h"
#include "mocking.h"

#ifdef TEST
    #define EXTERN_FOR_TEST 
    #define MOCK_FOR_TEST(func_call, return_type) *((return_type*) get_mock())
#else
    #define EXTERN_FOR_TEST static
    #define MOCK_FOR_TEST(func_call, return_type) func_call
#endif