#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mock {
    const char * func_name;
    void * val;
};

struct {
    struct mock * mock_ptr;
    int size;
} mock_queue = { NULL, 0 };

static void resize_mock_queue(int new_size);

void set_mock(const char * func_name, void * mock_val) {
    if (mock_queue.size < 1) {
        mock_queue.mock_ptr = (struct mock *) malloc(sizeof(struct mock));
        if (mock_queue.mock_ptr == NULL) {
            fprintf(stderr, "Failed to allocated memory!\n");
            exit(EXIT_FAILURE);
        }
    } else {
        resize_mock_queue(mock_queue.size + 1);
    }
    mock_queue.mock_ptr[mock_queue.size].func_name = func_name;
    mock_queue.mock_ptr[mock_queue.size].val = mock_val;
    mock_queue.size++;
}

void * get_mock(void) {
    if (mock_queue.size < 1) {
        fprintf(stderr, "Cannot get mock since the queue is empty!\n");
        exit(EXIT_FAILURE);
    } else {
        printf("-> inside mock function\n"); // DEBUG
        void * mock_val = mock_queue.mock_ptr[0].val;
        if (mock_queue.size == 1) {
            free(mock_queue.mock_ptr);
        } else {
            memmove(mock_queue.mock_ptr, mock_queue.mock_ptr + 1, (mock_queue.size - 1) * sizeof(struct mock));
            resize_mock_queue(mock_queue.size - 1);
        }
        mock_queue.size--;
        return mock_val;
    }
}

static void resize_mock_queue(int new_size) {
    struct mock * temp_ptr = (struct mock *) realloc(mock_queue.mock_ptr, new_size * sizeof(struct mock));
    if (temp_ptr == NULL) {
        fprintf(stderr, "Failed to reallocate memory!\n");
        free(mock_queue.mock_ptr);
        exit(EXIT_FAILURE);
    }
    mock_queue.mock_ptr = temp_ptr;
}