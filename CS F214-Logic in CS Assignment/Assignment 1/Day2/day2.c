#include<stdio.h>
#include<string.h>
#include "day1.h"
#include "day2.h"

void infixToPostfix(char infix_exp[])
{
	int max = strlen(infix_exp);
	char stack[max+1];  //Create stack
	int stackPointer = -1;  //Index of stack top
	for(int i = 0; i < max; i++)
	{
		switch(infix_exp[i])
		{
			case '(': {
                           push(stack, max, &stackPointer, infix_exp[i]);
                           break;
			          }
			case '~':
			case 'V':
			case '>':
			case '^': {
                           push(stack, max, &stackPointer, infix_exp[i]);
                           break;
			          }
			case ')': {
				           while(top(stack, max, stackPointer) != '(')
				           {
				           	    printf("%c", top(stack, max, stackPointer));
				           	    pop(stack, max, &stackPointer);
				           }
				           pop(stack, max, &stackPointer);  //Pop left bracket from stack                         
                           break;
			          }
			default:  {
                           printf("%c", infix_exp[i]);
                           break;
			          }
		}
	}
	while(!isEmpty(stack, max, stackPointer))
	{
		//printf("%c", top(stack, max, stackPointer));
		pop(stack, max, &stackPointer);
	}
	printf("\n");
}
