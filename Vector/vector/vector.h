#define INIT_CAPACITY 16
#include <stdbool.h>

typedef struct {
    int size; //amount of used elements
    int capacity; //maximum available slots
    int *data; //pointer to the start of the array
} Vector;

void vectorInit(Vector *vector); //+
void vectorFree(Vector *vector); //+
int size(Vector *vector); //+
int capacity(Vector *vector);//+
bool isEmpty(Vector *vector);//+
int vectorGet(Vector *vector, int index);//+
void push(Vector *vector, int value);//+
void insertElem(Vector *vector, int position, int value); //+
void prepend(Vector *vector, int value); //+
int pop(Vector *vector);//+
void deleteElem(Vector *vector, int index);//+
void removeElem(Vector *vector, int value);
int findElem(Vector *vector, int value);//+
int findElem2(Vector *vector, int value);//+
void resize(Vector *vector, int newCapacity);//+

