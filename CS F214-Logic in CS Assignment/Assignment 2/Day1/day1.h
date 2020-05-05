// contains function to make any propositional logic formula implication-free. 
// author : Rashi Jain, 30/10/19

// Removes all implications from the parse tree.   
// root : Pointer to root of the parse tree(dataype : node *)
// node dataype is defined as
// typedef struct node
// {
//		char ch;  	
//   	struct node *left;
//		struct node *right;
// }node;
// return : root of the parse tree not containing any implication (dataype : node *)
/*
	Group ID - A4
	Siddarth Gopalakrishnan - 2017B3A71379H
	Pranav Grandhi - 2017B2A71604H
	Rahul Shevade - 2017B3A70878H
*/

node *impl_free(node *root);