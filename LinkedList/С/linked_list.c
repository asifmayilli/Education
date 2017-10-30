#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

node* create_node(int value)
{
	node* temp = (node*) malloc(sizeof(node));
	
	if(temp == NULL)
	{
		printf("Memory cannot be allocated");
		exit(1);
	}
	
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void push_front(int value)
{
	node* newnode = create_node(value);
	
	if(head == NULL)
	{
		head = newnode;
		head->next = NULL;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
	
	printf("Added %d in front of Linked list. \n", value);
}

void display()
{
	if(head == NULL)
	{
		printf("Linked list is empty! \n");
	}
	else
	{
		printf("Linked List: \n\t\t");
		
		node* temp = head;
		while(temp != NULL)
		{
			printf(" %d", temp->value);
			
			if(temp->next != NULL)
				printf(" -> ");
			
			temp = temp->next;
		}
		
		printf("\n");
	}
}

int size()
{
	int count = 0;
	
	node* temp = head;
	
	while(temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	
	printf("Size of Linked List: %d \n", count);
	return count;
}

bool empty()
{
	if(head == NULL)
	{
		return true;
	}
	return false;
}

int value_at(int index)
{
	node* temp = head;
	int count = 0;
	
	if(index < 0)
	{
		printf("index cannot be less than 0");
		exit(1);
	}
	
	
	while(temp->next != NULL)
	{
		if(count == index)
		{
			printf("Node at position %d is %d \n", index, temp->value);
			return;
		}
		temp = temp->next;
		count++;
	}
	
	printf("Node at position %d not found. Size of Linked List: %d.\n", index, count);
}

int pop_front()
{
	if(empty())
	{
		printf("No element in list\n");
		return -1;
	}
	int temp;
	if(head != NULL)
	{
		printf("First element %d was removed.\n", head->value);
		temp = head->value;
		head = head->next;
	}
	
	return temp;
}

void push_back(int value)
{
	node* newnode = create_node(value);
	
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	
	node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}

int pop_back()
{
	if(empty())
	{
		printf("No element in list\n");
		return -1;
	}
	
	if(head->next == NULL)
	{
		head = NULL;
		return;
	}
	
	node* curr = head;
	node* prev;
	
	while(curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	
	prev->next = NULL;
	free(curr);
}

int front()
{
	if(empty())
	{
		printf("No element in list\n");
		return -1;
	}
	
	return head->value;
}

int back()
{
	if(empty())
	{
		printf("No element in list\n");
		return -1;
	}
	
	node* temp = head;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	return temp->value;
}

void insert(int index, int value)
{
	if(index < 0)
	{
		printf("Index cannot be less than 0\n");
		exit(1);
	}
	
	if(head == NULL)
	{
		if(index == 1)
		{
			push_back(value);
			return;
		}
	}
	
	int size = 1;
	node* temp = head;
	while(temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	
	if(index > size)
	{
		printf("Index cannot be more than size %d \n", size);
		exit(1);
	}
	
	node* curr = head;
	node* prev;
	
	while(curr->next != NULL && index-- != 1)
	{
		prev = curr;
		curr = curr->next;
	}
	
	temp = create_node(value);
	temp->next = curr;
	prev->next = temp;

}

void erase(int index)
{
	if(index < 0)
	{
		printf("Index cannot be less than 0\n");
		exit(1);
	}
	
	if(head == NULL)
	{
		if(index == 1)
		{
			pop_back(1);
			return;
		}
	}
	
	int size = 1;
	node* temp = head;
	while(temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	
	if(index > size)
	{
		printf("Index cannot be more than size %d \n", size);
		exit(1);
	}
	
	node* curr = head;
	node* prev;
	while(curr->next != NULL && index-- != 1)
	{
		prev = curr;
		curr = curr->next;
	}
	
	prev->next = curr->next;
	free(curr);	
}

void remove_element(int value)
{
	if(empty())
	{
		printf("No element in list\n");
		exit(1);
	}
	
	if(head->value == value)
	{
		pop_front();
		return;
	}
	
	node* temp = head->next;
	node* prev = head;
	
	while(temp->next != NULL)
	{
		if(temp->value == value)
		{
			prev->next = temp->next;
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;		
	}
	
	printf("Value not found in linked list!\n");
}
