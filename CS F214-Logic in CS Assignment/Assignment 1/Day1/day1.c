#include<stdio.h>
#include "day1.h"

void push(char stack[], int max, int *stackPointer, char value)
{
	if(*stackPointer == max-1)
	{
	    printf("Error : Stack overflow : Element will not be pushed\n");
	    return;
	}
	else
	{
	    *stackPointer += 1;
	    stack[*stackPointer] = value;
	}
	return;
}

void pop(char stack[], int max, int *stackPointer)
{
	if(*stackPointer == -1)
	{
	    printf("Error : Stack underflow : No element to pop\n");
	    return;
	}
	stack[*stackPointer] = '\0';
	*stackPointer -= 1;
}

int isEmpty(char stack[], int max, int stackPointer)
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

int isFull(char stack[], int max, int stackPointer)
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

char top(char stack[], int max, int stackPointer)
{
	if(isEmpty(stack, max, stackPointer))
	{
		printf("No elements in stack");
		return '\0';
	}
	else
	{
        return stack[stackPointer];
    }
}

void print(char stack[], int max, int stackPointer)
{
	for(int i = stackPointer; i >= 0; i--)
	{
		printf("%c->", stack[i]);
	}
}