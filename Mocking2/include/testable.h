#include "enable_testing.h"

#ifdef TEST
    /*
     * Sets static methods to be extern in TEST-mode to allow testing from a separate source file.
     */
    #define EXTERN_FOR_TEST 
#else
    /*
     * Resolves to static since TEST-mode is off.
     */
    #define EXTERN_FOR_TEST static
#endif