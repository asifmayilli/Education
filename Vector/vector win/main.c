#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
	Vector my_vector;
	vector_init(&my_vector);
	int my_capacity = vector_capacity(&my_vector);
	int my_size = vector_size(&my_vector);
	
	printf("capacity: %d \n", vector_capacity(&my_vector));
	printf("size: %d \n", vector_size(&my_vector));
	
	//printf("%d \n", vector_is_empty(&my_vector));
	//printf("%s \n", vector_is_empty(&my_vector) ? "true" : "false");
	
	// printf("%d \n", vector_get(&my_vector, -3));
	vector_push(&my_vector, 23);
	vector_push(&my_vector, 7);
	
	printf("\t==========\t\t\n");
	
	printf("%d \n", vector_get(&my_vector, 0));
	printf("%d \n", vector_get(&my_vector, 1));
	// printf("%d \n", vector_get(&my_vector, 2));
	
	vector_add_element(&my_vector, 8, 88);
	
	printf("\n size: %d\n", vector_size(&my_vector));
	printf("\n capacity: %d\n", vector_capacity(&my_vector));
	
	for(int i = 0; i < vector_size(&my_vector); i++)
	{
		printf("%d  - %d \n", i, my_vector.data[i]);
				
	}
	printf("\n size: %d\n", vector_size(&my_vector));
	printf("\n capacity: %d\n", vector_capacity(&my_vector));
	vector_add_element(&my_vector, 3, 33);
	
	for(int i = 0; i < vector_size(&my_vector); i++)
	{
		printf("%d  - %d \n", i, my_vector.data[i]);
				
	}
	printf("\n size: %d\n", vector_size(&my_vector));
	printf("\n capacity: %d\n", vector_capacity(&my_vector));
	
	
	
	printf("\n last elem: %d\n", vector_pop(&my_vector));
	
	
	vector_push(&my_vector, 77);
	
	vector_delete_element(&my_vector, 3);
	for(int i = 0; i < vector_size(&my_vector); i++)
	{
		printf("%d  - %d \n", i, my_vector.data[i]);
				
	}
	printf("\n size: %d\n", vector_size(&my_vector));
	printf("\n capacity: %d\n", vector_capacity(&my_vector));
	
	vector_remove_element(&my_vector, 0);
	for(int i = 0; i < vector_size(&my_vector); i++)
	{
		printf("%d  - %d \n", i, my_vector.data[i]);
				
	}
	printf("\n size: %d\n", vector_size(&my_vector));
	printf("\n capacity: %d\n", vector_capacity(&my_vector));
	
	
	printf("\n element 7: %d\n", vector_find_element(&my_vector, 7));
	
	vector_push(&my_vector, 4);
	vector_push(&my_vector, 5);
	
	for(int i = 0; i < vector_size(&my_vector); i++)
	{
		printf("%d  - %d \n", i, my_vector.data[i]);
				
	}
	printf("\n size: %d\n", vector_size(&my_vector));
	printf("\n capacity: %d\n", vector_capacity(&my_vector));
	
	
	printf("\n last elem: %d\n", vector_pop(&my_vector));
	
	
	for(int i = 0; i < vector_size(&my_vector); i++)
	{
		printf("%d  - %d \n", i, my_vector.data[i]);
				
	}
	printf("\n size: %d\n", vector_size(&my_vector));
	printf("\n capacity: %d\n", vector_capacity(&my_vector));
	
	
	vector_free(&my_vector);
	
	return 0;
}
