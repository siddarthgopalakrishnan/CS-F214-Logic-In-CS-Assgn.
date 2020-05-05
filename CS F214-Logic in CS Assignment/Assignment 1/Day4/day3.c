#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modifiedDay1.h"
#include "day3.h"

node* parseTree(char post_exp[]) // parse tree implementation
{
    int max = strlen(post_exp);
    node* stack[max+1];
    int stackPointer = -1;
    for(int i = 0; i < max; i++)
    {	
    	node *value = (node *)malloc(sizeof(node));
        switch(post_exp[i])
        {
            case '>':
            case 'V':
            case '^': { // in case of operators get left and right node and push value
                          node* rightnode = top(stack, max, stackPointer);
                          pop(stack, max, &stackPointer);
                          node* leftnode = top(stack, max, stackPointer);
                          pop(stack, max, &stackPointer);
                          value->ch = post_exp[i];
                          value->left = leftnode;
                          value->right = rightnode;
                          push(stack, max, &stackPointer, value);
                          break; 
                      }
            case '~': { // special case for negation as only one sub tree
                          node* rightnode = top(stack, max, stackPointer);
                          pop(stack, max, &stackPointer);
                          value->ch = post_exp[i];
                          value->left = NULL;
                          value->right = rightnode;
                          push(stack, max, &stackPointer, value);
                          break;
                      } 
            default:  { // rest of the cases handled by default
            			  
                          value->ch = post_exp[i];
                          value->left = NULL;
                          value->right = NULL;
                          push(stack, max, &stackPointer, value);
						  break;
					  }
		}
	}
	return top(stack, max, stackPointer); // returning top of the stack
}

void inorder(node *root) // inorder traversal
{
    if(root == NULL)
        return;
    switch(root->ch) 
    {
        case '~':
        case 'V':
        case '^':
        case '>': { // open bracket before traversing left subtree
                      printf("(");
                      break;
                  }
        default:  {
                      break;
                  }
    }
    inorder(root->left);
    printf("%c", root->ch); // printing the root character
    inorder(root->right);
    switch(root->ch) 
    {
        case '~':
        case 'V':
        case '^':
        case '>': { // close bracket after traversing right subtree
                      printf(")");
                      break;
                  }
        default:  {
                      break;
                  }
    }
}
