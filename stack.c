#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

stack * create_stack(size_t elemsize)
{
	stack *t = (stack *) malloc (sizeof(*t));

	t->elem = malloc(INIT_SIZE * elemsize);
	t->elementsize = elemsize;
	t->size = 0;
	t->allocsize = INIT_SIZE;

	return t;
}

void stackdispose(stack *t)
{
	free(t);
}

int stackempty(stack *t)
{
	return t->size==0;
}

void push(stack *t, void *elem)
{
	if (t==NULL) {
		fprintf(stderr, "%s\n", "Stack not initialized");
	}
	else
	{
		if (t->size == t->allocsize) {
			t->allocsize *= 2;
			t->elem = realloc(t->elem, t->elementsize *  t->allocsize);
			memcpy((char *)t->elem + t->elementsize * t->size, elem, t->elementsize);
		}
		else
		{
			memcpy((char *)t->elem + t->elementsize * t->size, elem, t->elementsize);

		}
		t->size++;
	}
}

void pop(stack *t, void * elementaddr)
{
	const void * sourceAddr;
	if (t->size == 0)
	{
		fprintf(stderr, "%s\n", "Stack is empty!");
	}
	else
	{
		sourceAddr = (const char *)t->elem + t->elementsize * --t->size;
		memcpy(elementaddr, sourceAddr, t->elementsize);
	}

}
