/*
	Group ID - A4
	Siddarth Gopalakrishnan - 2017B3A71379H
	Pranav Grandhi - 2017B2A71604H
	Rahul Shevade - 2017B3A70878H
*/
#include<stdio.h>
#include "stack.h"

void push(node* stack[], int max, int *stackPointer, node* value)
{
	if(*stackPointer == max-1) // checking if stack is full
	{
	    return;
	}
	else
	{ // increment pointer and add value
		*stackPointer += 1;
	    stack[*stackPointer] = value;
	}
	return;
}

void pop(node* stack[], int max, int *stackPointer)
{
	if(*stackPointer == -1) // checking if stack is empty
	{
		return;
	}
	stack[*stackPointer] = NULL; // making current element null and decrementing pointer
	*stackPointer -= 1;
}

int isEmpty(node* stack[], int max, int stackPointer)
{
	if(stackPointer == -1) // checking if stack is empty
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(node* stack[], int max, int stackPointer)
{
	if(stackPointer == max-1) // cecking if stack is full
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

node* top(node* stack[], int max, int stackPointer)
{
	return stack[stackPointer]; // returning top node of the stack
}
