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
#include "day1.h"

node *impl_free(node *root)
{
	if(root == NULL)
		return NULL; // won't be used, but saves a stack frame
	
	switch(root->ch)
	{
		case '~':{
					impl_free(root->right); // recurse through right sub-tree in case of negation
					break;
				 }
				 
		case 'V':
		case '^':{ // in case of OR or AND, recurse through left then right sub-tree
					impl_free(root->left);
					impl_free(root->right);
					break;
				 }
		
		case '>':{ // in case of implication, convert (p>q) to ((~p)Vq) by DeMorgan's theorem
					node *temp = (node *)malloc(sizeof(node)); // creating the left node as ~p
					temp->right = root->left; // right sub-tree is p
					temp->left = NULL; // left sub-tree is NULL
					temp->ch = '~'; // left sub-tree node root character
					root->left = temp; // putting ~p before 'V'
					root->ch = 'V'; // character instead of implication
					impl_free(root->left);
					impl_free(root->right); // right sub-tree remains q
					break;
				 }
				 
		default: break;
	}
	return root; // returning the root
}
