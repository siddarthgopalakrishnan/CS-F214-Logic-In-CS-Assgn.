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

node* parseTree(char post_exp[])
{
    int max = strlen(post_exp);
    int stackPointer = -1;
    node* stack[max+1];
    for(int i = 0; i < max; i++)
    {
        switch(post_exp[i])
        {
            case 'V':
            case '^':
            case '>': {
                          node* right_child = top(stack, max, stackPointer);
                          pop(stack, max, &stackPointer);
                          node* left_child = top(stack, max, stackPointer);
                          pop(stack, max, &stackPointer);
                          node *value = (node *)malloc(sizeof(node));
                          value->ch = post_exp[i];
                          value->left = left_child;
                          value->right = right_child;
                          push(stack, max, &stackPointer, value);
                          break; 
                      }
            case '~': {
                          node* right_child = top(stack, max, stackPointer);
                          pop(stack, max, &stackPointer);
                          node *value = (node *)malloc(sizeof(node));
                          value->ch = post_exp[i];
                          value->left = NULL;
                          value->right = right_child;
                          push(stack, max, &stackPointer, value);
                          break;
                      } //Special case for negation - create right child only
            default:  {
                          node* value = (node *)malloc(sizeof(node));
                          value->ch = post_exp[i];
                          value->left = NULL;
                          value->right = NULL;
                          push(stack, max, &stackPointer, value);
                          break;
                      } //Takes care of operands
        }
    }
    
    return top(stack, max, stackPointer); //Return root node
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    switch(root->ch) //If root node is operator, open a bracket
    {
        case '~':
        case 'V':
        case '^':
        case '>': {
                      printf("(");
                      break;
                  }
        default:  {
                      break;
                  }
    }
    inorder(root->left);
    printf("%c", root->ch);
    inorder(root->right);
    switch(root->ch) //Once operands have been printed and functions have recursed back to operator node, close bracket
    {                
        case '~':
        case 'V':
        case '^':
        case '>': {
                      printf(")");
                      break;
                  }
        default:  {
                      break;
                  }
    }
}
