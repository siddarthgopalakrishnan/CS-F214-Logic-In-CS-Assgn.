/*
  Group ID - A4
  Siddarth Gopalakrishnan - 2017B3A71379H
  Pranav Grandhi - 2017B2A71604H
  Rahul Shevade - 2017B3A70878H
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"
#include "parse_tree.h"
#include "day2.h"
#include "day3.h"

node *distr(node *n1, node *n2)
{
	switch(n1->ch)
	{
		case '^':{ // if n1 is of the form n11^n12, return (distr(n11, n2)^distr(n12, n2))
			node *left = distr(n1->left, n2);
			node *right = distr(n1->right, n2);
			node *root = (node *)malloc(sizeof(node));
			root->ch = '^';
			root->left = left;
			root->right = right;
			return root;
			break;
		}
		default:{ // in other case, return (n1 V n2)
			node *root = (node *)malloc(sizeof(node));
			root->ch = 'V';
			root->left = n1;
			root->right = n2;
			return root;
			break;
		}
	}
	switch(n2->ch)
	{
		case '^':{ // if n2 is of the form n21^n22, return (distr(n1, n21)^distr(n1, n22))
			node *left = distr(n1, n2->left);
			node *right = distr(n1, n2->right);
			node *root = (node *)malloc(sizeof(node));
			root->ch = '^';
			root->left = left;
			root->right = right;
			return root;
			break;
		}
		default:{ // in other case, return (n1 V n2)
			node *root = (node *)malloc(sizeof(node));
			root->ch = 'V';
			root->left = n1;
			root->right = n2;
			return root;
			break;
		}
	}
}

node *cnf(node *root)
{
	if(root == NULL)
		return NULL; // won't be used, but saves a stack frame
	else
	{
		node *left = NULL;
		node *right = NULL;
		switch(root->ch)
		{
			case 'V':{ // in case of OR, recurse left, then right then pass to distr
				left = cnf(root->left);
				right = cnf(root->right);
				root = distr(left, right);
				break;
			}
			case '^':{ // in case of AND, recurse left, then right, then assign children to root
				left = cnf(root->left);
				right = cnf(root->right);
				root->left = left;
				root->right = right;
				break;
			}
			default:{
				break;
			}
		}
	}
	return root; // returning the root
}