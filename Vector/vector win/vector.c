#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector)
{
	vector->size = 0;
	vector->capacity = VECTOR_INIT_CAPACITY;
	
	vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector_free(Vector *vector)
{
	free(vector->data);
}

int vector_size(Vector *vector)
{
	return vector->size;
}

int vector_capacity(Vector *vector)
{
	return vector->capacity;
}

bool vector_is_empty(Vector *vector)
{
	if(vector->size == 0)
	{
		return true;		
	}
	
	return false;	
}

int vector_get(Vector *vector, int index)
{
	if(index < 0 || index >= vector->size)
	{
		printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    	exit(1);	
	}
	
	return *(vector->data+index);
//	return vector->data[index];
}

void vector_push(Vector *vector, int value)
{
	if(vector->size == vector->capacity)
	{
		// double capacity
		vector_resize(vector, 2 * vector->capacity);
	}
	
//	*(vector->data+vector->size++) = value;
	vector->data[vector->size++] = value;
}

int vector_resize(Vector *vector, int new_capacity)
{
	// printf("resized! \n");
	vector->capacity = new_capacity;
	vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
}

void vector_add_element(Vector *vector, int index, int value)
{
	if(index < 0)
	{
		printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    	exit(1);	
	}
	
	if(index < vector->size)
	{
		if(vector->size == vector->capacity)
		{
			vector_resize(vector, 2 * vector->capacity);
		}
		
		for(int i = vector->size - 1; i >= index; i--)
		{
			*(vector->data+i+1) = *(vector->data+i);
//			vector->data[i+1] = vector->data[i];
		}
		vector->size++;
	}
	
	while(index >= vector->size)
	{
		vector_push(vector, 0);
	}
	
	*(vector->data+index) = value;
//	vector->data[index] = value;
	
}

void vector_prepend(Vector *vector, int value)
{
	vector_add_element(vector, 0, value);
}

int vector_pop(Vector *vector)
{
	if(vector->capacity / --vector->size == 4)
	{
		vector_resize(vector, vector->capacity / 2);
	}
	
	return *(vector->data + vector->size);
}

void vector_delete_element(Vector *vector, int index)
{
	if(index < 0 || index >= vector->size)
	{
		printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    	exit(1);	
	}
	
	for(int i = index + 1; i < vector->size; i++)
	{
		*(vector->data + i-1) = *(vector->data + i);
//		vector->data[i-1] = vector->data[i];
	}
	
	vector->size--;
}

void vector_remove_element(Vector *vector, int value)
{
	for(int i = vector->size - 1; i >= 0; i--)
	{
		if(vector->data[i] == value)
		{
			vector_delete_element(vector, i);
		}
	}
}

int vector_find_element(Vector *vector, int value)
{
	for(int i = 0; i < vector->size; i++)
	{
		if(*(vector->data+i) == value)
		{
			return i;
		}
	}
	return -1;
}

int vector_find_element2(Vector *vector, int value)
{
    int i = 0;
    while(*(vector->data+i)!=value)
        if (i++ == vector->size)
            return -1;
    return i;
}
