#include <stdbool.h>
#include <stddef.h>

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL;

node* create_node(int value);
int size();
bool empty();
int value_at(int index);
void push_front();
int pop_front();
void push_back(int value);
int pop_back();
int front();
int back();
void insert(int index, int value);
void erase(int index);
void remove_element(int value);
void display();
