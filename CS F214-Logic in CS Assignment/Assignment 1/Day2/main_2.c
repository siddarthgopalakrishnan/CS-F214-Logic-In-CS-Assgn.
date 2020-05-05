#include<stdio.h>
#include "day2.h"

int main()
{
	char infix_exp[100];
	//scan the infix expression 
	scanf("%s", infix_exp);
	infixToPostfix(infix_exp); //The function will print the postFix expression. 
	return 0;
}