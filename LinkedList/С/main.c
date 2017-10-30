#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	if(empty())
	{
		printf("Empty!\n");
	}
	else
	{
		printf("not empty :D \n");
	}
	
	push_back(-1);
	
	size();
	display();
	
	
	push_front(23);
	push_front(5);
	push_front(8);

	value_at(2);
		
	display();
	
	size();
	int popped = pop_front();
	
	display();
	
	push_back(7);
	display();
	

	pop_back();
	display();
	printf("First element: %d. \n Last element: %d", front(), back());
	
	size();
	
	
	
	display();
	insert(3, 4);
	display();
	
	
	erase(4);
	display();
	
	remove_element(58);
	display();
	
	return 0;
}
