#include <stdio.h>
#include "modifiedDay1.h"

void push(node* stack[], int max, int *stackPointer, node* value) // pushing in stack
{
	if(*stackPointer == max-1)
	{
		return;
	}
	else
	{
		stack[++(*stackPointer)] = value;
	}
}

void pop(node* stack[], int max, int *stackPointer) // popping from stack
{
	if(*stackPointer == -1)
	{
		return;
	}
	else
	{
        stack[*stackPointer] = NULL;
		*stackPointer -= 1;
	}
}

int isEmpty(node* stack[], int max, int stackPointer) // check if empty
{
	if(stackPointer == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(node* stack[], int max, int stackPointer) // check if full
{
	if(stackPointer == (max-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

node* top(node* stack[], int max, int stackPointer) // return the top node
{
	return stack[stackPointer];
}
