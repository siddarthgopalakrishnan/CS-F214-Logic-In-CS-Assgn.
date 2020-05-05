/*
	Group ID - A4
	Siddarth Gopalakrishnan - 2017B3A71379H
	Pranav Grandhi - 2017B2A71604H
	Rahul Shevade - 2017B3A70878H
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"
#include "parse_tree.h"
#include "day2.h"

node *nnf(node *root)
{
	if(root == NULL)
		return NULL; // won't be used but saves a stack frame
	else
	{
		node *left;
		node *right;
		switch(root->ch)
		{
			case 'V':
			case '^':{ // in case of p^q or pVq, return nnf(p)^nnf(q) or nnf(p)Vnnf(q) respectively
						left = nnf(root->left);
						right = nnf(root->right);
						break;
					 }
			case '~':{ // if node is negation, check it's next node
						if(root->right->ch == '~')
						{ // if that is also negation, cancel the double negation and return
							node *temp = (node *)malloc(sizeof(node));
							temp->right = root->right->right->right;
							temp->left = root->right->right->left;
							temp->ch = root->right->right->ch;
							root = temp; // cancel double negation
							left = nnf(root->left); // recurse through left
							right = nnf(root->right); // recurse through right
						}
						else if(root->right->ch == 'V')
						{ // if next node is OR operator
							node *lefttemp = (node *)malloc(sizeof(node));
							node *righttemp = (node *)malloc(sizeof(node));
							//Apply DeMorgan's law to convert (~(pVq)) to ((~p)^(~q))
							lefttemp->right = root->right->left;
							lefttemp->left = NULL;
							righttemp->right = root->right->right;
							righttemp->left = NULL;
							righttemp->ch = '~';
							lefttemp->ch = '~';
							root->right->ch = '^'; // convert 'V' to '^'
							root->right->left = lefttemp;
							root->right->right = righttemp;
							root = root->right;
							left = nnf(root->left); // recurse left
							right = nnf(root->right); // recurse right
						}
						else if(root->right->ch == '^')
						{ // if next node is AND operator
							node *lefttemp = (node *)malloc(sizeof(node));
							node *righttemp = (node *)malloc(sizeof(node));
							//Apply DeMorgan's law to convert (~(p^q)) to ((~p)V(~q))
							lefttemp->right = root->right->left;
							lefttemp->left = NULL;
							righttemp->right = root->right->right;
							righttemp->left = NULL;
							righttemp->ch = '~';
							lefttemp->ch = '~';
							root->right->ch = 'V'; // convert '^' to 'V'
							root->right->left = lefttemp;
							root->right->right = righttemp;
							root = root->right;
							left = nnf(root->left); // recurse left
							right = nnf(root->right); // recurse right
						}
						else
						{ // if p is an atom, return it
							left = root->left;
							right = root->right;
						}
						break;
					 }
			 default:{ // if p is an atom, return it
						left = root->left;
						right = root->right;
						break;
					 }
		}
		root->right = right; // updating children
		root->left = left;

		return root;
	}
}