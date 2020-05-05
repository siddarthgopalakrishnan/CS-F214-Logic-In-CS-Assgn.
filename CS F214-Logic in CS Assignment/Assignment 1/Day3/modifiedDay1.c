#include<stdio.h>
#include "modifiedDay1.h"

void push(node* stack[], int max, int *stackPointer, node* value)
{
	if(*stackPointer == max-1)
	{
	    return;
	}
	else
	{
		*stackPointer += 1;
	    stack[*stackPointer] = value;
	}
	return;
}

void pop(node* stack[], int max, int *stackPointer)
{
	if(*stackPointer == -1)
	{
		return;
	}
	stack[*stackPointer] = NULL;
	*stackPointer -= 1;
}

int isEmpty(node* stack[], int max, int stackPointer)
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

int isFull(node* stack[], int max, int stackPointer)
{
	if(stackPointer == max-1)
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
	return stack[stackPointer];
}

void print(char stack[], int max, int stackPointer)
{
	for(int i = stackPointer; i >= 0; i--)
	{
		printf("%c->", stack[i]);
	}
}