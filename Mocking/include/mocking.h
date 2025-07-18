#include <stdbool.h>

struct mock {
    const void * func;
    void * val;
};

struct found_mock {
    bool found;
    struct mock mock;
};

void set_mock(const void * func, void * val);
struct found_mock * get_mock(const void * func);
void remove_mock(const void * func);
void reset_mocks(void);