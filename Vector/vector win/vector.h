#include <stdbool.h>
#define VECTOR_INIT_CAPACITY 8

typedef struct {
	int size;
	int capacity;
	int *data;
} Vector;

void vector_init(Vector *vector);

void vector_free(Vector *vector);

int vector_size(Vector *vector);

int vector_capacity(Vector *vector);

bool vector_is_empty(Vector *vector);

int vector_get(Vector *vector, int index);

void vector_push(Vector *vector, int value);

void vector_add_element(Vector *vector, int index, int value);

void vector_prepend(Vector *vector, int value);

int vector_pop(Vector *vector);

void vector_delete_element(Vector *vector, int index);

void vector_remove_element(Vector *vector, int value);

int vector_find_element(Vector *vector, int value);

int vector_find_element2(Vector *vector, int value);

int vector_resize(Vector *vector, int new_capacity);

