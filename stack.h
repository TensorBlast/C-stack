#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 4

typedef struct stack
{
	void *elem;
	size_t elementsize;
	int size;
	int allocsize;
} stack;

stack * create_stack(size_t );
void push(stack *,  void *);
void pop(stack *, void *);
void stackdispose(stack *);
int stackempty(stack *);