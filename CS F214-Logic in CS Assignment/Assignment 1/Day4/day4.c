#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modifiedDay1.h"
#include "day3.h"
#include "day4.h"

int evalParseTree(node *root, char var[], int value[], int n)
{
	if(root == NULL) return -1;
	int leftside = evalParseTree(root->left, var, value, n);
	// evaluate right sub tree in all cases and return appropriate value
	if(root->ch == 'V') // returning logical OR
	{
		int rightside = evalParseTree(root->right, var, value, n);
		return (leftside || rightside);
	}
	else if(root->ch == '>') // returning implication
	{
		int rightside = evalParseTree(root->right, var, value, n);
		if((leftside == 1) && (rightside == 0))
			return 0; // implication is false only in one case
		else return 1;
	}
	else if(root->ch == '^') // returning logical AND
	{
		int rightside = evalParseTree(root->right, var, value, n);
		return (leftside && rightside);
	}
	else if(root->ch == '~') // returning negation
	{
		int rightside = evalParseTree(root->right, var, value, n);
		return (!(rightside)); // expression will be to right of operator in parse tree
	}
	else
	{
		for(int i = 0; i<n; i++)
		{
			if(root->ch == var[i])
			{
				return value[i]; // return value if oprand is encountered
			}
		}
	}
	return leftside; // return final value
}