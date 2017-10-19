#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vectorInit(Vector *vector){
    vector->size = 0;
    vector->capacity = INIT_CAPACITY;
    vector->data = malloc(sizeof(int)*vector->capacity);
}

void vectorFree(Vector *vector){
    free(vector->data);
}

int size(Vector *vector){
    return vector->size;
}

int capacity(Vector *vector){
    return vector->capacity;
}

bool isEmpty(Vector *vector){
    return (bool) !vector->size;
}

int vectorGet(Vector *vector, int index){
    if(index<0 || index>=vector->size){
        printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
        exit(1);
    }
    return *(vector->data+index);
}

void push(Vector *vector, int value){
    if(vector->size == vector->capacity)
        resize(vector,2*vector->capacity);

    *(vector->data+vector->size++) = value;
}

void resize(Vector *vector, int newCapacity){
    vector->capacity = newCapacity;
    vector->data = realloc(vector->data, sizeof(int)*vector->capacity);
}

void insertElem(Vector *vector, int position, int value){
    if(position < 0){
        printf("Index %d out of bounds for vector of size %d\n", position, vector->size);
        exit(1);
    }

    if(position < vector->size ) {
        if(vector->size == vector->capacity)
            resize(vector, 2 * vector->capacity);
        vector->size++;
        for(int i = vector->size - 2; i >= position; i--)
            *(vector->data+i+1) = *(vector->data+i);
    }
    while (position>=vector->size)
        push(vector, 0);

    *(vector->data+position) = value;

}

void prepend(Vector *vector, int value){
    insertElem(vector,0,value);
}

int pop(Vector *vector){
    if(vector->capacity / --vector->size == 4)
        resize(vector, vector->capacity / 2);
    return *(vector->data+vector->size);
}

void deleteElem(Vector *vector, int index){
    if(index<0 || index>=vector->size){
        printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
        exit(1);
    }
    for(int i = index + 1; i < vector->size; i++)
    {
        *(vector->data+i-1) = *(vector->data+i);
    }
    vector->size--;
}

void removeElem(Vector *vector, int value){
    for(int i = vector->size - 1; i >= 0; i--)
    {
        if(*(vector->data+i) == value)
        {
            deleteElem(vector, i);
        }
    }
}

int findElem(Vector *vector, int value){
    for(int i = 0; i < vector->size; i++)
        if(*(vector->data+i) == value)
            return i;
    return -1;
}

int findElem2(Vector *vector, int value){
    int i = 0;
    while(*(vector->data+i)!=value)
        if (i++ == vector->size)
            return -1;
    return i;
}



