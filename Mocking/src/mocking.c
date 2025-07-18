#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mocking.h"

static struct {
    struct mock * mock_ptr;
    unsigned int size;
    struct found_mock * cache; // Cache the last mock retrieval
} mock_list = { NULL, 0, NULL };

static void append_mock_list(const void * func, void * val);
static void resize_mock_list(unsigned int new_size);
static void dealloc_mock_ptr(void);
static void invalidate_cache(void);

void set_mock(const void * func, void * val) {
    bool updated_existing_mock = false;
    for (int i = 0; i < mock_list.size; i++) {
        if (mock_list.mock_ptr[i].func == func) {
            mock_list.mock_ptr[i].val = val;
            updated_existing_mock = true;
            break;
        }
    }
    if(!updated_existing_mock) {
        append_mock_list(func, val);
    }
    invalidate_cache();
}

struct found_mock * get_mock(const void * func) {
    if (mock_list.cache != NULL && mock_list.cache->mock.func == func) {
        return mock_list.cache;
    } else {
        printf("-> inside mock function\n"); // DEBUG
        if (mock_list.cache == NULL) {
            mock_list.cache = (struct found_mock *) malloc(sizeof(struct found_mock));
        }
        mock_list.cache->mock.func = func;
        bool found_existing_mock = false;
        for (int i = 0; i < mock_list.size; i++) {
            if (mock_list.mock_ptr[i].func == func) {
                mock_list.cache->mock.val = mock_list.mock_ptr[i].val;
                found_existing_mock = true;
                break;
            }
        }
        if (!found_existing_mock) {
            mock_list.cache->mock.val = NULL;
        }
        mock_list.cache->found = found_existing_mock;
        return mock_list.cache;
    }
}

void remove_mock(const void * func) {
    for (int i = 0; i < mock_list.size; i++) {
        if (mock_list.mock_ptr[i].func == func) {
            if (mock_list.size == 1) {
                free(mock_list.mock_ptr);
            } else {
                memmove(mock_list.mock_ptr + i, mock_list.mock_ptr + (i + 1), (mock_list.size - (i + 1)) * sizeof(struct mock));
                resize_mock_list(mock_list.size - 1);
            }
            mock_list.size--;
            break;
        }
    }
    invalidate_cache();
}

void reset_mocks(void) {
    dealloc_mock_ptr();
    invalidate_cache();
    mock_list.size = 0;
}

static void append_mock_list(const void * func, void * val) {
    resize_mock_list(mock_list.size + 1);
    mock_list.mock_ptr[mock_list.size].func = func;
    mock_list.mock_ptr[mock_list.size].val = val;
    mock_list.size++;
}

static void resize_mock_list(unsigned int new_size) {
    if (new_size == 0) {
        dealloc_mock_ptr();
    } else {
        if (mock_list.size == 0) {
            mock_list.mock_ptr = (struct mock *) malloc(new_size * sizeof(struct mock));
            if (mock_list.mock_ptr == NULL) {
                fprintf(stderr, "Failed to allocated memory!\n");
                exit(EXIT_FAILURE);
            }
        } else {
            struct mock * temp_ptr = (struct mock *) realloc(mock_list.mock_ptr, new_size * sizeof(struct mock));
            if (temp_ptr == NULL) {
                fprintf(stderr, "Failed to reallocate memory!\n");
                free(mock_list.mock_ptr);
                exit(EXIT_FAILURE);
            }
            mock_list.mock_ptr = temp_ptr;
        }
    }
}

static void dealloc_mock_ptr(void) {
    if (mock_list.mock_ptr != NULL) {
        free(mock_list.mock_ptr);
        mock_list.mock_ptr = NULL;
    }
}

static void invalidate_cache(void) {
    if (mock_list.cache != NULL) {
        free(mock_list.cache);
        mock_list.cache = NULL;
    }
}